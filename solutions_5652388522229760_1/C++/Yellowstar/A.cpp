#include<cstdio>
#include<cstring>
using namespace std;
const int ALL=(1<<10)-1;
inline long long f(const long long& n)
{
	int i,exi=0,l;
	long long ans=n;
	char str[22];
	while(true)
	{
		sprintf(str,"%lld",ans);
		l=strlen(str);
		while(l--)
		{
			exi|=(1<<(str[l]-'0'));
		}
		if(exi==ALL)
		{
			return ans;
		}
		ans+=n;
	}
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T,n,cas=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		printf("Case #%d: ",++cas);
		if(n==0)
		{
			puts("INSOMNIA");
		}
		else
		{
			printf("%lld\n",f(n));
		}
	}
	return 0;
}
/*
5
0
1
2
11
1692
*/

