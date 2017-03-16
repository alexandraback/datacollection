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

int n;
int a[MAX];

int eval(int maxSize, int best) {
    int ans = maxSize;
    for (int i = 0; i < n; i++) {
        for (int tmp = a[i]; tmp > maxSize; tmp -= maxSize)
            ans++;
        if (ans > best)
            return ans;
    }
    return ans;
}

void solveTest() {
    fscanf(in, "%d", &n);
    for (int i = 0; i < n; i++)
        fscanf(in, "%d", &a[i]);
    
    int ans = 1000;
    for (int maxSize = 1; maxSize <= 1000; maxSize++) {
        ans = min(ans, eval(maxSize, ans));
    }
    fprintf(out, "%d\n", ans);
}

int main(void) {
	unsigned sTime = clock();
	in = fopen("InfiniteHouseOfPancakes.in", "rt");
	out = fopen("InfiniteHouseOfPancakes.out", "wt");
	
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
