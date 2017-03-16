#include<cstdio>
#include<cmath>
int main()
{
	int n,a,b;
	scanf("%d",&n);
	for(int l=1;l<=n;l++)
	{
		scanf("%d %d",&a,&b);
		double* p=new double [a];
		for(int i=0;i<a;i++)scanf("%lf",&p[i]);
		int c=b-a+1;
		double sum=0,min=10000000,pp=1;
		for(int i=0;i<=a;i++)
		{
			sum=0;
			if(i<a)pp*=p[i];
			if(i==a)
			{
				if(a<b){if(min>double(b+2))min=double(b+2);}
				else{if(min>(1*pp+(1-pp)*double(b+2)))min=(1*pp+(1-pp)*double(b+2));}
			}
			else{
				sum=pp*double(b-i*2+a-1)+(1-pp)*double(2*b-2*i+a);
				if(sum<min)min=sum;
			}
		}
		printf("Case #%d: %lf\n",l,min);
	}
}
