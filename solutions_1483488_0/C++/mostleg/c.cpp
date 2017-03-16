#include <cstdio>
#include <cstring>


void work()
{
	int T,A,B;
	int cas,re;
	int i,j,k,top,w;
	int save[10],num;
	
	scanf("%d",&T);
	for (cas=1;cas<=T;cas++)
	{
		re=0;
		scanf("%d%d",&A,&B);
		for (i=A;i<B;i++)
		{
			for (top=1;top<B;top*=10);
			num=0;
			for (j=10;j<top;j*=10)
			{				
				k=i/j + i%j*(top/j);
				if (k<=B && k>i)
				{
					for (w=0;w<num;w++)
					{
						if (k == save[w])
							break;
					}
					if (w == num)
					{
						save[num++]=k;
						re++;
					}
				}
			}
		}
		printf("Case #%d: %d\n",cas,re);
	
	}
}

int main()
{
	//int i;
	
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	
	
	work();

	
	return 0;
}
