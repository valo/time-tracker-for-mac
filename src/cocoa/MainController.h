/* MainController */

#import <Cocoa/Cocoa.h>
#import "TTDocumentV1.h"
#import "TProject.h"
#import "TTask.h"
#import "TWorkPeriod.h"
#import "TTTimeProvider.h"
#import "TTTimer.h"
#import "TTDocumentLoader.h"
#import "TTStatusItemController.h"

@interface MainController : NSObject <TTResources>
{
	NSUserDefaults *defaults;
	
	NSImage *playToolImage;
	NSImage *stopToolImage;
	NSImage *addTaskToolImage;
	NSImage *addProjectToolImage;
  
  
  IBOutlet NSTableView *tvProjects;
  IBOutlet NSTableView *tvTasks;
  IBOutlet NSTableView *tvWorkPeriods;
  IBOutlet NSWindow *mainWindow;
  IBOutlet NSPanel *panelEditWorkPeriod;
  IBOutlet NSPanel *panelIdleNotification;
  
	IBOutlet NSDatePicker *dtpEditWorkPeriodStartTime;
	IBOutlet NSDatePicker *dtpEditWorkPeriodEndTime;
	
	IBOutlet NSMenuItem *startMenuItem;
  IBOutlet NSMenu *statusItemMenu;
  
  TTStatusItemController *statusItemController;
	NSToolbarItem *startstopToolbarItem;
	
	TTDocumentV1 *document;
  id documentController;
  TTDocumentLoader *documentLoader;
  TTTimeProvider *timeProvider;
  TTTimer *timer;
	NSMutableDictionary *_projects_lastTask;
	TProject *_selProject;
	TTask *_selTask;
	TWorkPeriod *_curWorkPeriod;
	TProject *_curProject;
	TTask *_curTask;
	
	int timeSinceSave;
	
	NSDate *filterStartTime;
	NSDate *filterEndTime;
}

- (id) initWithDocumentLoader:(TTDocumentLoader *)aDocumentLoader;

// actions
- (IBAction)clickedAddProject:(id)sender;
- (IBAction)clickedAddTask:(id)sender;
- (IBAction)clickedStartStopTimer:(id)sender;
- (IBAction)clickedDelete:(id)sender;
- (IBAction)clickedChangeWorkPeriod:(id)sender;
- (IBAction)clickedCountIdleTimeYes:(id)sender;
- (IBAction)clickedCountIdleTimeNo:(id)sender;
- (IBAction)actionExport:(id)sender;

- (IBAction)filterToAll:(id)sender;
- (IBAction)filterToToday:(id)sender;
- (IBAction)filterToYesterday:(id)sender;
- (IBAction)filterToThisWeek:(id)sender;
- (IBAction)filterToLastWeek:(id)sender;
- (IBAction)filterToWeekBeforeLast:(id)sender;
- (IBAction)filterToThisMonth:(id)sender;
- (IBAction)filterToLastMonth:(id)sender;

- (void)stopTimer;
- (void)startTimer;
- (void)saveData;
- (void)createProject;
- (void)createTask;

- (void) updateStartStopState;

- (BOOL) validateUserInterfaceItem:(id)anItem;

// Dependencies
- (void)setMainWindow:(NSWindow *)w;
- (NSWindow *)mainWindow;
- (void)setProjectsTableView:(NSTableView *)tv;
- (void)setTasksTableView:(NSTableView *)tv;
- (void)setWorkPeriodsTableView:(NSTableView *)tv;
- (TTDocumentV1 *)document;
- (void)setDocument:(TTDocumentV1 *)aDocument;
- (id)documentController;
- (void)setDocumentController:(id)aDocumentController;
- (void)setTimeProvider:(TTTimeProvider *)tp;
- (TProject *)selectedProject;
- (void)setSelectedProject:(TProject *)aProject;
- (void)setSelectedTask:(TTask *)aTask;
- (TTTimer *)timer;
- (void)setTimer:(TTTimer *)aTimer;
- (TProject *)activeProject;
- (TTask *)activeTask;
- (TWorkPeriod *)activeWorkPeriod;

- (void)clearFilter;
- (void)setFilterStartTime:(NSDate *)startTime endTime:(NSDate *)endTime;

// Data source methods
- (NSTimeInterval)totalTimeForProject:(TProject *)project;
- (NSTimeInterval)totalTimeForTask:(TTask *)task;
- (int)countOfWorkPeriodsForTask:(TTask *)task;

@end
