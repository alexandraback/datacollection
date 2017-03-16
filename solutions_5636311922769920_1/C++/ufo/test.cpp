#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
long long k,c,s,x;
int main()
{
	freopen("D-large.in","r",stdin);
	freopen("D-large.out","w",stdout);
	int t,tt;
	int i,j;
	scanf("%d",&tt);
	for(t=1;t<=tt;++t)
	{
		scanf("%lld%lld%lld",&k,&c,&s);
		if((k+c-1)/c>s)
			printf("Case #%d: IMPOSSIBLE\n",t);
		else
		{
			printf("Case #%d: ",t);
			for(i=1;(i-1)*c<k;++i)
			{
				x=0;
				for(j=(i-1)*c+1;j<=i*c;++j)
					if(j<=k)
						x=x*k+(j-1);
					else
						x=x*k+k-1;
				printf("%lld ",x+1);
			}
			puts("");
		}
	}
	return 0;
}
