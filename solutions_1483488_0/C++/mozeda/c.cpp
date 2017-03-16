#include <cstdio>

int main()
{
	int N, n, m;
	scanf("%d",&N);
	for (int I=1;I<=N;++I)
	{
		scanf("%d%d",&n, &m);
		int a[20], ans=0;;
		for (int i=n;i<=m;++i)
		{
			int b[10];
			int t=0,tt=0;
			int j=i;
			while (j!=0)
			{
				a[t++]=j%10;
				j/=10;
			}
			for (int j=t-2;j>=0;--j)
			{
				if (a[j]!=0)
				{
					int tmp=0;
					for (int k=0;k<t;++k)
						tmp=tmp*10+a[(j+t-k)%t];
					if (tmp>i && tmp<=m && tmp>=n)
					{
						bool pa=false;
						for (int k=0;k<tt;++k)
						  if (tmp==b[k])
						  {
								pa=true;
								break;
							}
						if (!pa)
						{
							++ans;
							b[tt++]=tmp;
						}
					}
				}
			}
		}
		printf("Case #%d: %d\n", I, ans);
	}
}
