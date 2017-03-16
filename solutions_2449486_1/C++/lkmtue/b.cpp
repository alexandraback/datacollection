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
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()
 
#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#define PR(a,n) {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n) {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}
#define ll long long
using namespace std;
 
const double PI = 2.0 * acos (0.0);
 
typedef long long LL;
typedef pair <int, int> PII;
 
template <class T> inline T MAX (T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN (T a, T b) { if (a < b) return a; return b; }

#define maxn 111

int m,n;
int a[maxn][maxn],b[maxn][maxn];

bool possible() {
	FOR(i,1,m) FOR(j,1,n) if(a[i][j]>b[i][j]) return false;
	return true;
}

bool same() {
	FOR(i,1,m) FOR(j,1,n) if(a[i][j]!=b[i][j]) return false;
	return true;
}

bool chkRow(int i,int v) {
	FOR(j,1,n) if(v<a[i][j]) return false;
	return true;
}

bool chkCol(int j,int v) {
	FOR(i,1,m) if(v<a[i][j]) return false;
	return true;
}

string solve() {
	FOR(i,1,m) FOR(j,1,n) b[i][j]=100;
	
	while(1) {
		if(!possible()) return "NO";
		if(same()) return "YES";
		
		int x=0,y=0;
		FOR(i,1,m) FOR(j,1,n) if(a[i][j]!=b[i][j] && (x==0|| a[i][j]>a[x][y])) x=i,y=j;
		
		if(chkRow(x,a[x][y])) FOR(j,1,n) b[x][j]=a[x][y];
		else if(chkCol(y,a[x][y])) FOR(i,1,m) b[i][y]=a[x][y];
		else return "NO";		
	}
}

int main() {
	freopen("a.inp","r",stdin);
	freopen("a.out","w",stdout);
	int ntest;
	cin >> ntest;
	FOR(test,1,ntest) {
		cin >> m >> n;
		FOR(i,1,m) FOR(j,1,n) cin >> a[i][j];
		cout << "Case #" << test << ": " << solve() << endl;
	}
}
