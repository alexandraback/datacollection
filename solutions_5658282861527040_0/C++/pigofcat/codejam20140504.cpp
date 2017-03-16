#include<stdio.h>

int main()
{
	freopen("F:\\B-small-attempt0.in","r",stdin);
	freopen("F:\\B_small-out.txt","w",stdout);
	int a,b,k,i,j,cnt,t,tt;
	scanf("%d",&t);
	for(tt=1;tt<=t;++tt)
	{
		scanf("%d %d %d",&a,&b,&k);
		cnt=0;
		for(i=0;i<a;++i)
			for(j=0;j<b;++j)
				if((i&j)<k)
					++cnt;
		printf("Case #%d: %d\n",tt,cnt);
	}
	return 0;
}