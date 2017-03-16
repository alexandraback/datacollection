#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int p[7];
bool f;
int c2,c3,c5,r,n,m,k;

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int T;
	scanf("%d", &T);
	scanf("%d%d%d%d",&r,&n,&m,&k);
	printf("Case #1:\n");
	for (int ii = 1; ii <= r; ++ii)
	{
		f=false;
		c2=0;
		c3=0;
		c5=0;
		memset(p,0,sizeof(p));
		for (int i = 0; i < k; ++i)
		{
			scanf("%d",&p[i]);
		}
		for (int i = 0; i < k; ++i)
		{
			if(p[i]%125==0)
			{
				printf("555\n");
				f=true;
			}
			if(p[i]%27==0)
			{
				printf("333\n");
				f=true;
			}
			while(p[i]%2==0)
			{
				c2++;
				p[i]/=2;
			}
			while(p[i]%3==0)
			{
				c3++;
				p[i]/=3;
			}
			while(p[i]%5==0)
			{
				c5++;
				p[i]/=5;
			}

		}
		if(f)continue;
		if(c2!=0&&c3!=0&&c5!=0)
		{
			printf("235\n");
			continue;
		}
		if(c5!=0&&c3!=0&&c2==0)
		{
			if(c3>c5)printf("335\n");
			else printf("355\n");
			continue;
		}
		if(c3==0&&c5==0)
		{
			if(c2*2>35)
			{
				printf("444\n");
				continue;
			}
			if(c2*2>28)
			{
				printf("244\n");
				continue;
			}if(c2*2>21)
			{
				printf("224\n");
				continue;
			}
			printf("222\n");
			continue;
		}
		if(c2!=0&&c3!=0&&c5==0)
			{
				if(c3*2>7)
					if(c2<7)printf("233\n");
					else printf("334\n");
				else
				if(c2<14)printf("223\n");
					else printf("344\n");
				continue;
			}
		if(c2!=0&&c3==0&&c5!=0)
			{
				if(c5*2>7)printf("255\n");
				else printf("225\n");
				continue;
			}
		printf("234\n");
	}
	return 0;
}