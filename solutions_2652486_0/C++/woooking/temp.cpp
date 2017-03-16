
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

int cases;

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("C-small-1-attempt2.in","r",stdin);
	freopen("C-small-1-attempt2.out","w",stdout);
	scanf("%d",&cases);
	printf("Case #1:\n");
	int r,n,m,k;
	scanf("%d%d%d%d",&r,&n,&m,&k);
	while(r--)
	{
		int a[3];
		a[0]=0;a[1]=0;a[2]=0;
		int j=0;
		int v[7];
		for(int i=0;i<k;++i)scanf("%d",&v[i]);
		std::sort(v,v+7,cmp);
		for(int i=0;i<k;++i)
		{
			int pro=v[i];
			for(int l=0;l<3;++l)if(a[l]!=0 && pro%a[l]==0)pro/=a[l];
			while(j<2&&a[j]!=0)++j;
			if(j==3)continue;
			while(pro%3==0)
			{
				a[j++]=3;
				pro/=3;
			}
			while(pro%5==0)
			{
				a[j++]=5;
				pro/=5;
			}
			while(pro%4==0)
			{
				a[j++]=4;
				pro/=4;
			}
			while(pro%2==0)
			{
				a[j++]=2;
				pro/=2;
			}
			std::sort(a,a+j,cmp);
		}
		if(j!=3)
		{
			for(int k=0;k<j;++k)
			{
				if(a[k]==4)
				{
					a[k]=2;
					a[j++]=2;
					if(j==3)break;
				}
			}
		}
		while(j!=3)a[j++]=2;
		for(int j=0;j<3;++j)printf("%d",a[j]);
		printf("\n");
	}
}