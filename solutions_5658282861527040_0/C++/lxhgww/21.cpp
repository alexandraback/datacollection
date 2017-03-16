#include<stdio.h>

int main()
{
	int t,p;
	int a,b,c;
	int i,j;
	int res;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d%d%d",&a,&b,&c);
		res=0;
		for (i=0;i<a;i++)
			for (j=0;j<b;j++)
				if ((i&j)<c) res++;
		printf("Case #%d: %d\n",p,res);
	}
	return 0;
}