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
const int INF = 1000000001;
const double EPS = 0.000000001;

struct Hiker {
    double origin, speed;
    bool operator < (const Hiker& r) const {
        return speed < r.speed;
    }
};

int rand30() {
    return (((rand() & (((1 << 10) - 1) << 3)) >> 3) << 0) |
           (((rand() & (((1 << 10) - 1) << 3)) >> 3) << 10) |
           (((rand() & (((1 << 10) - 1) << 3)) >> 3) << 20) ;
}

int n;
Hiker a[MAX];

/*
int eval(double speed) {
    int ret = 0;
    double t = 360.0 / speed;
    for (int i = 0; i < n; i++) {
        
        if (speed < a[i].speed) {
            
        }
    }
    
    return ret;
}

void solve() {
    sort(a, a + n);

    vector <double> speeds;
    for (int i = 0; i < n; i++) {
        speeds.push_back(a[i].speed);
        speeds.push_back(a[i].speed + EPS);
        speeds.push_back(a[i].speed - EPS);
    }
    for (int iter = 0; iter < 100000; iter++) {
        speeds.push_back(360.0 / (double)(rand30() % 2000000 + 1));
        speeds.push_back(360.0 / (double)(rand30() % 360 + 1));
    }
    
    int ans = INF;
    for (int i = 0; i < (int)speeds.size(); i++) {
        ans = min(ans, eval(speeds[i]));
    }
    return ans;
}
*/

void solveForTwo() {
    if (n <= 1)
        fprintf(out, "0\n");
    else {
        int ans = 0;
        for (int i = 0; i < 2; i++) {
            double t = (360.0 - a[i].origin) / a[i].speed;
            double d = t * a[i ^ 1].speed;
            if (d > 360.0 + (360.0 - a[i ^ 1].origin) - EPS)
                ans = 1;
        }
        fprintf(out, "%d\n", ans);
    }
}

void readInput() {
    int g;
    fscanf(in, "%d", &g);
    n = 0;
    for (int i = 0; i < g; i++) {
        int origin, cnt, speed;
        fscanf(in, "%d %d %d", &origin, &cnt, &speed);
        for (int c = 0; c < cnt; c++) {
            a[n].origin = origin;
            a[n].speed = 360.0 / (speed + c);
            n++;
        }
    }
}

void solveTest() {
    readInput();
    solveForTwo();
}

int main(void) {
	unsigned sTime = clock();
	in = fopen("HikingDeer.in", "rt");
	out = fopen("HikingDeer.out", "wt");
	
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
