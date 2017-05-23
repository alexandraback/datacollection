#include<stdio.h>


int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("sample.out", "w", stdout);
	
	int t,a,b;
	int i,j;
	double e=1;
	float p;
	double c1,c2,c3,minx;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d%d",&a,&b);
		e=1;
	
		for(j=0;j<a;j++){
			scanf("%f",&p);
			e *= p;
			c2 = (1-e)*(b+1) + (a-j-1) + b-j;
			if(j==0)minx=c2;
			else if( minx>c2)
				minx = c2;
		}
		c1 = b+2;
		if( minx>c1)minx = c1;
		printf("Case #%d: %.6f\n",i+1,minx);
		
	}

	return 0;
}