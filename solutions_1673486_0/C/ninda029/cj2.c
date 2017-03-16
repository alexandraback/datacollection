#include <stdio.h>

int main()
{
	int T,i;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		int A,B;
		scanf("%d",&A);
		scanf("%d",&B);
		double p[A];
		int j;
		for(j=0;j<A;j++)
		scanf("%lf",&p[j]);
		double min=100000000.0;
		double t1;
		t1=1.0;
		for(j=0;j<A;j++)
		t1*=p[j];
		double temp;
		temp=(2*B+2-A) + t1*(-B-1);
		if(temp<min) min=temp;
		if(min>(B+2))   min=B+2;
		int k;
		for(j=1;j<=A;j++)
		{ 
			t1=1;
			for(k=0;k<A-j;k++)
			t1*=p[k];
			temp=(2+2*j+2*B-A) + t1*(-B-1);
			if(temp<min)  min=temp;
		}
		printf("Case #%d: %lf\n",i,min);
	}
}	