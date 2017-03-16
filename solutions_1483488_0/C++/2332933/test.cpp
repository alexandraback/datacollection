#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define swap(a,b) a=a^b,b=a^b,a=a^b

int dig(int n)
{
	return n>=10?1+dig(n/10):1;
}

int pow10(int n)
{
	int ans=1;
	while (n-->0)
		ans*=10;
	return ans;
}

int main()
{
//	freopen("1.txt", "r", stdin);
//	freopen("2.txt", "w", stdout);

	int i,j;
	int T;
	int a,b,tmp,l,p;
	scanf("%d",&T);
	__int64 ans;

	for (i=1;i<=T;i++)
	{
		scanf("%d%d",&a,&b);
		ans=0;
		for (j=a;j<=b;j++)
		{
			tmp=j;
			l=dig(j);
			p=pow10(l-1);
			do
			{
				tmp=tmp%p*10+tmp/p;
				if (tmp<=b && tmp>j)
					ans++;
			}while (tmp!=j);
		}
		printf("Case #%d: %I64d\n",i,ans);
	}

	return 0;
}