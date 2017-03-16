#include<stdio.h>
#define A_max 100000
double p[A_max],key[A_max+2];
int a,b;
main()
{
//	freopen("A.in","r",stdin);
//	freopen("A.txt","w",stdout);
	
	int testcase,t,i,j;
	double k,poss;
	p[0]=1;
	scanf("%d",&testcase);
	for(t=1;t<=testcase;t++)
	{
		scanf("%d %d",&a,&b);
		for(i=1;i<=a;i++) scanf("%lf",p+i);
		poss=1.0;
		for(i=1;i<=a;i++) poss=poss*p[i]; 
		for(i=0;i<=a;i++)
		{
			key[i]=(1-poss)*(b+1)+(i+i+b-a+1);
			poss=poss/p[a-i];
		}
		key[a+1]=b+2;
		k=100000000;
		for(i=0;i<=a+1;i++)
			if(key[i]<k) k=key[i];
		printf("Case #%d: %.6lf\n",t,k);
	}
}
