#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int t,n,a[100],b[100],d;

main()
{
	int i,j,k;
	scanf("%*d");
	while(~scanf("%d%d",&d,&n))
	{
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n);
		if(d==1)
		{
			printf("Case #%d: %d\n",++t,n);
			continue;
		}
		for(i=k=0;i<n;i++)
		{
			j=0;
			if(d>a[i]) d+=a[i];
			else
			{
				while(d<=a[i])
				{
					d<<=1;
					d--;
					j++;
				}
				d+=a[i];
			}
			b[i]=j;
			k+=j;
		}
		for(i=n-1,j=k;i>-1;i--)
		{
			j=j-b[i]+1;
			k=j<k?j:k;
		}
		printf("Case #%d: %d\n",++t,k);
	}
}
