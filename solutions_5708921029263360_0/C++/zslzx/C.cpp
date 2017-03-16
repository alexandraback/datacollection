#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
int J,P,S,K;
bool use[10+10][10+10][10+10];
int useJP[10+10][10+10];
int useJS[10+10][10+10];
int usePS[10+10][10+10];
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{
		memset(use,0,sizeof(use));
		memset(useJS,0,sizeof(useJP));
		memset(useJP,0,sizeof(useJP));
		memset(usePS,0,sizeof(useJP));
		scanf("%d%d%d%d",&J,&P,&S,&K);
		int ans=0;
		for(int i=1;i<=J;i++)
			for(int j=1;j<=P;j++)
				for(int k=1;k<=S;k++)
				{
					if(useJP[i][j]==K||useJS[i][k]==K||usePS[j][k]==K)continue;
					useJP[i][j]++;
					useJS[i][k]++;
					usePS[j][k]++;
					ans++;
					use[i][j][k]=true;
				}
		printf("Case #%d: %d\n",cas,ans);
		for(int i=1;i<=J;i++)
			for(int j=1;j<=P;j++)
				for(int k=1;k<=S;k++)
					if(use[i][j][k])printf("%d %d %d\n",i,j,k);
	}
	return 0;
}
