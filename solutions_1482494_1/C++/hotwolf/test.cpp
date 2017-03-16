#include<stdio.h>
#include<algorithm>
int st[1001];
struct star{
	int one;
	int two;
}stars[1001];
int cmp(const void *a,const void *b)
{
	return (*(star*)b).two<(*(star*)a).two?1:-1;
}
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("out.out","w",stdout);
	int t,cas=0;
	scanf("%d",&t);
	while(t--)
	{
		printf("Case #%d: ",++cas);
		int n;
		int i,j;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d %d",&stars[i].one,&stars[i].two);
		qsort(stars,n,sizeof(stars[0]),cmp);
		int s=0,cnt=0;
		int x=n;
		while(x)
		{
			int t=s;
			int max=0;
			for(i=0;i<n;i++)
				if(stars[i].two<=s)
				{
					if(stars[i].one!=100000)
						s+=2;
					else
						s++;
					x--;
					cnt++;
					stars[i].two=100000;
				}
			if(t==s)
				for(i=n-1;i>=0;i--)
					if(stars[i].one<=s && stars[i].two!=100000)
					{
						s++;
						stars[i].one=100000;
						cnt++;
						break;
					}
			if(t==s)
				break;
		}
		if(x)
			printf("Too Bad\n");
		else
			printf("%d\n",cnt);
	}
	return 0;
}


