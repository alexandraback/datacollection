#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>

using namespace std;
FILE* in; FILE* out;

const int MAX = 1024;


void solveTest() {
    int ms;
    char a[MAX];
    fscanf(in, "%d %s", &ms, a);
    int ans = 0;
    int covered = 0, level = 0;
    while (covered < ms) {
        if (level <= covered && level <= ms) {
            covered += a[level++] - '0';
        } else {
            ans++, covered++;
        }
    }
    fprintf(out, "%d\n", ans);
}

int main(void) {
	unsigned sTime = clock();
	in = fopen("StandingOvation.in", "rt");
	out = fopen("StandingOvation.out", "wt");
	
	int numTests;
	fscanf(in, "%d", &numTests);
	for (int test = 1; test <= numTests; test++) {
		fprintf(stderr, "Currently executing testcase %d...\n", test);
		fprintf(out, "Case #%d: ", test);
		solveTest();
	}
	
	fprintf(stderr, "Total execution time %.3lf seconds.\n",
        (double)(clock() - sTime) / (double)CLOCKS_PER_SEC);
	return 0;
}
