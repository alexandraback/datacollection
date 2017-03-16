#include<stdio.h>

double e[100000];

int main()
{
	int n,i;
	int a,b,j;
	double min;

	freopen("A-small-attempt1.in","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		min=b+2;

		for(j=0;j<a;j++)
			scanf("%lf",&e[j]);

		for(j=1;j<a;j++)
			e[j]*=e[j-1];


		for(j=0;j<a;j++)
			if(min>e[j]*((b-a)+2*(a-j-1)+1)+(1.0-e[j])*((b-a)+2*(a-j-1)+1+b+1))
				min=e[j]*((b-a)+2*(a-j-1)+1)+(1.0-e[j])*((b-a)+2*(a-j-1)+1+b+1);

		printf("Case #%d: %.6lf\n",i+1,min);
	}
}