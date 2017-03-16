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

ll solve(char s0[], char s1[]) {
	if( !s0[0] ) return 0;
	if( s0[0]==s1[0] ) {
		if( s0[0] != '?' )
			return solve(s0+1, s1+1);
		else {
			char ss0[3][20], ss1[3][20];
			ll ans[3];
			int minn = 0;

			REP(i, 3) {
				strcpy(ss0[i], s0);
				strcpy(ss1[i], s1);
			}
			ss0[0][0] = ss1[0][0] = '0';
			ans[0] = solve(ss0[0]+1, ss1[0]+1);

			ss0[1][0] = '0', ss1[1][0] = '1';
			ans[1] = solve(ss0[1], ss1[1]);
			if( ans[1]<ans[minn] )
				minn = 1;

			ss0[2][0] = '1', ss1[2][0] = '0';
			ans[2] = solve(ss0[2], ss1[2]);
			if( ans[2]<ans[minn] )
				minn = 2;

			strcpy(s0, ss0[minn]);
			strcpy(s1, ss1[minn]);
			return ans[minn];
		}
	} else {
		if( s0[0]!='?' && s1[0]!='?' ) {
			if( s0[0]<s1[0] ) {
				for(int i=0; s0[i]; ++i) {
					if( s0[i]=='?' ) s0[i] = '9';
					if( s1[i]=='?' ) s1[i] = '0';
				}
				return atoll(s1)-atoll(s0);
			} else {
				return solve(s1, s0);
				/*
				for(int i=0; s0[i]; ++i) {
					if( s0[i]=='?' ) s0[i] = '0';
					if( s1[i]=='?' ) s1[i] = '9';
				}
				return atoll(s0)-atoll(s1);
				*/
			}
		} else if( s0[0]=='?' ) {
			char ss0[3][20], ss1[3][20];
			ll ans[3];
			int minn = 0;

			REP(i, 3) {
				strcpy(ss0[i], s0);
				strcpy(ss1[i], s1);
			}

			if( ss1[2][0]!='0' ) {
				ss0[2][0] = ss1[2][0]-1;
				ans[2] = solve(ss0[2], ss1[2]);
				minn = 2;
			}

			ss0[0][0] = ss1[0][0];
			ans[0] = solve(ss0[0]+1, ss1[0]+1);
			if( ans[0]<ans[minn] )
				minn = 0;

			if( ss1[1][0]!='9' ) {
				ss0[1][0] = ss1[1][0]+1;
				ans[1] = solve(ss0[1], ss1[1]);
				if( ans[1]<ans[minn] )
					minn = 1;
			}

			strcpy(s0, ss0[minn]);
			strcpy(s1, ss1[minn]);
			return ans[minn];
		} else if( s1[0]=='?' ) {
			return solve(s1, s0);
		}
	}
}

int main() {
#ifdef KEVINPTT
	//freopen("a.in", "r", stdin);
	//freopen("a.ans", "w", stdout);
#endif
	DRI(T);
	REP1(casen, T) {
		char score[2][20];
		scanf("%s %s", score[0], score[1]);
		solve(score[0], score[1]);
		printf("Case #%d: %s %s\n", casen, score[0], score[1]);
	}
	return 0;
}

