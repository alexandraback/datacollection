#include <stdio.h>
typedef struct{
	int r1;
	int r2;
	int done1;
	int done2;
}level;

int main()
{
	int T,i;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
	int N;
	scanf("%d",&N);
	level l[N];
	int j;
	for(j=0;j<N;j++)
	{
		scanf("%d",&l[j].r1);
		scanf("%d",&l[j].r2);
	}
	for(j=0;j<N;j++)
	{
		l[j].done1=0;
		l[j].done2=0;
	}
	
	int temp=0;
	int k;
	int total=0;
	int star=0;
	int minlevel;
	int min=100000000;
	while(temp!=N)
	{
		min=100000000;
		for(k=0;k<N;k++)
		{
			if(l[k].r2<min && l[k].done2==0)  
			{
				min=l[k].r2;
				minlevel=k;
			}
		}
		if(min<=star)
		{
			temp++;
			total++;
			if(l[minlevel].done2==1)
			star=star+1;
			else star =star+2;
			l[minlevel].done2=1;
			continue;
		}
		
		min=100000000;
		for(k=0;k<N;k++)
		{
			if(l[k].r1<min && l[k].done1==0)  
			{
				min=l[k].r1;
				minlevel=k;
			}
		}
		if(min<=star)
		{
			l[minlevel].done1=1;
			star=star+1;
			total++;
			continue;
		}
		else break;
	}
	if(temp==N) printf("Case #%d: %d\n",i,total);
	else  printf("Case #%d: Too Bad\n",i);
	
}
}