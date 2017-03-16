#include<cstdio>
#include<cstring>
using namespace std;
int num[2502];
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int T,n,i,j,t,cas=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(num,0,sizeof(int)*2501);
		for(i=(n<<1)-1;i>0;--i)
		{
			for(j=0;j<n;++j)
			{
				scanf("%d",&t);
				++num[t];
			}
		}
		
		printf("Case #%d:",++cas);
		for(i=1;i<=2500;++i)
		{
			if(num[i]&1)
			{
				printf(" %d",i);
			}
		}
		putchar('\n');
	}
	return 0;
}
/*
1
3
1 2 3
2 3 5
3 5 6
2 3 4
1 2 3
*/

