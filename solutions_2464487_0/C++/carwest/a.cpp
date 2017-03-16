#include<stdio.h>

#define p(x) (x)*(x)

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T;
	scanf("%d",&T);
	for ( int tt=1;tt<=T;tt++ )
	{
		printf("Case #%d:",tt);
		int r,t;
		scanf("%d%d",&r,&t);
		int ans=0;
		while ( t> 0 ) {
			if ( t >= (p(r+1)-p(r)) ) ans++;
			t-=p(r+1)-p(r);
			r+=2;
		}
		printf(" %d\n",ans);
	}
	return 0;
}
