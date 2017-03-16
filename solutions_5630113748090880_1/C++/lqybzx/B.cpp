#include<queue>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100001],q[100001];
int s[10001];
int main()
{
//	freopen("B-small-attempt0.in","r",stdin);
//	freopen("B-small-attempt0.out","w",stdout);
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int T;
	int k=0;
	scanf("%d",&T);
	while(T>0)
	{
		T--;
		k++;
		int n;
		scanf("%d",&n);
		int i,j;
		memset(s,0,sizeof(s));
		int x;
		for(i=1;i<=n*2-1;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&x);
				s[x]++;
			}
		}
		printf("Case #%d: ",k);
		int sx=0;
		for(i=1;i<=2500;i++)
		{
			if(s[i]%2==1&&sx!=n-1)
			{
				printf("%d ",i);
				sx++;
			}
			else if(s[i]%2==1)
			{
				printf("%d\n",i);
				sx++;
			}
		}
	}
	return 0;
}
