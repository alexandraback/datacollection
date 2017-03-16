#include <stdio.h>
#include <stdlib.h>

float result(long a, long b)
{
	float* prob = (float*)malloc(a*sizeof(float));
	int i,j;
	float p = 1;
	float enterv = b+2;
	
	for(i=0;i<a;i++)
	{
		scanf("%f",&prob[i]);
		p = p*prob[i];
	}
		
	float* res = (float*)malloc((a+1)*sizeof(float));
	
	for(j=0;j<=a;j++)
		res[a] = 0;
		
	for(i=a; i>=0; i--)
	{

		res[a-i] = (a-i) + p*(float)(b-i+1) + (1-p)*(float)(b+b-i+2);		
		if(i!=0)
			p = p/prob[i-1];
	}
	
	float min = enterv;
	for(i=0;i<=a;i++)
	{
		if(res[i]<min)
			min = res[i];
	}
	
	return min;
	
}

int main()
{

	int t,n;
	long a,b;
	scanf("%d",&t);
	
	int i,j,k;
	float res;
	
	for(j=0;j<t;j++)
	{
		scanf("%ld",&a);
		scanf("%ld",&b);
		res = result(a,b);
		
		printf("Case #%d: %f\n",j+1,res);
	}
	
	return 0;
}
