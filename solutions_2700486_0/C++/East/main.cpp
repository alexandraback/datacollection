#include<stdio.h>

double diamond(int n, int x, int y)
{
	int r = (x+y)/2;
	int used = 1;
	int need = 0;
	while(n>used)
	{
		n-=used;
		used+=4;
		need++;
	}
	if(need>r)
		return 1.0;
	if(need<r)
		return 0.0;
	if(n==used)
		return 1.0;
	if(x==0)
		return 0.0;
	int maxheight = used/2;
	int count = 0;
	int chance = 0;
	int limit = 1;
	for(int i=0;i<n;i++)
		limit*=2;
	for(int i=0;i<limit;i++)
	{
		int ones = 0;
		int s = i;
		while(s>0)
		{
			ones+=(s%2);
			s/=2;
		}
		int zeros = n - ones;
		count++;
		if(ones>y || zeros>maxheight && ones+(zeros-maxheight)>y)
			chance++;
	}
	return (double)chance/count;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T,n,x,y;
	scanf("%d",&T);
	for(int c=1;c<=T;c++)
	{
		scanf("%d %d %d",&n,&x,&y);
		if(x<0) x=-x;
		if(y<0) y=-y;
		printf("Case #%d: %lf\n",c,diamond(n,x,y));
	}
	return 0;
}