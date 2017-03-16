#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<a;++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

int T, A, B, D, P;

bool lt(char a[10], char b[10], char bsh) {
	int ia = D-1, ib = D-1-bsh;
	REP(i,D) {
		if (a[ia] < b[ib]) return true;
		if (a[ia] > b[ib]) return false;
		--ia; --ib; if (ib < 0) ib = D-1;
	}
	return false;
}

int rot(int n) {
	int d = n%10;
	n /= 10;
	n += d*P/10;
	return n;
}

int cnt(int n) {
	int res = 0;
	int m = n;
	int used[10]; int usedc = 0;
	REP(sh, D) {
		m = rot(m);
		if (m <= n) continue;
		if (m > B) continue;
		bool ok = true;
		REP(i,usedc) if (used[i] == m) {ok = false;break;}
		if (!ok) continue;
		used[usedc++] = m;
		//printf("%d %d\n", n, m);
		++res;
	}
	return res;
}

int main() {
	scanf("%d", &T);
	REP(t,T) {
		scanf("%d%d", &A, &B);
		D = 0; P = 1; int tt = A;
		while (tt) { ++D; tt /= 10; P *= 10; }
		int res = 0;
		FOR(i,A,B-1) {
			res += cnt(i);
		}
		printf("Case #%d: %d\n", t+1, res);
	}
	return 0;
}
