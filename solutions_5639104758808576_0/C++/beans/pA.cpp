#include<bits/stdc++.h>
using namespace std;
const int maxk=1000+5;
char s[maxk];
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("outA","w",stdout);
	int T,kase=0;
	scanf("%d",&T);
	while(T--)
	{
		int k,ans=0,now=0;
		scanf("%d%s",&k,s);
		for(int i=0;i<=k;i++)
		{
			if(now<i) ans+=i-now,now=i;
			now+=s[i]-'0';
		}
		printf("Case #%d: %d\n",++kase,ans);
	}
}
