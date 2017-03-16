// Template.cpp by kevinptt 20140306
// #include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <deque>
#define REP(I, N) for(int I=0; I<(N); ++I)
#define REPP(I, A, B) for(int I=(A); I<(B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int X; scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
//typedef pair<int,int> pii;


int main() {
	DRI(T);
	REP(casen, T) {
		long long p, q, gcd;
		scanf("%I64d/%I64d", &p, &q);
		gcd = __gcd(p, q);
		p /= gcd, q /= gcd;
		bool ok=false;
		int i, ans=-1;
		long long j;
		double num = 1.0*p/q;
		for(i=0, j=1; i<40; ++i, j<<=1) {
			if( ans==-1 && num*j >= 1-1e-9 ) ans=i;
			if( q==j ) { ok=true; break; }
		}
		printf("Case #%d: ", casen+1);
		if( ok ) printf("%d\n", ans);
		else puts("impossible");
	}

	return 0;
}

