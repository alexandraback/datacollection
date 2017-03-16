#define _CRT_SECURE_NO_DEPRECATE

#pragma comment(linker,"/STACK:260108864")

#include <iostream>
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
#define INF 2000000000
#define PI 3.141592653589
#define eps 0.000000001
#define MOD 1000000007
#define PRIME 1000003

using namespace std;

VI d;
vector< double > res;
int sum;

bool can(int who, double perc)
{
	double score(d[who]+sum*perc);
	double left(1-perc);
	rept(i,sz(d))
	{
		if (i==who) continue;
		double have(d[i]);
		if (have>score) continue;
		double lft(score-have);
		double need(lft/sum);
		left-=need;
		if (left<0.) return false;
	}
	if (left>0. || abs(left)<eps) return true;
	return false;
}

void solve()
{
	sum=accumulate(all(d),0);
	rept(i,sz(d))
	{
		double BAD(0.),GOOD(1.);
		rept(temp,300)
		{
			double med((BAD+GOOD)/2.);
			if (can(i,med)) BAD=med;
			else GOOD=med;
		}
		res.pb(BAD);
	}
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
		printf("Case #%d: ",t+1);
		int n;
		scanf("%d",&n);
		d.resize(n);
		rept(i,n) scanf("%d",&d[i]);
		res.clear();
		solve();
		rept(i,n)
		{
			if (i) printf(" ");
			printf("%.8lf",res[i]*100);
		}
		printf("\n");
	}
	return 0;
}