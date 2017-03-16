#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int T,Case,C,D,V,i,j,k,ans;
long long now;
int a[1005];

int main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d",&T);
	for(;T;--T)
	{
		scanf("%d%d%d",&C,&D,&V);
		for(i=1;i<=D;++i)scanf("%d",&a[i]);
		sort(a+1,a+D+1);
		now=0;
		k=1;ans=0;
		for(;;)
		{
			for(;k<=D&&now+1>=a[k];++k)now+=(long long)C*a[k];
			if(now>=V)break;
			++ans;
			now+=(now+1)*C;
		}
		++Case;
		printf("Case #%d: %d\n",Case,ans);
	}
}
