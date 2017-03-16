#include<stdio.h>
#include<math.h>
int check(int a)
{
	int i,j;
	for(i=0;i<10;i++)
	{
		j=pow(2,i);	

		if(a==j)
		return 1;
	}
	
	return 0;
}
main()
{
	int T,t,i,j,p,q,c,r;
	float k;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		c=0;
		scanf("%d/%d",&p,&q);
		k=(float)p/(float)q;
		while(k<1)
		{
			c++;
			k=k*2;
			
		}
		
		if(c<=40)
		{
			r=check(q);
			if(r==1)
			printf("Case #%d: %d\n",t,c);
			
			else
			printf("Case #%d: impossible\n",t);
		}
	
		else
		printf("Case #%d: impossible\n",t);
	}

}

//printf("Case #%d: impossible");
