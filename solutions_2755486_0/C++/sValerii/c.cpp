// c.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <list>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <ctime>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define forr(i,a,b) for (int i=a; i<=b; i++)
#define ford(i,a,b) for (int i=a; i>=b; i--)
#define mset(a,b) memset(a,b,sizeof(a))
#define sz(a) int( a.size() )
#define all(A) A.begin(),A.end()
#define sqr(q) q*q
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define X first
#define Y second

typedef long long i64;
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef pair<int,int> PII;
typedef vector<string> VS;

typedef struct {
	int sti,fini,s;
} attack;

const int WE = 1000;
int delWE = 220;
const int AN = 500;
const int D = 676060;
attack a[AN];
VI d[D];
int n;
int w[WE];

int getMin(int st, int fin) {
	int mv = w[st];
	forr(i,st,fin)
		if (w[i] < mv) mv = w[i];
	return mv;
}

void setMin(int st, int fin, int v) {
	forr(i,st,fin)
		if (w[i] < v) w[i] = v;
}

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int tnum;
	scanf("%d",&tnum);
	rep(tc,tnum) {
		rep(i,WE) w[i] = 0;
		rep(i,D) d[i].clear(); 
		int n;
		scanf("%d",&n);
		int ind = 0;
		rep(i,n) {
			int ds, num, west,east, st, dday,dp,dels;
			scanf("%d %d %d %d %d %d %d %d",&ds, &num, &west,&east, &st, &dday,&dp,&dels);
			rep(j,num) {
				a[ind].s = st+j*dels;
				a[ind].sti = (west+delWE+j*dp)*2;
				a[ind].fini = (east+delWE+j*dp)*2;
				int da = ds+j*dday;
				d[da].pb(ind);
				ind++;
			}
		}
		int ans = 0;
		rep(i,D)
			if (!d[i].empty()) {
					rep(j,sz(d[i])) {
						int ind = d[i][j];
						int mv = getMin(a[ind].sti,a[ind].fini);
						if (mv < a[ind].s) ans++;
					}
				
					rep(j,sz(d[i])) {
						int ind = d[i][j];
						setMin(a[ind].sti,a[ind].fini,a[ind].s);
					}
					

			}
			printf("Case #%d: %d\n",tc+1,ans);
	}
	return 0;
}

