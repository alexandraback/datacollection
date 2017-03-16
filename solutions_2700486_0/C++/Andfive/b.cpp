#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int cas,n,xx,yy,knum,ksum;

void prework()
{
	int i=1,sum=1;
	while(sum<=n)
	{
		sum+=++i;
		sum+=++i;
	}
	sum-=i--;
	sum-=i--;
	knum=i;
	ksum=sum;
}

double work(int a,int b)
{
	 
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	scanf("%d",&cas);
	for(int ii=1;ii<=cas;++ii)
	{
		scanf("%d%d%d",&n,&xx,&yy);
		printf("Case #%d: ",ii);

		prework();

		if(n==ksum)
		{
			if(xx+yy<=knum/2*2 && yy-xx<=knum/2*2)
				puts("1.0");
			else
				puts("0.0");
		}
		else
		{
			if(xx+yy<=knum/2*2 && yy-xx<=knum/2*2)
				puts("1.0");
			else if(!(xx+yy<=(knum+1)/2*2 && yy-xx<=(knum+1)/2*2))
				puts("0.0");
			else
			{
				int num=n-ksum;
				knum+=2;
				if(num<knum)
				{
					if(yy>num-1)
						puts("0.0");
					else
						printf("%.7f\n",work(num,yy));
				}
				else
				{
					if(yy==knum-1)
						puts("0.0");
					else if(yy<=num-knum)
						puts("1.0");
					else
						printf("%.7f\n",work(knum-1,yy-num+knum-1));
				}
			}
		}
	}
	return 0;
}

