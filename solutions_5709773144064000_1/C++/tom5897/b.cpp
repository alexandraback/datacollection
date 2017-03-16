#include<stdio.h>

int main()
{
	FILE *fi=fopen("input.txt","r");
	FILE *fo=fopen("output.txt","w");
	int i,l,n;
	double c,f,x,sum,sum2,min;

	fscanf(fi,"%d",&n);
	for(i=0;i<n;i++){
		fscanf(fi,"%lf %lf %lf",&c,&f,&x);

		sum = 0.0,sum2 = x/2, min = sum2;
		for(l=0;;l++){
			sum += c/(2+l*f);
			sum2 = sum+x/(double)(2+(l+1)*f);
			if(min > sum2)
				min = sum2;
			else break;
		}
		fprintf(fo,"Case #%d: %.7f\n",i+1,min);
	}
}