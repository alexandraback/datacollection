#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

#define fo(i,a,b) for (int i=a;i<=b;i++)
#define fd(i,a,b) for (int i=a;i>=b;i--)
	
typedef long long ll;

int t,ans;

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&t);
	fo(i,1,t)
	{
		ans=0;
		char c,la;
		while (c=getchar(),c!='-'&&c!='+');
		ans=1;
		la=c;
		while (c=getchar(),c=='-'||c=='+')
		{
			if (la!=c)
			{
				la=c;
				ans++;
			}
		}
		if (la=='+') ans--;
		printf("Case #%d: %d\n",i,ans);
	}
}