// b2.cpp : Defines the entry point for the console application.
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

int k[4] = {1,3,5,7};
int s[4] = {1,6,15,28};
int ans = 0;
int reshta = 0;
int lev;
int step;

void hid(int zl, int ls, int rs, int lv, int f){
	if (lev = lv && rs == step)  f = 1;
	if (zl == 0) {
		if (f) ans++;
		else reshta++;
		return ;
	}	
	if (ls == k[lv]-1 && rs ==k[lv]-1) {
		//if (f) ans++;
		if (lev = lv && rs+1 == step)  f = 1;
		hid(zl-1,0,0,lv+1,f);
		return ;

	}

	if (ls == k[lv]-1) {
		//if (lv == lev && rs+1 == step) ans++;
		//if (f) ans++;
		hid(zl-1, ls, rs+1,lv,f);
		return ;
	}

	if (rs == k[lv]-1) {
	//	if (f) ans++;
		hid(zl-1,ls+1,rs,lv,f);
		return ;
	}

	//if (lv==lev && rs+1 == step) ans++;
	hid(zl-1,ls,rs+1,lv,f);
	hid(zl-1,ls+1,rs,lv,f);
}

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int tnum;
	scanf("%d",&tnum);
	rep(tc,tnum) {
		int n,x,y;
		scanf("%d %d %d",&n,&x,&y);
		ans = 0;
		reshta = 0;
		printf("Case #%d: ",tc+1);
		if ((x+y)%2 == 1) {
			printf("0\n");
			continue;
		}

		if (x==0 && y==0 && n>0) {
			printf("1\n");
			continue;
		}

		if (x<0) x = -x;
		lev = (x+y)/2;
		step = y+1;

		/*int ind = 0;
		while (n > s[ind]) ind++;

		if (ind > lev) printf("1\n");
		else if (lev > ind) printf("0\n");
		else {*/
			hid(n-1,0,0,1,0);
			double res = ans*1.0/(ans+reshta);
			printf("%.6f\n",res);

/*		} */
	}
	return 0;
}

