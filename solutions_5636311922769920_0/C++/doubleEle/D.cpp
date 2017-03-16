#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k,s,c;
int main()
{
//	freopen("D-small-attempt0.in","r",stdin);
//	freopen("D-small-attempt0.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&k,&c,&s);
		printf("Case #%d: ",i);
		for(int j=1;j<=k;j++) printf("%d ",j);
		printf("\n");
	}
	return 0;
}
