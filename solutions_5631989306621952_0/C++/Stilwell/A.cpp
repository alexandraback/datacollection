#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int T,Case,n,i,j,k,l,r;
char s[100005],ans[100005];

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for(;T;--T)
	{
		scanf("%s",s+1);n=strlen(s+1);
		l=1;r=n;
		for(i=n;i>=1;i=k-1)
		{
			k=i;
			for(j=i;j>=1;--j)if(s[j]>s[k])k=j;
			for(j=i;j>k;--j)ans[r]=s[j],--r;
			ans[l]=s[k];++l;
		}
		++Case;printf("Case #%d: ",Case);
		for(i=1;i<=n;++i)printf("%c",ans[i]);
		printf("\n");
	}
}
