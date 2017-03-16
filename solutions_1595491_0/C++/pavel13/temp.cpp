#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <string.h>
using namespace std;
#define REP(i,n) for(int i=0,n_=(n);i<n_;i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FOR(i,a,b) for (int i=a,b_=b;i<=(b);i++)
#define ALL(a) a.begin(),a.end()
#define SZ(a) (int)(a).size()
#define SORT(a) sort(ALL(a))
#define INF 1073741823
#define DEB(x) cerr<<#x<<":"<<x<<"\n"
#define PB(b) push_back(b)
#define i64 long long
#define FOREACH(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

vector<int> SplitInt(string &s)
{
	vector<int>Res;int tmp;stringstream a(s);
	while (a>>tmp){Res.push_back(tmp);}return Res;
}

vector<string> SplitStr(string &s)
{
	vector<string>Res;string tmp;stringstream a(s);
	while (a>>tmp){Res.push_back(tmp);}return Res;
}

//////////////////////////////////////////////////////////////
int DP[111][111];
int G[123]={0};
int B[123]={0};
int fill()
{	
	FOR(i,0,10)
	FOR(j,0,10)
	FOR(k,0,10)
	{
		if(abs(i-j)<2&&abs(i-k)<2&&abs(k-j)<2)
			G[i+j+k]=max(max(max(i,j),k),G[i+j+k]);
		if((max(max(i,j),k)-min(min(i,j),k))==2)
			B[i+j+k]=max(max(max(i,j),k),B[i+j+k]);
	}
}
int maxx(int n)
{
	return B[n];
}
int maxS(int n)
{
	return G[n];
}
int n,p,S[101];
int go(int pos,int t)
{
	if (pos==n)
	{
		if (t==0)
		return 0;
		return -1;
	}
	int &y=DP[pos][t];
	if (y!=-1)
	return y;
	y=0;
	if(t)
	if (S[pos]>=2&&S[pos]<=28)
	{

		int r=go(pos+1,t-1);

		int s=0;
		if (r!=-1)
		{
		if (maxx(S[pos])>=p)
			y=max(r+1,y);
		else
		y=max(r,y);
		}
	
	}
	int r=go(pos+1,t);
	int s=0;
	if (r!=-1)
	if (maxS(S[pos])>=p)
		y=max(r+1,y);
	else
		y=max(r,y);
//	printf ("%d %d %d\n",pos,t,y);
	return y;
}
int main ()
{
	int c;
	fill();
//	REP(i,30)
//	DEB(i<<":"<<G[i]);
//	REP(i,30)
//	DEB(i<<":"<<B[i]);
	scanf ("%d",&c);
	FOR(cas,1,c)
	{
		int res=0;
		int s;

		scanf("%d%d%d",&n,&s,&p);
		REP(i,n)
			scanf ("%d",&S[i]);
		memset(DP,-1,sizeof DP);
		res=go(0,s);
		printf ("Case #%d: %d",cas,res);

		printf ("\n");
	}
	return 0;
}

