#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;


bool a[10];
int cnt,T,n,i;
int main()
{
//	freopen("A-small-attempt0.in","r",stdin);
//	freopen("A-small-attempt0.out","w",stdout);
	scanf("%d",&T);
	for (int j=1;j<=T;j++)
	{
		scanf("%d",&n);
		printf("Case #%d: ",j);		
		if (n==0) 
		{
			printf("INSOMNIA\n");
			continue;
		}
		cnt=0;
		memset(a,0,sizeof(a));
		for (int i=1;;i++)
		{
			int u=i*n;
			while (u)
			{
				if (a[u%10]==0) cnt++;
				a[u%10]=1;
				if (cnt==10)
				{
					printf("%d\n",i*n);
					break;
				}
				u/=10;
			}
			if (cnt==10) break;
		}
	}
	return 0;
} 
