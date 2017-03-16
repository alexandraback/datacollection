#include <memory.h>
#include <stdio.h>
long long A[32],B[32],K[32];
long long Dp[32][2][2][2];
bool Chk[32][2][2][2];
long long dp(int len,int af,int bf,int cf)
{
	if (len>=32) return 1;
	if (Chk[len][af][bf][cf]) return Dp[len][af][bf][cf];
	Chk[len][af][bf][cf]=1;
	Dp[len][af][bf][cf]=0;
	for (int a=0;a<=af || a<=A[len];a++)
		for (int b=0;b<=bf || b<=B[len];b++)
		{
			int c = a&b;
			if (c<=K[len] || cf)
			{
				long long calc = dp(len+1, af || (a<A[len]),
				                    	   bf || (b<B[len]),
				                    	   cf || (c<K[len]));
				//printf("%d %d %d %d, %d %d get%lld\n",len,af,bf,cf,a,b,calc);
				Dp[len][af][bf][cf]+=calc;
			}
		}
	return Dp[len][af][bf][cf];
}
int main()
{
	int T;scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		int a,b,k;
		scanf("%d %d %d",&a,&b,&k);
		a--;b--;k--;
		for (int i=31;i>=0;i--)
		{
			A[i]= (a&1);
			B[i]= (b&1);
			K[i]= (k&1);
			a>>=1;
			b>>=1;
			k>>=1;
		}
		memset(Chk,0,sizeof(Chk));
		printf("Case #%d: %lld\n",kase,dp(0,0,0,0));
	}
	return 0;
}