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
#define oo 1000111


using namespace std;

int f[111][111];
int N, A;
int mote[111];

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("a2.out", "w", stdout);
	int ntest;
	
	cin >> ntest;
	FOR (test, 1, ntest) {
		cout << "Case #" << test << ": ";
		
		cin >> A >> N;
		FOR (i, 1, N) cin >> mote[i];
		sort(mote + 1, mote + N + 1);
		
		RESET (f, -1);
		
		f[0][0] = A;
		FOR (i, 1, 100) 
			f[0][i] = min(oo, f[0][i - 1] * 2 - 1);
		
		FOR (i, 1, N) {
			if (f[i - 1][0] != -1 && f[i - 1][0] > mote[i])
				f[i][0] = min(oo, f[i - 1][0] + mote[i]);
				
			FOR (k, 1, 100) {
			
				if (f[i-1][k - 1] != -1) f[i][k] = f[i - 1][k - 1];
				
				if (f[i - 1][k] != -1 && f[i - 1][k] > mote[i]) {
					int tmp = f[i - 1][k] + mote[i];
					if (f[i][k] == -1) f[i][k] = tmp;
					else (f[i][k] = max(f[i][k], tmp));
				}
					
				if (f[i][k - 1] != -1) {
					int tmp = min(oo, f[i][k - 1] * 2 - 1);
					if (f[i][k] == -1) f[i][k] = tmp;
					else (f[i][k] = max(f[i][k], tmp));
				}
			}
		}
		
		FOR (i, 0, 101)
			if (f[N][i] != -1) {
				cout << i << endl;
				break;
			}
	}
    return 0;
}



