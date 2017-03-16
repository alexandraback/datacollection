#include <iomanip>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <complex>
#include <cassert>
#include <bitset>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define dforall(i, c) for(decl(i, c.rbegin()); i!=c.rend(); ++i)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define D(a) cout << #a << "=" << a << endl;
#define pb push_back
#define mp make_pair

typedef long long int tint;

#define MAXN 128

bool x[MAXN], y[MAXN];
int T,N,M, a[MAXN][MAXN];

bool solve(int u, int v) {
	if (u==0 || v==0) return true;
		
	int minx = N+1, miny = M+1;
	int minval = 101;	
	forn(i,N) if (x[i]) forn(j,M) if (y[j]) {
		if (a[i][j] < minval) {
			minval = a[i][j];
			minx = i, miny = j;	
		}	
	}
	
	int cond = true;
	forn(j,M) if (y[j] && a[minx][j]!= minval) {cond = false; break;}
	if (cond) {
		x[minx] = false;
		return solve(u,v-1);	
	} 
	
	cond = true;
	forn(i,N) if (x[i] && a[i][miny] != minval) {cond = false; break;}
	if (cond) {
		y[miny] = false;
		return solve(u-1,v);	
	}
	return false;
}

int main () {
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	
	cin >> T;
	forn(caso,T) {
		cin >> N >> M;
		memset(x,true,sizeof(y));
		memset(y,true,sizeof(y));
		
		forn(i,N) forn(j,M) cin >> a[i][j];
		
		cout << "Case #" << caso+1 << ": ";
		if (solve(N,M)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}
