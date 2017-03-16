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
const long long INF = 2000000000000000002LL;

int n;
int a[MAX], b[MAX];
int dyn[MAX][3];

long long bestDiff;
long long withA, withB;

void recurse(int idx, long long num1, long long num2) {
    if (idx >= n) {
        long long diff = num1 > num2 ? num1 - num2 : num2 - num1;
        if (bestDiff > diff)
            bestDiff = diff, withA = num1, withB = num2;
        else if (bestDiff == diff && (num1 < withA || (num1 == withA && num2 < withB)))
            withA = num1, withB = num2;
        return;
    }
    
    /*
    if (a[idx] == -1 && b[idx] == -1) {
        for (int d1 = 0; d1 < 10; d1++) {
            for (int d2 = 0; d2 < 10; d2++) {
                recurse(idx + 1, num1 * 10 + d1, num2 * 10 + d2);
            }
        }
    } else if (a[idx] == -1) {
        for (int d1 = 0; d1 < 10; d1++) {
            recurse(idx + 1, num1 * 10 + d1, num2 * 10 + b[idx]);
        }
    } else if (b[idx] == -1) {
        for (int d2 = 0; d2 < 10; d2++) {
            recurse(idx + 1, num1 * 10 + a[idx], num2 * 10 + d2);
        }
    } else {
        recurse(idx + 1, num1 * 10 + a[idx], num2 * 10 + b[idx]);
    }
    */
    
    if (a[idx] == -1 && b[idx] == -1) {
        if (num1 == num2) {
            recurse(idx + 1, num1 * 10 + 0, num2 * 10 + 0);
            recurse(idx + 1, num1 * 10 + 1, num2 * 10 + 0);
            recurse(idx + 1, num1 * 10 + 0, num2 * 10 + 1);
        } else if (num1 < num2) {
            recurse(idx + 1, num1 * 10 + 1, num2 * 10 + 0);
            recurse(idx + 1, num1 * 10 + 9, num2 * 10 + 0);
        } else {
            recurse(idx + 1, num1 * 10 + 0, num2 * 10 + 9);
        }
    } else if (a[idx] == -1) {
        if (num1 == num2) {
            recurse(idx + 1, num1 * 10 + b[idx], num2 * 10 + b[idx]);
            if (b[idx] != 9) recurse(idx + 1, num1 * 10 + (b[idx] + 1), num2 * 10 + b[idx]);
            if (b[idx] != 0) recurse(idx + 1, num1 * 10 + (b[idx] - 1), num2 * 10 + b[idx]);
        } else if (num1 < num2) {
            recurse(idx + 1, num1 * 10 + 9, num2 * 10 + b[idx]);
        } else {
            recurse(idx + 1, num1 * 10 + 0, num2 * 10 + b[idx]);
        }
    } else if (b[idx] == -1) {
        if (num1 == num2) {
            recurse(idx + 1, num1 * 10 + a[idx], num2 * 10 + a[idx]);
            if (a[idx] != 9) recurse(idx + 1, num1 * 10 + a[idx], num2 * 10 + (a[idx] + 1));
            if (a[idx] != 0) recurse(idx + 1, num1 * 10 + a[idx], num2 * 10 + (a[idx] - 1));
        } else if (num1 < num2) {
            recurse(idx + 1, num1 * 10 + a[idx], num2 * 10 + 0);
        } else {
            recurse(idx + 1, num1 * 10 + a[idx], num2 * 10 + 9);
        }
    } else {
        recurse(idx + 1, num1 * 10 + a[idx], num2 * 10 + b[idx]);
    }
}

void printFixed(long long num, int digs) {
    string str;
    while (num) {
        str.push_back(num % 10 + '0');
        num /= 10;
    }
    while ((int)str.size() < digs)
        str.push_back('0');
    reverse(str.begin(), str.end());
    fprintf(out, "%s", str.c_str());
}

void solveTest() {
    char tmpA[MAX], tmpB[MAX];
    fscanf(in, "%s %s", tmpA, tmpB);
    n = (int)strlen(tmpA);
    for (int i = 0; i < n; i++) {
        a[i] = tmpA[i] == '?' ? -1 : tmpA[i] - '0';
        b[i] = tmpB[i] == '?' ? -1 : tmpB[i] - '0';
    }
    
    bestDiff = INF;
    withA = withB = -1;
    recurse(0, 0, 0);

    printFixed(withA, n);
    fprintf(out, " ");
    printFixed(withB, n);
    fprintf(out, "\n");
}

int main(void) {
	unsigned sTime = clock();
	in = fopen("CloseMatch.in", "rt");
	out = fopen("CloseMatch.out", "wt");
	
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
