#include<stdio.h>

int isbad(long mid, int n)
{
	int i, r=0, l=0;
	for(i=0;i<n;i++)
	{
		if(i&1)
			l+=(mid&(1<<i))>>i;
		else
			r+=(mid&(1<<i))>>i;
	}
	if(r==l)
		return 0;
	return 1;
}

void affiche(unsigned p)
{
	if(p==1)
	{
		printf("1");
		return;
	}
	affiche(p>>1);
	if(p%2)
		printf("1");
	else
		printf("0");
	return;
}

int main()
{
	int t, n, j, i, k, l;
	long p, mid;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		printf("Case #%d:\n",i+1);
		scanf("%d %d",&n,&j);
		p=(1<<(n-1))+1;
		mid=0;
		for(k=0;k<j;k++)
		{
			while(isbad(mid,n))
				mid++;
			affiche(p|(mid<<1));
			for(l=3;l<12;l++)
				printf(" %d",l);
			printf("\n");
			mid++;
		}
	}

	return 0;
}
