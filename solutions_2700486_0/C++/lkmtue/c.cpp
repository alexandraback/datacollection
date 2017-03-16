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

#define maxn 1111

int cur,cnt,n,needx,needy,used[maxn][maxn],t[maxn];

int dx[]={0,-1,1};
int dy[]={-1,-1,-1};

void att(int id) {
	if(id>n) {
		cur++;
		FOR(i,1,n) {
			int x=100,y=20,k=0;
			bool flag=false;
			while(1) {
				int u=x+dx[k];
				int v=y+dy[k];
				
				if(v<0) break;
					
				if(used[u][v]==cur) {
					if(k==0) k=t[i];
					else {
						if(flag) break;
						k=3-k;
						flag=true;
					}
				}
				else x=u,y=v;
				
			}
			if(x==needx && y==needy) cnt++;
			
			used[x][y]=cur;
			used[x][y+1]=cur;
			x-=100;
			
		}
		
		return;
	}
	t[id]=1;
	att(id+1);
	t[id]=2;
	att(id+1);
}

int main() {
	freopen("a.inp","r",stdin);
	int ntest;
	cin >> ntest;
	FOR(test,1,ntest) {
		cin >> n >> needx >> needy;
		needx+=100;
		cnt=0;
		att(1);
		printf("Case #%d: %.9lf\n",test,1.0*cnt/(1<<n));
	}
}
	
