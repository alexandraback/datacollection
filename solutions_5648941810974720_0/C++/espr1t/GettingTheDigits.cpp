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

const int MAX = 2048;

int n;
char a[MAX];
int cnt[MAX];
int ans[10];

void handleDigit(int digit, char id, string name) {
    ans[digit] = cnt[(int)id];
    for (int i = 0; i < (int)name.size(); i++)
        cnt[(int)name[i]] -= ans[digit];
}

void solveTest() {
    fscanf(in, "%s", a);
    n = (int)strlen(a);
    
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++)
        cnt[(int)a[i]]++;
    
    handleDigit(0, 'Z', "ZERO");
    handleDigit(2, 'W', "TWO");
    handleDigit(6, 'X', "SIX");
    handleDigit(8, 'G', "EIGHT");
    handleDigit(4, 'U', "FOUR");
    handleDigit(5, 'F', "FIVE");
    handleDigit(7, 'V', "SEVEN");
    handleDigit(3, 'H', "THREE");
    handleDigit(1, 'O', "ONE");
    handleDigit(9, 'I', "NINE");
    
    for (int digit = 0; digit < 10; digit++) {
        for (int i = 0; i < ans[digit]; i++)
            fprintf(out, "%d", digit);
    }
    fprintf(out, "\n");
}

int main(void) {
	unsigned sTime = clock();
	in = fopen("GettingTheDigits.in", "rt");
	out = fopen("GettingTheDigits.out", "wt");
	
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
