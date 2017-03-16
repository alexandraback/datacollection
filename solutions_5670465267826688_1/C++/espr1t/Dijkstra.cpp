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

const int MAX = 10002;

char digits[8] = { '1', 'i', 'j', 'k', '-', 'I', 'J', 'K'};
int conv[128];
char rules[4][4][3] = {
    {{'1', '1', '1'}, {'1', 'i', 'i'}, {'1', 'j', 'j'}, {'1', 'k', 'k'}},
    {{'i', '1', 'i'}, {'i', 'i', '-'}, {'i', 'j', 'k'}, {'i', 'k', 'J'}},
    {{'j', '1', 'j'}, {'j', 'i', 'K'}, {'j', 'j', '-'}, {'j', 'k', 'i'}},
    {{'k', '1', 'k'}, {'k', 'i', 'j'}, {'k', 'j', 'I'}, {'k', 'k', '-'}}
};

int ma3x[8][8];

void init() {
    for (int i = 0; i < 8; i++)
        conv[(int)digits[i]] = i;

    for (int i = 0; i < 4; i++) {
        for (int c = 0; c < 4; c++) {
            ma3x[conv[(int)rules[i][c][0]]][conv[(int)rules[i][c][1]]] =
                conv[(int)rules[i][c][2]];
        }
        for (int c = 4; c < 8; c++) {
            ma3x[i][c] = (ma3x[i][c - 4] + 4) % 8;
        }
    }
    for (int i = 4; i < 8; i++) {
        for (int c = 0; c < 8; c++) {
            ma3x[i][c] = (ma3x[i - 4][c] + 4) % 8;
        }
    }
}

int fastPow(int what, long long pwr) {
    if (pwr == 1)
        return what;
    int split = fastPow(what, pwr / 2);
    int ret = 0;
    if (pwr % 2)
        ret = ma3x[ret][what];
    ret = ma3x[ret][split];
    ret = ma3x[ret][split];
    return ret;
}

long long n, m;
char a[MAX];
bool vis[MAX][8];

long long getLong() {
    char buff[32];
    fscanf(in, "%s", buff);
    long long ret = 0;
    for (int i = 0; i < (int)strlen(buff); i++)
        ret = ret * 10 + buff[i] - '0';
    return ret;
}

void solveTest() {
    init();
    n = getLong();
    m = getLong();
    fscanf(in, "%s", a);
    
    // Find an 'i'
    memset(vis, 0, sizeof(vis));
    int left = 0; long long leftAt = -1;
    for (long long i = 0; i < n * m; i++) {
        left = ma3x[left][conv[(int)a[i % n]]];
        if (left == 1) {
            leftAt = i;
            break;
        }
        if (vis[i % n][left])
            break;
        vis[i % n][left] = true;
    }
    if (leftAt == -1) {
        fprintf(out, "NO\n");
        return;
    }

    // Find a 'j'
    memset(vis, 0, sizeof(vis));
    int middle = 0; long long middleAt = -1;
    for (long long i = leftAt + 1; i < n * m; i++) {
        middle = ma3x[middle][conv[(int)a[i % n]]];
        if (middle == 2) {
            middleAt = i;
            break;
        }
        if (vis[i % n][middle])
            break;
        vis[i % n][middle] = true;
    }
    if (middleAt == -1) {
        fprintf(out, "NO\n");
        return;
    }
    
    // Check if the rest is 'k'
    int right = 0; long long rightAt = middleAt + 1;
    for (long long i = middleAt + 1; i < n * m; i++) {
        if (i % n == 0)
            break;
        right = ma3x[right][conv[(int)a[i % n]]];
        rightAt++;
    }
    long long rem = (n * m - rightAt) / n;
    if (rem > 0) {
        int what = 0;
        for (int i = 0; i < n; i++)
            what = ma3x[what][conv[(int)a[i]]];
        what = fastPow(what, rem);
        right = ma3x[right][what];
    }
    fprintf(out, "%s\n", right == 3 ? "YES" : "NO");
}

int main(void) {
	unsigned sTime = clock();
	in = fopen("Dijkstra.in", "rt");
	out = fopen("Dijkstra.out", "wt");
	
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
