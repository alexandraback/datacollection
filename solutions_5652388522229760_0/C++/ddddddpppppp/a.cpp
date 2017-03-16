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

int t,n,bz[10];
ll a;

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&t);
	fo(j,1,t)
	{
		memset(bz,0,sizeof(bz));
		scanf("%d",&n);
		if (!n)
		{
			printf("Case #%d: INSOMNIA\n",j);
			continue;
		}
		a=n;
		while (true)
		{
			ll tmp=a;
			while (tmp)
			{
				bz[tmp%10]=1;
			tmp/=10;
			}
			int flag=1;
			fo(i,0,9)
				if (!bz[i])
				{
					flag=0;
					break;
				}
			if (flag) break;
			a+=n;
		}
		printf("Case #%d: %lld\n",j,a);
	}
}