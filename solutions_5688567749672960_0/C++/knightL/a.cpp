#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <numeric>
#include <cstring>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

const int MAXN=1000001;

int rev[MAXN];
int q[MAXN];
int res[MAXN];

ll solve()
{
	int N;
	scanf("%d",&N);
	return res[N];
}

int main()
{
	REP(i,MAXN)
	{
		rev[i]=0;
		int cur=i;
		while(cur)
		{
			rev[i]=rev[i]*10+cur%10;
			cur/=10;
		}
	}
	int l=0, r=0;
	q[r++]=1;
	memset(res,-1,sizeof(res));
	res[1]=1;
	while(l<r)
	{
		int c=q[l++];
		if(res[rev[c]]==-1)
		{
			res[rev[c]]=res[c]+1;
			q[r++]=rev[c];
		}
		if(c+1<MAXN && res[c+1]==-1)
		{
			res[c+1]=res[c]+1;
			q[r++]=c+1;
		}
	}
	int T;
	scanf("%d",&T);
	for(int test=1;test<=T;test++)
		printf("Case #%d: %lld\n",test, solve());
	return 0;
}
