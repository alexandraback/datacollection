#include <stdio.h>

int main()
{
	int tc=0,a,b,k,i,j,l;
	scanf("%d",&a);
	while (scanf("%d %d %d",&a,&b,&k)==3)
	{
		l=0;
		for (i=0;i<a;++i) for (j=0;j<b;++j) if ((i&j)<k) ++l;
		printf("Case #%d: %d\n",++tc,l);
	}
	return 0;
}
