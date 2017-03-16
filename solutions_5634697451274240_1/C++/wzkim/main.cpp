#include <bits/stdc++.h>

using namespace std;

int cases=0,l,ans;
char a[105];

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("out","w",stdout);
	while(scanf("%d",&cases)!=EOF)
	{
		for(int t=1;t<=cases;t++)
		{
			scanf("%s",a+1);
			l=strlen(a+1);
			int cnt=l;
			while(a[cnt]=='+'&&cnt>0)
				cnt--;
			ans=0;
			for(int i=1;i<=cnt;i++)
				if(a[i]!=a[i-1]||i==1)
					ans++;
			printf("Case #%d: %d\n",t,ans);
		}
	}
	return 0;
}
