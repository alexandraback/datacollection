#define _CRT_SECURE_NO_DEPRECATE

#pragma comment(linker,"/STACK:267386880")

#include <iostream>
#include <functional>
#include <ctime>
#include <cstdio>
#include <memory>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <utility>
#include <iterator>
#include <bitset>
#include <sstream>
#include <numeric>

#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
#define LL long long
#define ULL unsigned LL
#define VI vector<int>
#define X first
#define Y second
#define sz(_v) ((int)_v.size())
#define all(_v) (_v).begin(),(_v).end()
#define FOR(i,a,b) for (int i(a); i<=(b); ++i)
#define rep(i,a) FOR(i,1,a)
#define rept(i,a) FOR(i,0,(int)(a)-1)
#define x1 X1
#define y1 Y1
#define sqr(a) ((a)*(a))
#define C(a) memset((a),0,sizeof (a))
#define MS(a,x) memset((a),(x),sizeof (a))
#define INF 1000000000
#define PI 3.141592653589
#define eps 0.00000000001
#define MOD 1000000007
#define PRIME 1000003

using namespace std;

VI sched;
int e,r;

int check(int pos)
{
	int energy=e;
	int ans=0;
	int hx=pos;
	rept(i,sz(sched))
	{
		energy-=hx%6;
		ans+=sched[i]*(hx%6);
		hx/=6;
		if (energy < 0)
			return 0;
		energy+=r;
		energy=min(e,energy);
	}
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}
#endif
	int tst;
	scanf("%d",&tst);
	rept(t,tst)
	{
		printf("Case #%d: ", t+1);
		int n;
		scanf("%d%d%d",&e,&r,&n);
		sched.resize(n);
		rept(i,n)
			scanf("%d",&sched[i]);
		int ans=0;
		int mxhx=1;
		rept(i,sz(sched))
			mxhx*=6;
		rept(i,mxhx)
			ans=max(ans,check(i));
		printf("%d\n",ans);
	}
	return 0;
}