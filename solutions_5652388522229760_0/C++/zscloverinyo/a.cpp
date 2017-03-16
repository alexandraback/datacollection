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
bool f[20];
bool flag;
int n,now,dq;
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	for (int z=1;z<=T;++z)
	{
		printf("Case #%d: ",z);
		scanf("%d",&n);
		memset(f,false,sizeof(f));
		if (n==0)
		{
			printf("INSOMNIA\n");
			continue;
		}
		now=n;
		while (1)
		{
			dq=now;
			while (dq)
			{
				f[dq%10]=true;
				dq/=10;
			}
			flag=true;
			for (int i=0;i<=9;++i) if (f[i]==false) flag=false;
			if (flag) break;
			now+=n;
		}
		printf("%d\n",now);
	}
	return 0;
}
