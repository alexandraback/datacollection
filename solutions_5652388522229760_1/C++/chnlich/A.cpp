#include<bits/stdc++.h>

using namespace std;

int T,x;
char s[100];
int cnt[10];

int main()
{
	freopen("A.in","r",stdin);
	
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	//for(x=1;x<=1000000;x++)
	{
		scanf("%d",&x);
		printf("Case #%d: ", tt);
		if (x==0)
		{
			printf("INSOMNIA\n");
			continue;
		}
		memset(cnt,0,sizeof cnt);
		int i;
		long long t;
		for(i=1;i<=100;i++)
		{
			t=1ll*x*i;
			sprintf(s,"%lld",t);
			int l=strlen(s);
			for(int j=0;j<l;j++)
				cnt[s[j]-48]=1;
			int tmp=0;
			for(int j=0;j<10;j++)
				tmp+=cnt[j];
			if (tmp==10)
			{
				printf("%lld\n", t);
				break;
			}
		}
		if (i>100)
			while(1);
			
	}
	return 0;
}

