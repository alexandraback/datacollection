#include<stdio.h>
#include<stdlib.h>
int main()
{ 
	int t,n,s,p,tl,i,op,j;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d %d %d",&n,&s,&p);
		op=0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&tl);
			if(tl>=3*p-2)
			op=op+1;
			else if(s>0 && (tl>=(3*p)-4) && ((tl>0)||p==0))
			{
				op=op+1;
				s=s-1;
			}
 
		}
		printf("Case #%d: %d\n",i,op);
 	}
return 0;
}
