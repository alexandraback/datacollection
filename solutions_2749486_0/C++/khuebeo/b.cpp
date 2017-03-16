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
typedef pair<pair <int, int>,int> PIII;
 
template <class T> inline T MAX (T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN (T a, T b) { if (a < b) return a; return b; }

#define maxn 

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
char dc[]={'W','N','E','S'};

int fx,fy;

PIII s;
map<PIII,PIII> trace;
map<PIII,char> traceChar;

void TRACE(PIII t) {
	if(t==s) return;
	TRACE(trace[t]);
	cout << traceChar[t];
}

void solve() {
	trace.clear();
	traceChar.clear();
	queue<PIII> q;
	
	s=MP(MP(0,0),0);
	q.push(s);
	trace[s]=s;
	
	while(!q.empty()) {
		PIII z=q.front();q.pop();
		int x=z.F.F,y=z.F.S,step=z.S;
		REP(k,4) {
			int u=x+dx[k]*(step+1);
			int v=y+dy[k]*(step+1);
			PIII t=MP(MP(u,v),step+1);
			if(trace.find(t)==trace.end()) {
				q.push(t);
				trace[t]=z;
				traceChar[t]=dc[k];
				if(u==fx && v==fy) {
					TRACE(t);
					return;
				}
			}
		}
	}
}

int main() {
	freopen("a.inp","r",stdin);
	freopen("a.out","w",stdout);
	int ntest;
	cin >> ntest;
	FOR(test,1,ntest) {
		cin >> fx >> fy;
		cout << "Case #" << test <<": ";
		solve();
		cout << endl;
		DEBUG(test);
	} 
}

