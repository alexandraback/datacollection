// Generic Codejam/Facejam input loader, problem dispatcher, and verifier.  Actual problem solution in the other file.
// Using libUtil from libGlov (Game Library of Victory) available at http://bigscreensmallgames.com/libGlov
// Some solutions may use BigInteger from http://mattmccutchen.net/bigint/
// Built with MS Visual Studio 2010
#include "utilUtils.h"
#include "utilFile.h"
#include "utilString.h"
#include <assert.h>
#include "utilArray.h"
#include "utilRand.h"
#include <process.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <conio.h>
#include <Windows.h>

// Launches each specific test case into its own process, combined with a distributed build
// system, this can improve the running time enormously, and on a single computer can at least
// get a speedup equal to the number of cores.
//#define DO_DISTRIBUTED

#pragma comment(lib, "winmm.lib")

extern char *doA(char **&toks);
extern char *doB(char **&toks);
extern char *doC(char **&toks);
extern char *doD(char **&toks);
extern char *doE(char **&toks);

int argc;
char **argv;
U32 starttime;

typedef char *(*Solver)(char **&toks);

void myfprintf(FILE *f, const char *fmt, ...)
{
	va_list va;
	char buf[32768];

	va_start(va, fmt);
	Vsprintf(buf, fmt, va);
	va_end(va);

	printf("%s", buf);
	fprintf(f, "%s", buf);
}

void realfprintf(FILE *f, const char *fmt, ...)
{
	va_list va;
	char buf[32768];

	va_start(va, fmt);
	Vsprintf(buf, fmt, va);
	va_end(va);

	fprintf(f, "%s", buf);
}

#define fprintf myfprintf

void doProblem(char *filename, Solver s, char *delims, char *delims_noteaten)
{
	char outname[MAX_PATH];
	sprintf(outname, "%s.out", filename);
	FILE *fout = fopen(outname, "w");
	char *data = fload(filename, "rb", NULL);
	char **toks=NULL;
	char **freeMe=NULL;;
	if (delims_noteaten)
		tokenizeStringAlloc2(data, delims, delims_noteaten, &toks, &freeMe);
	else
		tokenizeStringAlloc(data, delims, &toks);
	int N = atoi(toks[0]);
	char **curtoks = &toks[1];
	for (int i=0; i<N; i++) {
#ifdef DO_DISTRIBUTED
		fprintf(fout, "%s\n", s(curtoks));
#else
		fprintf(fout, "Case #%d: %s\n", i+1, s(curtoks)); // Google
		//fprintf(fout, "%s\n", s(curtoks)); // Facebook
#endif
	}
	assert(curtoks == &toks[arrayGetSize(&toks)]);
	fclose(fout);
	arrayDestroyEx(&freeMe, NULL);
}

void doProblemNonGeneric(char *filename, Solver s, char *delims)
{
	char outname[MAX_PATH];
	sprintf(outname, "%s.out", filename);
	FILE *fout = fopen(outname, "w");
	char *data = fload(filename, "rb", NULL);
	char **toks=NULL;
	tokenizeStringAlloc(data, delims, &toks);
	//int N = atoi(toks[0]);
	char **curtoks = &toks[0];
	fprintf(fout, "%s", s(curtoks));
	assert(curtoks == &toks[arrayGetSize(&toks)]);
	fclose(fout);
}


typedef struct ThreadState
{
	volatile long bGotArgs;
	char **toks0;
	char **toks;
	char *cmdline;
	char *file_out;
	char *result;
	volatile long bDone;
	U32 queueTime;
	U32 procStartTime;
	U32 procFinishTime;
	U32 finishTime;
	U32 dequeueTime;
} ThreadState;
_declspec(thread) ThreadState *my_ts;

void doneParsingArgs(char **&toks)
{
	if (!my_ts)
		return;
	my_ts->toks = toks;
	toks = NULL;
	MemoryBarrier();
	my_ts->bGotArgs = true;
	ExitThread(0);
}

Solver g_s;

void GetArgsThread(void *dummy)
{
	ThreadState *ts = (ThreadState*)dummy;
	my_ts = ts;
	char **toks = ts->toks;
	g_s(toks);
}

void RunProcThread(void *dummy)
{
	ThreadState *ts = (ThreadState*)dummy;
	ts->procStartTime = timeGetTime();
	system(ts->cmdline);
	ts->procFinishTime = timeGetTime();
	ts->result = fload(ts->file_out, "r", NULL);
	assert(ts->result);
	while (strEndsWith(ts->result, "\n") ||
			strEndsWith(ts->result, "\r"))
		ts->result[strlen(ts->result)-1] = '\0';
	free(ts->cmdline);
	ts->finishTime = timeGetTime();
	MemoryBarrier();
	ts->bDone = true;
}

