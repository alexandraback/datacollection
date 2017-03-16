/* Date: 15 April 2016
 * Comments: 
 */

#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
#define err(...) fprintf(stderr,__VA_ARGS__)


void doCase(int case_number) {
	bool counter[2501] = {};
	int N; cin >> N;
	for (int i=0; i<2*N-1; i++) for (int j=0; j<N; j++) {
		int h; cin >> h;
		counter[h] ^= true;
	}
	printf("Case #%d:",case_number);
	for (int h=1; h<=2500; h++) if (counter[h]) printf(" %d",h);
	printf("\n");
}

/* PROBLEM NON-SPECIFIC TEMPLATE CODE FOLLOWS.
 * This template version created 3 April 2016.
 * The code below reads the input, and prints the output either to stdout or to a file.
 * If output goes to a file, it also writes a log file for later reference.
 * Notes:
 * 	- If no arguments are provided, the program reads from standard input and prints to standard output.
 * 	- The first argument specifies the input file name. If it is "x", the standard input is used.
 * 	- The second argument specifies the output file name. If it is "a", an unused filename is created.
 * 	- This code assumes that the first line of the input is the number of cases that follow.
 *	- If output is written to a file, then a corresponding "log" file is also created, to store some basic information and the source code used to create this output.
 */

ofstream logstream;

int main(int argc, char **argv) {
	if (argc>1 && argv[1][0]!= 'x') freopen(argv[1],"r",stdin);
	if (argc>2) {
		// Second argument tells filename for the output.
		// If the argument is "a" (for auto), one is created.
		char outfname[100];
		char logfname[100];
		if (argv[2][0] != 'a') {
			strcpy(outfname,argv[2]);
			sprintf(logfname,"%s.log",outfname);
		} else {
			int id = 0;
			// stem will remove ".in" from the input file name, if present.
			char stem[100];
			strcpy(stem,argv[1]);
			if (strcmp(stem+(strlen(stem)-3),".in") == 0) stem[strlen(stem)-3] = 0;
			char outfname[100];
			while (true) {
				sprintf(outfname,"%s.out%d",stem,id);
				sprintf(logfname,"%s.log%d",stem,id);
				ifstream in(outfname);
				if (!in) break;
				id++;
			}
			freopen(outfname,"w",stdout);
			logstream.open(logfname);
			err("Writing output to %s.\n",outfname);

			// Generate a log for this execution.
			time_t rawtime = time(NULL);
			tm *timeinfo = localtime(&rawtime);
			logstream << asctime(timeinfo);
		}
	}
	int T; cin >> T;
	err("There are %d cases.\n",T);
	logstream << "There are " << T << " cases." << endl;
	
	clock_t prev,cur = clock();
	clock_t start = cur;
	for (int t=1; t<=T; t++) {
		doCase(t);
		prev = cur;
		cur = clock();
		int time_elapsed = (int) ( 1000*(cur - prev) / ((int)CLOCKS_PER_SEC));
		err("_%d(%d)_",t, time_elapsed);
		logstream << "Case #" << t << " completed in " << time_elapsed << "ms" << endl;

	}
	int total_time = (int) ( 1000*(cur-start) / ((int)CLOCKS_PER_SEC) );
	err("\nFinished %d cases in %d milliseconds.\n",T,total_time);

	// Print the source code (minus the template) to the log for reference.
	if (logstream.good()) {
		logstream << "Total time: " << total_time << endl;
		logstream << "\nCurrent source code for " << __FILE__ << ":" << endl;
		ifstream src;
		src.open(__FILE__);
		while (true) {
			string line; getline(src,line);
			if (line == "/* PROBLEM NON-SPECIFIC TEMPLATE CODE FOLLOWS.") break;
			logstream << line << endl;
		}
		logstream << "(Truncating at the beginning of the template code)" << endl;
	}
}
