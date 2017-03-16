#include<bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define mod 1000000007
#define bitcount __builtin_popcountll
#define ll long long
int main()
{
	int i,j,k,x;
	int t,n;
	freopen("A-large(1).in","r",stdin);
	freopen("output.txt","w",stdout);
	char s[5000],ans[5000];
	sd(t);
	for(x=1;x<=t;x++)
	{
		ss(s);
		n=strlen(s);
		ans[1000]=s[0];
		i=999;
		j=1001;
		for(k=1;k<n;k++)
		{
			if(s[k]<ans[i+1])
			{
				ans[j]=s[k];
				j++;
			}
			else
			{
				ans[i]=s[k];
				i--;
			}
		}
		printf("Case #%d: ",x );
		for(k=i+1;k<j;k++)
		{
			printf("%c",ans[k]);
		}
		printf("\n");
	}
	return 0;
}