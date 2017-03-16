//Written by technolt~h

#pragma comment(linker, "/STACK:16777216")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
 #include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
 #include <complex>

#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
 #define FORN(i,a,b) for(int i=a;i<b;i++)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define RESET(c,x) memset (c, x, sizeof (c))

#define sqr(x) ((x) * (x))
#define PB push_back
 #define MP make_pair
#define F first
#define S second
#define Aint(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()

#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#define PR(a,n) {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n) {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}
#define LL long long
#define PI acos(-1.0)

using namespace std;

int f[5005][12];
int N, A;
int mote[11];

int call(int cur, int pos) {
//cerr << cur << " " << pos << endl;
	if (pos == N + 1) return 0;
	if (f[cur][pos] != -1) return f[cur][pos];
	
	f[cur][pos] = call(cur, pos + 1) + 1;
	
	if (cur > mote[pos]) 
		f[cur][pos] = min(f[cur][pos], call(cur + mote[pos], pos + 1));
	
	FOR (i, 1, cur - 1) 
		if (cur + i <= 5000)
			f[cur][pos] = min(f[cur][pos], call(cur + i, pos) + 1);
			
	return f[cur][pos];
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("a.out", "w", stdout);
	int ntest;
	
	cin >> ntest;
	FOR (test, 1, ntest) {
		cout << "Case #" << test << ": ";
		
		cin >> A >> N;
		FOR (i, 1, N) cin >> mote[i];
		sort(mote + 1, mote + N + 1);
		RESET(f, -1);
		
		cout << call(A, 1) << endl;
	}
    return 0;
}



