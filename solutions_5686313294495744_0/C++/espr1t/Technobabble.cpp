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
const int MASK = (1 << 16);

int n;
string a[MAX][2];
int dyn[MASK];

int recurse(int mask) {
    if (mask == (1 << n) - 1)
        return 0;
    if (dyn[mask] != -1)
        return dyn[mask];
    
    int ans = 0;
    for (int i = 0; i < n; i++) if (!(mask & (1 << i))) {
        // Try as an original
        ans = max(ans, recurse(mask | (1 << i)));

        // Try as a fake
        int hasWords = 0;
        for (int c = 0; c < n; c++) if (mask & (1 << c)) {
            if (a[i][0] == a[c][0]) hasWords |= (1 << 0);
            if (a[i][1] == a[c][1]) hasWords |= (1 << 1);
        }
        if (hasWords == 3) {
            ans = max(ans, recurse(mask | (1 << i)) + 1);
        }
    }
    return dyn[mask] = ans;
}

void solveTest() {
    fscanf(in, "%d", &n);
    for (int i = 0; i < n; i++) {
        char word1[32], word2[32];
        fscanf(in, "%s %s", word1, word2);
        a[i][0] = word1, a[i][1] = word2;
    }
    memset(dyn, -1, sizeof(dyn));
    fprintf(out, "%d\n", recurse(0));
}

int main(void) {
	unsigned sTime = clock();
	in = fopen("Technobabble.in", "rt");
	out = fopen("Technobabble.out", "wt");
	
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
