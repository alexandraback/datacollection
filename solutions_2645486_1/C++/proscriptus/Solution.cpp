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

VI s;
int e,r;
vector< pair<LL,LL> > need;
priority_queue<pii, vector<pii>, less<pii> > pq;

LL getAns()
{
	while (!pq.empty())
		pq.pop();
	need.assign(sz(s),mp(-1,-1));
	rept(i,sz(s))
		pq.push(mp(s[i],i));
	while (!pq.empty())
	{
		pii cur=pq.top();
		pq.pop();
		int pos=cur.Y;
		int lft(pos-1);
		while (lft>=0 && need[lft].X==-1)
			--lft;
		int rgh(pos+1);
		while (rgh<sz(s) && need[rgh].X==-1)
			++rgh;
		LL canSpend,shouldLeft;
		if (lft==-1)
			canSpend=e;
		else
			canSpend=min(need[lft].X+(pos-lft)*1ll*r,e*1ll);
		if (rgh==sz(s))
			shouldLeft=0;
		else
			shouldLeft=max(need[rgh].X+need[rgh].Y-(rgh-pos)*1ll*r,0ll);
		need[pos].X=shouldLeft;
		if (canSpend>shouldLeft)
			need[pos].Y=canSpend-shouldLeft;
		else
			need[pos].Y=0;
	}
	LL ans=0;
	rept(i,sz(s))
		ans+=need[i].Y*s[i];
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
		s.resize(n);
		rept(i,n)
			scanf("%d",&s[i]);
		cout<<getAns()<<endl;
	}
	return 0;
}