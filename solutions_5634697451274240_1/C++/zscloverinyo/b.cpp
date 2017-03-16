#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;

int T;
char s[200],ss[200];
int n,ans;
int main()
{
	freopen("b.in","r",stdin);
	freopen("bb.out","w",stdout);
	scanf("%d",&T);
	for (int z=1;z<=T;++z)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		ans=0;
		printf("Case #%d: ",z);
		for (int i=n;i>=1;--i)
		{
			if (s[i]=='+') continue;
			if (s[1]=='+')
			{
				for (int j=1;j<=i;++j) if (s[j]=='+') s[j]='-';else break;
				ans++;
			}
			for (int j=1;j<=i;++j) if (s[j]=='-') ss[j]='+';else ss[j]='-';
			for (int j=1;j<=i;++j) s[j]=ss[i-j+1];
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
