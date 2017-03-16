#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP(a, b) make_pair(a, b)
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#pragma comment(linker, "/STACK:1024000000,1024000000") 

int R, C, X;

// rechardWin : one domino exist force the putter can't fill R * C
void output(int ti, int rechardWin) {
	printf("Case #%d: %s\n", ti, rechardWin ? "RICHARD" : "GABRIEL");
}

int main() {
//freopen("in", "r", stdin);
//freopen("D-small-attempt2.in", "r", stdin);
//freopen("D-small-attempt2.out", "w", stdout);
//freopen("D-large.in", "r", stdin);
//freopen("D-large.out", "w", stdout);
	int test;	scanf("%d", &test);
	for (int ti = 1; ti <= test; ti++) {
		scanf("%d %d %d", &X, &R, &C);
		if (R * C % X) { 
			output(ti, 1);
			continue;
		}
		if (X >= 7) {
			output(ti, 1);
			continue;
		}
		if (max(R, C) < X || min(R, C) < (X - 1) / 2 + 1) {
			output(ti, 1);
			continue;
		}
		if (X == 4 && R * C == 8) {
			output(ti, 1);
			continue;
		}

		output(ti, 0);
	}
}
