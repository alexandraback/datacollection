// Template.cpp by kevinptt 20150108
#include <bits/stdc++.h>
/*
#include <cstdio>
#include <cstring>
#include <cmath>

#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>

#include <iostream>
// */
using namespace std;

#define REP(I, N) for(int I=0; I<(N); ++I)
#define REP1(I, N) for(int I=1; I<=(N); ++I)
#define REPP(I, A, B) for(int I=(A); I<(B); ++I)
#define REPR(I, N) for(int I=N-1; I>=0; --I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int X; scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define MP make_pair
#define PB push_back
#define MSET(x, y) memset(x, y, sizeof(x))
#define F first
#define S second
typedef long long ll;
typedef pair<int,int> pii;

/***************************************************************/

int cnt[127];
int ans[10];

void process(int num, int _cnt, const char *STR) {
	while( _cnt-- ) {
		ans[num]++;
		for(int i=0; STR[i]; ++i)
			cnt[STR[i]]--;
	}
}

void solve(char str[]) {
	MSET(cnt, 0);
	MSET(ans, 0);
	for(int i=0; str[i]; ++i)
		cnt[str[i]]++;
	process(0, cnt['Z'], "ZERO");
	process(2, cnt['W'], "TWO");
	process(4, cnt['U'], "FOUR");
	process(6, cnt['X'], "SIX");
	process(8, cnt['G'], "EIGHT");
	process(1, cnt['O'], "ONE");
	process(3, cnt['T'], "THREE");
	process(5, cnt['F'], "FIVE");
	process(7, cnt['S'], "SEVEN");
	process(9, cnt['I'], "NINE");
}

int main() {
#ifdef KEVINPTT
	//freopen("a.in", "r", stdin);
	//freopen("a.ans", "w", stdout);
#endif
	DRI(n);
	REP1(casen, n) {
		char str[2005];
		scanf("%s", str);
		solve(str);
		printf("Case #%d: ", casen);
		for(int i=0; i<10; ++i)
			while(ans[i]--)
				printf("%d", i);
		puts("");
	}
	
	return 0;
}

