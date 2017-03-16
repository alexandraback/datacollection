#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <utility>
#include <cctype>
#include <list>
#include <bitset>

using namespace std;

#define FORALL(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORB(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef long double ld;
typedef complex<ld> vec;

typedef pair<int,int> pii;
typedef map<int,int> mii;

#define pb push_back
#define mp make_pair

#define MAXN 18
char A[MAXN];
char B[MAXN];
ll pw10[MAXN];
int N;

#define EQ 0
#define A_BIGGER 1
#define B_BIGGER 2
#define MAXT 3
#define INF 1000000000000000000ll

bool seen[MAXN][MAXT];
ll dp[MAXN][MAXT];
int chA[MAXN][MAXT];
int chB[MAXN][MAXT];
int newT[MAXN][MAXT];

#define cando(S,i,s) ((S[i] == '?' || S[i] == ('0'+s)))

ll f(ll x, int t) {
	if (t == EQ) return abs(x);
	if (t == A_BIGGER) return x;
	if (t == B_BIGGER) return -x;
	assert(false);
}

ll solve(int i, int t) {
	ll& ans = dp[i][t];
	int& cha = chA[i][t];
	int& chb = chB[i][t];
	int& st  = newT[i][t];

	if (seen[i][t]) return ans;
	seen[i][t] = true;

	if (i==N) return ans = 0;
	

	// if A bigger, set ans = INF and try to minimize ans (A-B)
	// if B bigger, set ans = -INF and try to minimize -ans (B-A)
	// if eq, set ans = INF and try to minimize the abs difference abs(A-B)

	if (t==A_BIGGER) ans = INF;
	else if (t==B_BIGGER) ans = -INF;
	else ans = INF;

	cha = chb = 9;

	FOR(a,10) FOR(b,10) {
		if (!cando(A,i,a)) continue;
		if (!cando(B,i,b)) continue;
		
		int new_t;
		if (t == A_BIGGER) new_t = A_BIGGER;
		else if (t == B_BIGGER) new_t = B_BIGGER;
		else if (a>b) new_t = A_BIGGER;
		else if (b>a) new_t = B_BIGGER;
		else new_t = EQ;

		ll diff = (a-b)*pw10[N-i-1] + solve(i+1, new_t);

		if (f(diff,t) < f(ans,t) || (f(diff,t) == f(ans,t) && (a < cha || (a == cha && b < chb)))) {
			ans = diff;
			cha = a;
			chb = b;
			st = new_t;
		}
	}

	assert(abs(ans) < INF);
	return ans;
}

int main() {
	pw10[0] = 1;
	FORALL(i,1,MAXN-1) pw10[i] = pw10[i-1]*10;

	int TEST;
	scanf("%d",&TEST);
	FOR(test,TEST) {
		scanf("%s%s",&A[0],&B[0]);
		N = strlen(A);
		assert(strlen(B) == N);

		memset(dp,-1,sizeof(dp));
		memset(seen,0,sizeof(seen));

		solve(0,0);

		int i = 0, t = EQ;
		while(i<N) {
			A[i] = (char)(chA[i][t]+'0');
			B[i] = (char)(chB[i][t]+'0');
			t = newT[i][t];
			i++;
		}

		printf("Case #%d: %s %s\n", test+1, A, B);
	}
}































