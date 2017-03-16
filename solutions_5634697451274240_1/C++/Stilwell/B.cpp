#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int T,n,i,j,k,Case,ans;
char s[100005];

int main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d",&T);
	for(;T;--T)
	{
		scanf("%s",s+1);n=strlen(s+1);++Case;
		ans=0;
		for(i=2;i<=n;++i)if(s[i]!=s[i-1])++ans;
		if(s[n]=='-')++ans;
		printf("Case #%d: %d\n",Case,ans);
	}
}
