#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<cassert>
#include<complex>
using namespace std;

#define LL long long

LL E, R, V[100000];

int N;

LL dp[20][10];

int check(LL &a, LL b)
{
	if(b > a) a= b;
}

LL run()
{
	scanf("%lld %lld %d", &E, &R, &N);
	
	LL rate = min(E, R);
	LL greedy=0;
	for(int i=1;i<=N;++i){
		scanf("%lld", V+i);
		greedy += V[i] * rate;
	}
	if(E > R) greedy += (E - R) * (*max_element(V+1,V+1+N));
	
	memset(dp,-1,sizeof(dp));
	dp[1][E]=0;
	for(int i=1;i<=N;++i)
		for(int j=0;j<=E;++j)
		{
			if(dp[i][j] > -1)
			{
				for(int k=0;k<=j;++k)
				{
					check(dp[i+1][min(E, j - k + R)], dp[i][j] + k * V[i]);
				}
			}
		}
	LL res=0;
	for(int j=0;j<=E;++j)
		check(res, dp[N+1][j]);
	if(res != greedy) cerr << "Error!!"<<endl;
	return res;
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	
	int test;scanf("%d",&test);
	for(int no=1;no<=test;++no)
		printf("Case #%d: %lld\n", no, run());
}
