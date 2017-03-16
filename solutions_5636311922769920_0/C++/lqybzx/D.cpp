#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);
	int T,K=0;
	scanf("%d",&T);
	while(T>0)
	{
		T--;
		K++;
		int k,c,s;
		scanf("%d%d%d",&k,&c,&s);
		printf("Case #%d: ",K);
		int i;
		for(i=1;i<=k-1;i++)
			printf("%d ",i);
		printf("%d\n",i);
	}
	return 0;
}
