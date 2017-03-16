#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int k,c,s,test;
int main()
{
	freopen("D-large.in","r",stdin);
	freopen("D2.out","w",stdout);
	cin>>test;
	for (int nmb=1;nmb<=test;nmb++)
	{
		printf("Case #%d: ",nmb);
		scanf("%d%d%d",&k,&c,&s);
		if (s*c<k) printf("IMPOSSIBLE\n");
		else 
		{
			for (int i=1;i<=k;i+=c)
			{
				long long ans=i;
				for (int j=i+1;j<i+c;j++)
				ans=(ans-1)*k+min(j,k);
				printf("%lld ",ans);
			}
			printf("\n");
		}
	}
	return 0;
}
