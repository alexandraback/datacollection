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
#include <queue>

using namespace std;
FILE* in; FILE* out;

const int MAX = 1048576;

int dist[MAX];

int revNum(int num) {
    int ret = 0;
    while (num) {
        ret = ret * 10 + num % 10;
        num /= 10;
    }
    return ret;
}

void bfs() {
    queue <int> q;
    memset(dist, 63, sizeof(dist));
    q.push(1); dist[1] = 1;
    while (!q.empty()) {
        int num = q.front(); q.pop();
        if (num + 1 < MAX && dist[num] + 1 < dist[num + 1]) {
            dist[num + 1] = dist[num] + 1;
            q.push(num + 1);
        }
        int rev = revNum(num);
        if (rev > 0 && rev < MAX && dist[num] + 1 < dist[rev]) {
            dist[rev] = dist[num] + 1;
            q.push(rev);
        }
    }
}

void solveTest() {
    int n;
    fscanf(in, "%d", &n);
    fprintf(out, "%d\n", dist[n]);
}

int main(void) {
	unsigned sTime = clock();
	in = fopen("CounterCulture.in", "rt");
	out = fopen("CounterCulture.out", "wt");
	
	bfs();
	
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
