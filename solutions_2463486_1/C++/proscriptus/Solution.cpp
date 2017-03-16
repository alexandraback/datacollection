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
#define eps 0.00000000000000001
#define MOD 1000000007
#define PRIME 1000003

using namespace std;

vector<LL> pals;
vector<LL> sqPals;

bool bruteforce(LL n)
{
	char c[20];
	int len=0;
	while (n!=0)
	{
		c[len++]='a'+(n%10);
		n/=10;
	}
	rept(i,len/2)
		if (c[i]!=c[len-i-1])
			return false;
	return true;
}

void fillPals()
{
	for (int i=1; i<100000000; ++i)
		if (bruteforce(i))
			pals.pb(i);
}

void fillSqPals()
{
	rept(i,sz(pals))
		if (bruteforce(pals[i]*pals[i]))
			sqPals.pb(pals[i]*pals[i]);
}

void precalc()
{
	fillPals();
	fillSqPals();
}

int main()
{
#ifndef ONLINE_JUDGE
	{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}
#endif
	precalc();
	int n;
	scanf("%d",&n);
	rept(i,n)
	{
		LL a,b;
		cin>>a>>b;
		int ans=0;
		rept(j,sz(sqPals))
			if (sqPals[j]>=a && sqPals[j]<=b)
				++ans;
		printf("Case #%d: %d\n",i+1,ans);
	}
	return 0;
}