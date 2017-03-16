#include <iostream>
#include <cstdio>
using namespace std;
long long T,tt,k,c,s,anss,i,flag,tmp,K;
int main(){
	freopen("temp.in","r",stdin);
	freopen("temp.out","w",stdout);
	scanf("%lld",&T);
	for (tt = 1;tt <= T;tt++)
	{
		printf("Case #%lld: ",tt);
		scanf("%lld%lld%lld",&k,&c,&s);
		anss = 1;
		for (i = 1;i<=c;i++)
		{
			anss*=k;
		}
		if (s*c<k) printf("IMPOSSIBLE");
		else
		{
			tmp = 1; 
			for (i = 1;i <= k;i++)
			{
				tmp = (tmp - 1) * k + i;
				if (i % c ==0)
				{
					printf("%lld ",tmp);
					tmp = 1;
				}
			}
			flag = 0;
			K = k;
			while (K % c != 0)
			{
				flag = 1;
				tmp = (tmp - 1) * k +1;
				K++;
			}
			if (flag == 1) printf("%lld ",tmp);
		}
		printf("\n");
	}
}
