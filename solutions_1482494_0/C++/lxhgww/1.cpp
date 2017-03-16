#include<stdio.h>
#include<string.h>

int a[1001],b[1001];
bool u1[1001],u2[1001];

int main()
{
	int t,p;
	int n;
	int i,j;
	int res,s;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%d%d",&a[i],&b[i]);
		memset(u1,true,sizeof(u1));
		memset(u2,true,sizeof(u2));
		res=0;
		s=0;
		while (s<2*n)
		{
			for (i=1;i<=n;i++)
				if (u2[i]&&s>=b[i]) break;
			if (i<=n)
			{
				u2[i]=false;
				res++;
				if (u1[i]) s=s+2;
				else s++;
				continue;
			}
			j=0;
			int mm=0;
			for (i=1;i<=n;i++)
				if (u2[i]&&u1[i]&&s>=a[i]&&b[i]>mm)
				{
					mm=b[i];
					j=i;
				}
			if (j==0) break;
			s++;
			res++;
			u1[j]=false;
		}
		if (s<2*n) printf("Case #%d: Too Bad\n",p);
		else printf("Case #%d: %d\n",p,res);
	}
	return 0;
}
