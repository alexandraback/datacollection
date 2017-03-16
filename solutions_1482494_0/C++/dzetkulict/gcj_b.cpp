#include <stdio.h>
#include <string.h>

int main()
{
	int a[1000],b[1000];
	int _cn,_cc,i,j,k,m,n,s;
	scanf("%d",&_cn);
	for (_cc=1;_cc<=_cn;++_cc)
	{
		scanf("%d\n",&n);
		for (i=0;i<n;++i) scanf("%d %d",a+i,b+i);
		s=k=0;
		while (n)
		{
			++k;
			m=j=-1;
			for (i=0;i<n;++i)
			{
				if (s>=b[i]) break;
				if (a[i]!=-1 && s>=a[i] && b[i]>m)
				{
					m=b[i];
					j=i;
				}
			}
			if (i<n)
			{
				++s;
				if (a[i]!=-1) ++s;
				a[i]=a[n-1];
				b[i]=b[n-1];
				--n;
			} else
			{
				if (j==-1) break;
				++s;
				a[j]=-1;
			}
		}
		
		printf("Case #%d: ",_cc);
		if (n) printf("Too Bad\n"); else printf("%d\n",k);
	}
	return 0;
}
