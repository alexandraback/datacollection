#include <cstdio>
#include <cstring>
const int N=1010;
int t[N][2],flag[N];
int main()
{
	int T,w=1,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&t[i][0],&t[i][1]);
		int now=0,ans=0;
		memset(flag,0,sizeof(flag));
		bool ok=true;
		while(ok)
		{
			ok=false;
			for(int i=1;i<=n;i++)
				if(flag[i]<=1&&t[i][1]<=now)
				{
					ok=true;
					now+=2-flag[i];
					flag[i]=2;
				}
			if(ok)continue;
			int max=-1,p=-1;
			for(int i=1;i<=n;i++)
				if(flag[i]==0 && now>=t[i][0] && t[i][1]>max)
				{
					max=t[i][1];
					p=i;
					ok=true;
				}
			if(p!=-1)
			{
				now++;ans++;
				flag[p]=1;
			}
		}
		if(now==2*n)
			printf("Case #%d: %d\n",w++,ans+n);
		else
			printf("Case #%d: Too Bad\n",w++);
	}
}
