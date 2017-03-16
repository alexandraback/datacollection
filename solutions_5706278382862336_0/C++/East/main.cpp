#include<stdio.h>

int elf(int a, int b)
{
	if(a==b)
		return 1;
	if(a>b)
		return -1;
	int iter = 0;
	int min = -1;
	while(a!=b && iter<40)
	{
		iter++;
		a*=2;
		if(a==b)
		{
			if(min==-1)
				min=iter;
		}
		if(a>b)
		{
			a-=b;
			if(min==-1)
				min=iter;
		}
	}
	if(a==b)
		return min;
	return 0;
}

void main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T,a,b;
	scanf("%d",&T);
	for(int cs=1;cs<=T;cs++)
	{
		scanf("%d/%d",&a,&b);
		int iter = elf(a,b);
		if(iter>0)
			printf("Case #%d: %d\n",cs,iter);
		else
			printf("Case #%d: impossible\n",cs);
	}
}