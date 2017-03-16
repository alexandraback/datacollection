#include <stdio.h>
#include <string.h>

#define N 2000001
int main()
{
	freopen("C-large.in","r",stdin);
	freopen("C.out","w",stdout);
	int time,A,B,cnt=0;
	int vis[N];
	scanf("%d",&time);
	for(int k=1;k<=time;++k)
	{
		scanf("%d%d",&A,&B);
		cnt=0;
		memset(vis,0,sizeof(vis));
		for(int j=A,t,num;j<=B;++j)
		{
			if(vis[j])continue;
			vis[j]=1;
			num=1;
			t=j;
			char lens[10];
			sprintf(lens,"%d",j);
			int len=strlen(lens),f=1;
			for(int i=0;i<len-1;++i)f*=10;
			for(int i=0;i<len-1;++i)
			{
				t=t%10*f+t/10;
				if(t>=A&&t<=B)
				{
					if(!vis[t])
					{
						vis[t]=1;
						++num;
					}
				}
			}
			cnt+=num*(num-1)/2;
		}
		printf("Case #%d: %d\n",k,cnt);
	}
}