void doProblemDistributed(char *filename, Solver s, char *delims, char *delims_noteaten)
{
	if (argc == 3 && strcmp(argv[1], "--subproc")==0)
	{
		doProblem(argv[2], s, " \n\r", NULL);
		return;
	}

	g_s = s;
	char outname[MAX_PATH];
	sprintf(outname, "%s.out", filename);
	FILE *fout = fopen(outname, "w");
	char *data = fload(filename, "rb", NULL);
	char **toks=NULL;
	char **freeMe=NULL;;
	if (delims_noteaten)
		tokenizeStringAlloc2(data, delims, delims_noteaten, &toks, &freeMe);
	else
		tokenizeStringAlloc(data, delims, &toks);
	int N = atoi(toks[0]);
	ThreadState *tss = new ThreadState[N];
	memset(tss, 0, sizeof(ThreadState)*N);
	char **curtoks = &toks[1];
	// dispatch to split args
	for (int i=0; i<N; i++) {
		tss[i].toks = curtoks;
		tss[i].toks0 = curtoks;
		_beginthread(GetArgsThread, 0, (void *)&tss[i]);
		while(!tss[i].bGotArgs)
			Sleep(1);
		curtoks = tss[i].toks;
	}
	printf("[%1.2f] Done parsing args\n", (timeGetTime() - starttime) / 1000.f);
	assert(curtoks == &toks[arrayGetSize(&toks)]);
	// run separate processes to solve each problem
	for (int i=0; i<N; i++)
	{
		char temp_filename[MAX_PATH];
		sprintf(temp_filename, "F:/temp/codejam/%d.txt", i);
		FILE *ftemp = fopen(temp_filename, "w");
		assert(ftemp);
		realfprintf(ftemp, "1\n");
		for (char **t=tss[i].toks0; t!= tss[i].toks; t++)
		{
			realfprintf(ftemp, "%s ", *t);
		}
		fclose(ftemp);
		char cmdline[MAX_PATH*2];
		char outfile[MAX_PATH];
		strcpy(outfile, temp_filename);
		strcat(outfile, ".cout");
		sprintf(cmdline, "%s --subproc %s > %s", GetCommandLine(), temp_filename, outfile);
		tss[i].cmdline = strdup(cmdline);
		strcat(temp_filename, ".out");
		tss[i].file_out = strdup(temp_filename);
		unlink(tss[i].file_out); // make sure it doesn't exist before running

		// Ready to start another thread, wait for some to finish
#define NUM_THREADS 8
		do 
		{
			int numRunning=0;
			for (int j=0; j<i; j++)
			{
				if (!tss[j].bDone)
					numRunning++;
				else if (!tss[j].dequeueTime)
					tss[j].dequeueTime = timeGetTime();
			}
			if (numRunning < NUM_THREADS)
				break;
			printf("\r\r%d/%d complete, %d running.   ", i - numRunning, N, numRunning);
			Sleep(15);
		} while (true);
		tss[i].queueTime = timeGetTime();
		_beginthread(RunProcThread, 0, (void *)&tss[i]);
	}
	// Wait
	do 
	{
		int numRunning=0;
		for (int j=0; j<N; j++)
		{
			if (!tss[j].bDone)
				numRunning++;
			else if (!tss[j].dequeueTime)
				tss[j].dequeueTime = timeGetTime();
		}
		if (numRunning == 0)
			break;
		printf("\r\r%d/%d complete, %d running.   ", N - numRunning, N, numRunning);
		Sleep(15);
	} while (true);
	printf("\r\r%d/%d complete.                                                        \n", N, N);
	if (0)
	for (int i=0; i<N; i++) {
		printf("%d: [%1.3fs to start] [%1.3fs to exec] [%1.3fs to finish] [%1.3fs to dequeue]\n",
			i,
			(tss[i].procStartTime - tss[i].queueTime) / 1000.f,
			(tss[i].procFinishTime - tss[i].procStartTime) / 1000.f,
			(tss[i].finishTime - tss[i].procFinishTime) / 1000.f,
			(tss[i].dequeueTime - tss[i].finishTime) / 1000.f);
	}

	// gather
	for (int i=0; i<N; i++) {
		fprintf(fout, "Case #%d: %s\n", i+1, tss[i].result); // Google
		//fprintf(fout, "%s\n", tss[i].result); // Facebook
		free(tss[i].result);
	}
	fclose(fout);
	arrayDestroyEx(&freeMe, NULL);
	delete []tss;
}


void gentest()
{
	FILE *f = fopen("B-large-test.in", "wb");
#undef fprintf
	for (int i=0; i<20; i++)
	{
		for (int j=0; j<60; j++)
		{
			fprintf(f, "%c", randInt(2)?'a':'b');
		}
		fprintf(f, "\n");
	}
	fclose(f);
}

#ifndef DO_DISTRIBUTED
#define doProblemDistributed doProblem
#endif

int main(int _argc, char **_argv)
{
	argc = _argc;
	argv = _argv;
	assert(argc == 1 || argc == 3 || argc==4);
	starttime = timeGetTime();

	// if (argc==4)
	// 	doProblem("B-large.in", doB, " \t\n\r", NULL);
	// else
	// 	doProblemDistributed("B-large.in", doB, " \t\n\r", NULL);

	//gentest();
	//doProblem("A-large.in", doA, " \t\n\r", NULL);
	doProblem("A-small.in", doA, " \t\n\r", NULL);
	//doProblem("A-small.in", doA, "\t\n\r", NULL);
	//doProblemNonGeneric("A-large.in", doA, " \t\n\r", NULL);
	//doProblem("A-large.in", doA, " \t\n\r", NULL);
	//doProblem("B-small-attempt0.in", doB, " \t\n\r", NULL);
	//doProblem("B-large-test.in", doB, " \t\n\r", NULL);
	//doProblem("B-large.in", doB, " \t\n\r", NULL);
	//doProblem("C-small.in", doC, " \t\n\r", NULL);
	//doProblem("C-small.in", doC, " \t\n\r", NULL);
	//doProblem("C-small-attempt0.in", doC, " \t\n\r", NULL);
	//doProblem("C-large.in", doC, " \t\n\r", NULL);
	//doProblem("D-small.in", doD, " \t\n\r", NULL);
	//doProblem("D-small-attempt2.in", doD, " \t\n\r", NULL);
	//doProblem("D-large-test.in", doD, " \t\n\r", NULL);
	printf("Finished in %1.2fs.\n", (timeGetTime() - starttime) / 1000.f);
	if (argc==1)
		_getch();
	return 0;
}
