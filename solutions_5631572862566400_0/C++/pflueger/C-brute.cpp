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

const int MAX_N = 1000;
int N;
int F[MAX_N+1];

bool used[MAX_N+1];
int order[MAX_N+1];
int dfs(int next, int loc) {
	if (used[next]) {
		//err("seen %d already. Skipping...\n",next);
		return -1;
	}
	used[next] = true;
	order[loc] = next;
	//err("trying kid %d in location %d...\n",next,loc);
	int res = -1;
	if (loc>0 && (F[next] == order[loc-1] || F[next] == order[0])) {
		res = loc+1; //Can complete the circle here
		//err("Found option of length %d\n",res);
	}
	if (loc>0 && (F[next] == order[loc-1])) { // Any kid can come next
		//err("any kid could come next...\n");
		for (int k=1; k<=N; k++) res = max(res,dfs(k,loc+1));
	} else { //Only BFF could come next
		res = max(res,dfs(F[next],loc+1));
	}
	used[next] = false;
	//err("backtracking from %d in %d...\n",next,loc);
	return res;
}

void doCase(int case_number) {
	cin >> N;
	for (int k=1; k<=N; k++) cin >> F[k];
	for (int k=1; k<=N; k++) used[k] = false;
	int res = -1;
	for (int k=1; k<=N; k++) {
		int cand = dfs(k,0);
		res = max(cand,res);
	}
	printf("Case #%d: %d\n",case_number,res);
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
