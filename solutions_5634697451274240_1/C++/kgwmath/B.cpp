#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

const int N=111;
int T,tc;
int n,t;
char s[N];

int main()
{
	int i,j;
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	for(scanf("%d",&T),tc=1;tc<=T;++tc)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		for(i=1;i<=n;++i)
			s[i]=(s[i]=='+'?0:1);
		t=0;
		for(i=n;i>=1;--i)
		{
			if(s[i])
			{
				++t;
				for(j=i;j>=1;--j)
					s[j]^=1;
			}

		}
		printf("Case #%d: %d\n",tc,t);
	}
	return 0;
}