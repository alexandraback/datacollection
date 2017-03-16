#include<cstdio>
int T,N;
int main()
{
	freopen("in.txt","r",stdin); 
	freopen("out.txt","w",stdout); 
	scanf("%d",&T);
	int kase=1;
	while(T--)
	{
		scanf("%d",&N);
		int now=0,ans=0;
		for(int i=0;i<=N;i++)
		{
			char c;while(scanf("%c",&c))if(c>='0'&&c<='9')break;
			c-='0';
			if(now<i)ans+=i-now,now=i;
			now+=c;
		}
		printf("Case #%d: %d\n",kase++,ans);
	}
}
