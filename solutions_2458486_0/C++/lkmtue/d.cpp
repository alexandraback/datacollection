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
#define PR0(a,n) {cerr<<#a<<" = ";REP(_,n) cerr << (a[_]) << ' '; cerr << endl;}
#define ll long long
using namespace std;
 
const double PI = 2.0 * acos (0.0);
 
typedef long long LL;
typedef pair <int, int> PII;
 
template <class T> inline T MAX (T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN (T a, T b) { if (a < b) return a; return b; }

#define maxn 411

int k,n;
int start[maxn],need[maxn],num[maxn],inside[maxn][maxn];

int trace[1<<22];

int BIT(int s,int i) {
	return (s>>(i-1))&1;
}

void TRACE(int s) {
	if(s==0) return;
	TRACE(s-(1<<(trace[s]-1)));
	cout << trace[s] << " ";
}

int main() {
	freopen("a.inp","r",stdin);
	freopen("a.out","w",stdout);
	int ntest;
	cin >> ntest;
	FOR(test,1,ntest) {
		cin >> k >> n;		
		
		FOR(i,1,k) cin >> start[i];
		FOR(i,1,n) {
			cin >> need[i] >> num[i];
			FOR(j,1,num[i]) cin >> inside[i][j];
		}
		
		RESET(trace,-1);
		queue<int> q;
		
		trace[0]=0;
		q.push(0);
		
		while(!q.empty()) {
			int s=q.front();q.pop();
			
			int remain[maxn];
			RESET(remain,0);
			FOR(i,1,k) remain[start[i]]++;
			
			FOR(i,1,n) if(BIT(s,i)==1) {
				remain[need[i]]--;
				FOR(j,1,num[i]) remain[inside[i][j]]++;
			}
			
			
			FOR(i,1,n) if(BIT(s,i)==0 && remain[need[i]]>0) {
				int ss=s|(1<<(i-1));
				if(trace[ss]==-1) {
					q.push(ss);
					trace[ss]=i;
					
				}
			}
		}
		
		
		cout <<"Case #" << test << ": ";
		
		int finish=(1<<n)-1;
		if(trace[finish]==-1) cout << "IMPOSSIBLE";
		else TRACE(finish);
		
		cout << endl;
		cerr << test;
	}
}

