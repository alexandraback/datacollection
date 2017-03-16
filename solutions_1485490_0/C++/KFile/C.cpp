#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PLL pair<LL,LL> 
#define PDD pair<double,double>
#define LL long long
#define INF 1000000000

using namespace std;

int T,N,M,i,j;
map<pair<PII,PLL>,LL> dp;
LL toyAmount[111],boxAmount[111];
int toyType[111],boxType[111];

LL solve(int toy,int box, LL toyAm, LL boxAm)
{
	if(toy==N || box==M) return 0LL;
	pair<PII,PLL> now = mp(mp(toy,box),mp(toyAm,boxAm));
	if(dp.find(now)!=dp.end()) return dp[now];
	
	LL &ret = dp[now] = 0LL;
	if(toyType[toy]!=boxType[box])
	{
		if(toy+1<N) ret = max(ret,solve(toy+1,box,toyAmount[toy+1],boxAm));
		if(box+1<M) ret = max(ret,solve(toy,box+1,toyAm,boxAmount[box+1]));
	} else
	
	{
		LL least = min(toyAm,boxAm);
		ret += least;
		toyAm -= least;
		boxAm -= least;
		
		if(!toyAm && !boxAm && toy+1<N && box+1<M) 
			ret+=solve(toy+1,box+1,toyAmount[toy+1],boxAmount[box+1]);
		else if(!toyAm && toy+1<N) 
			ret+=solve(toy+1,box,toyAmount[toy+1],boxAm);
		else if(!boxAm && box+1<M)
			ret+=solve(toy,box+1,toyAm,boxAmount[box+1]);
	}
	return ret;
}

int main()
{
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d %d",&N,&M);
		for(j=0;j<N;j++) scanf("%I64d %d",&toyAmount[j],&toyType[j]);
		for(j=0;j<M;j++) scanf("%I64d %d",&boxAmount[j],&boxType[j]);
		
		dp.clear();
		printf("Case #%d: %I64d\n",i,solve(0,0,toyAmount[0],boxAmount[0]));
	}
	return 0;
}

