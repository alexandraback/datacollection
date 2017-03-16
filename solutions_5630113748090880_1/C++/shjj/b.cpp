//shjj-b
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int s[3000],n;

int main()
{
	freopen("B1.in","r",stdin);
	freopen("B1.out","w",stdout);
	int T,Tt=0;scanf("%d",&T);
	for (;T--;)
	{
		memset(s,0,sizeof(s));
		scanf("%d",&n);
		int nn=n*(n*2-1);
		for (int i=1;i<=nn;i++)
			{
				int x;scanf("%d",&x);
				s[x]^=1;
			}
		printf("Case #%d:",++Tt);
		for (int i=1;i<=2500;i++)
			if (s[i]) printf(" %d",i);
		puts("");
	}
}