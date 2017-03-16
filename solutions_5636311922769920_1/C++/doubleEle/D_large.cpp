#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int k,c,s,T;

long long ksm(int a,int b)
{
	long long ret=1;
	while (b--) ret*=((long long) a);
	return ret;
}

int main()
{
//	freopen("D-large.in","r",stdin);
//	freopen("D-large.out","w",stdout);
	scanf("%d",&T);
	for (int e=1; e<=T; e++)
	{
		scanf("%d%d%d",&k,&c,&s);
		long long tmp=k/c+(k%c!=0);
		printf("Case #%d: ",e);
		if (tmp<=s)
		{
			long long x=0;
			for (int i=1; i<=tmp; i++)
			{
				long long y=0;
				for (int j=c; j>=1; j--)
				{
					y+=x*ksm(k,j-1);
					x++;
					if (x==k) x--;
				}
				printf("%I64d",y+1);
				if (i!=tmp) printf(" "); else printf("\n");
			}
		}
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
