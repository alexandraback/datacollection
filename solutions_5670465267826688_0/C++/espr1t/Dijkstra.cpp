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

int n, m;
char a[MAX];
int rev[MAX];

void solveTest() {
    init();
    fscanf(in, "%d %d %s", &n, &m, a);
    for (int i = 1; i < m; i++)
        for (int c = 0; c < n; c++)
            a[n * i + c] = a[c];
    
    rev[n * m] = 0;
    for (int i = n * m - 1; i >= 0; i--)
        rev[i] = ma3x[conv[(int)a[i]]][rev[i + 1]];
    
    int left = 0;
    for (int i = 0; i < n * m; i++) {
        left = ma3x[left][conv[(int)a[i]]];
        if (left == 1) {
//            fprintf(stderr, "  -- found 'i' ending at index %d.\n", i);
            int middle = 0;
            for (int c = i + 1; c < n * m; c++) {
                middle = ma3x[middle][conv[(int)a[c]]];
                if (middle == 2) {
//                    fprintf(stderr, "    >> found 'j' ending at index %d.\n", c);
                    if (rev[c + 1] == 3) {
                        fprintf(out, "YES\n");
                        return;
                    }
                }
            }
        }
    }
    fprintf(out, "NO\n");
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
