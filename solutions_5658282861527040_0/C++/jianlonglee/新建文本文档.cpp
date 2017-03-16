#include<iostream>
#include<cstdio>
#include<algorithm>
#include<time.h>
#include<cmath>
#include<set>
#include<vector>
#include<cstring>
#include<string>
#define bug puts("here!")
#define maxn 40
using namespace std;
#define ll long long
#define inf 1e17
int mod;
#define vec vector<int>
#define mat vector<vec>
int a[maxn],b[maxn],k[maxn],T;
ll dp[33][2][2][2][2][2];
/*void solve(int d,int a_,int b_,int fa,int fb,int fk)
{
	if(d<=0)
		return;
	int mx_a,mx_b;
	mx_a=(!fa)||a[d-1];

	if(!fk||k[d-1])
	{
		mx_a=(!fa)||a[d-1];
		mx_b=(!fb)||b[d-1];
		for(int i=0;i<=mx_a;++i)
			for(int j=0;j<=mx_b;++j)
				dp[d-1][i][j]
	}
}*/
int main()
{
	freopen("C:\\Users\\Administrator\\Desktop\\B-small-attempt0.in","r",stdin);
	freopen("C:\\Users\\Administrator\\Desktop\\D.txt","w",stdout);
	scanf("%d",&T);
	int A,B,K;
	int kase=1;
	while(T--)
	{
		scanf("%d%d%d",&A,&B,&K);
		A--;
		B--;
		K--;
		for(int i=0;i<32;++i)
		{
			a[i]=A&1;
			b[i]=B&1;
			k[i]=K&1;
			A>>=1;
			B>>=1;
			K>>=1;
		}
		int mx_a,mx_b;
		memset(dp,0,sizeof(dp));
		dp[32][0][0][1][1][1]=1;
		for(int i=32;i>0;--i)
			for(int a_=0;a_<2;++a_)
				for(int b_=0;b_<2;++b_)
					for(int fa=0;fa<2;++fa)
						for(int fb=0;fb<2;++fb)
						{
							if(dp[i][a_][b_][fa][fb][0])
							{
								//printf("%d %d %d %d %d 0\n",i,a_,b_,fa,fb);
								mx_a=(!fa)||a[i-1];
								mx_b=(!fb)||b[i-1];
								for(int j=0;j<=mx_a;++j)
									for(int g=0;g<=mx_b;++g)
										dp[i-1][j][g][fa&&j==mx_a][fb&&g==mx_b][0]+=dp[i][a_][b_][fa][fb][0];
							}
							if(dp[i][a_][b_][fa][fb][1])
							{
								//printf("%d %d %d %d %d 1\n",i,a_,b_,fa,fb);
								if(k[i-1])
								{
									mx_a=(!fa)||a[i-1];
									mx_b=(!fb)||b[i-1];
									for(int j=0;j<=mx_a;++j)
										for(int g=0;g<=mx_b;++g)
											dp[i-1][j][g][fa&&j==mx_a][fb&&g==mx_b][j&&g]+=dp[i][a_][b_][fa][fb][1];
								}
								else
								{
									mx_a=(!fa)||a[i-1];
									mx_b=(!fb)||b[i-1];
									for(int j=0;j<=mx_a;++j)
										for(int g=0;g<=mx_b;++g)
											if(!(j&&g))
												dp[i-1][j][g][fa&&j==mx_a][fb&&g==mx_b][1]+=dp[i][a_][b_][fa][fb][1];
								}
							}
						}
		ll ans=0;
		for(int a_=0;a_<2;++a_)
			for(int b_=0;b_<2;++b_)
				for(int fa=0;fa<2;++fa)
					for(int fb=0;fb<2;++fb)
						for(int fk=0;fk<2;++fk)
							ans+=dp[0][a_][b_][fa][fb][fk];
		printf("Case #%d: ",kase++);
		cout<<ans<<endl;
	}
}