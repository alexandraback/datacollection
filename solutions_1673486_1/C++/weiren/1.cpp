#include<stdio.h>
#include<string.h>

int main()
{
	FILE *in,*out;
	int T,A,B,i,j,k;
	double p[100];
	double result,temp,newresult=0;
	in=fopen("A-large.in","r");
	out=fopen("1ouL.txt","w");
	fscanf(in,"%d\n",&T);
	for(i=0;i<T;i++)
	{
		fscanf(in,"%d%d",&A,&B);
		for(j=0;j<A;j++)
		{
			fscanf(in,"%lf",&p[j]);
		}
		result=1;
		for(j=0;j<A;j++)
		{
			result*=p[j];
		}
		result=result*(B-A+1)+(1-result)*(2*B-A+2);
		newresult=B+2;
		if(newresult<result)
		{
			result=newresult;
		}
		for(j=1;j<=A;j++)
		{
			temp=1;
			for(k=0;k<A-j;k++)
			{
				temp*=p[k];
			}
			double wc1=temp*(j+1+(B-(A-j)));
			double wc2=(1-temp)*(j+2+(2*B-(A-j)));
			newresult=temp*(j+1+(B-(A-j)))+(1-temp)*(j+2+(2*B-(A-j)));
			if(newresult<result)
			{
				result=newresult;
			}
		}
		fprintf(out,"Case #%d: %.6f\n",i+1,result);
	}
	fclose(in);
	fclose(out);
	return 0;
}

