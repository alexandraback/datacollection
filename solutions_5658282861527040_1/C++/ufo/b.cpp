#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a,b,k;
int xa[110],xb[110],xk[110],xxa,xxb,xxk;
long long dp[33][2][2][2];
void solve(int i,int i1,int i2,int i3,int j1,int j2)
{
	if(i1==0&&j1>xa[i])
		return;
	if(i2==0&&j2>xb[i])
		return;
	if(i3==0&&(j1&j2)>xk[i])
		return;
	int t1,t2,t3;
	if(i1||j1<xa[i])
		t1=1;
	else
		t1=0;
	if(i2||j2<xb[i])
		t2=1;
	else
		t2=0;
	if(i3||(j1&j2)<xk[i])
		t3=1;
	else
		t3=0;
	dp[i-1][t1][t2][t3]+=dp[i][i1][i2][i3];
}
int main()
{
	int t,tt,i,i1,i2,i3,i4,i5;
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&t);
	for(tt=1;tt<=t;++tt)
	{
		scanf("%d%d%d",&a,&b,&k);
		xxa=xxb=xxk=1;
		memset(xa,0,sizeof(xa));
		memset(xb,0,sizeof(xb));
		memset(xk,0,sizeof(xk));
		while(a)
		{
			xa[xxa]=(a&1);
			a>>=1;
			++xxa;
		}
		while(b)
		{
			xb[xxb]=(b&1);
			b>>=1;
			++xxb;
		}
		while(k)
		{
			xk[xxk]=(k&1);
			k>>=1;
			++xxk;
		}
		memset(dp,0,sizeof(dp));
		dp[31][0][0][0]=1;
		for(i=31;i;--i)
			for(i1=0;i1<=1;++i1)
				for(i2=0;i2<=1;++i2)
					for(i3=0;i3<=1;++i3)
						for(i4=0;i4<=1;++i4)
							for(i5=0;i5<=1;++i5)
								solve(i,i1,i2,i3,i4,i5);
		printf("Case #%d: %I64d\n",tt,dp[0][1][1][1]);
	}
	return 0;
}
