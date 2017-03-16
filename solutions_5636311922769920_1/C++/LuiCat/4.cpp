#include <cstdio>

typedef long long int64;

inline int64 deeper(int64 x, int k, int i)
{
	return x*k+i;
}

int main()
{
	int t,k,c,s;
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		scanf("%d%d%d",&k,&c,&s);
		if(c*s<k)
			printf("Case #%d: IMPOSSIBLE\n",i);
		else
		{
			printf("Case #%d:",i);
			for(int i=0;i<k;i+=c)
			{
				long long x=0;
				for(int j=0;j<c;++j)
					x=deeper(x,k,(i+j<k)?i+j:0);
				printf(" %lld",x+1);
			}
			printf("\n");
		}
	}
	return 0;
}

