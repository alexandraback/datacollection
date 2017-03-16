#include<stdio.h>
#include<string.h>

int main()
{
	FILE *in,*out;
	int T,A,B,i,j,k,pos,flag;
	double p[100000];
	double result,temp,newresult=0;
	in=fopen("A-small-attempt0.in","r");
	out=fopen(" small0.txt","w");
	fscanf(in,"%d\n",&T);
	for(i=0;i<T;i++)
	{
		fscanf(in,"%d%d",&A,&B);
		printf("%d\n",i);
		for(j=0;j<A;j++)
		{
			fscanf(in,"%lf",&p[j]);
		}
		result=1;
	
		for(j=0;j<A;j++)
		{
			result*=p[j];
			if(result<0.000001)
			{
				result=0;
				break;
			}
		}
		result=result*(B-A+1)+(1-result)*(2*B-A+2);
		newresult=B+2;
		if(newresult<result)
		{
			result=newresult;
		}
		temp=1;
		flag=0;
		for(j=0;j<A;j++)
		{
			temp*=p[j];
			if(temp<0.000001)
			{
				temp=0;
				pos=j;
				flag=1;
				break;
			}
		}
		for(j=1;j<=A;j++)
		{
			temp=1;
			if(flag==1&&j>pos)
			{
				temp=0;
			}
			else
			{
				for(k=0;k<A-j;k++)
				{
					temp*=p[k];
				}
			}
			newresult=temp*(j+1+(B-(A-j)))+(1-temp)*(j+2+(2*B-(A-j)));
			if(newresult<result)
			{
				result=newresult;
			}
		}
		printf("Case #%d: %.6f\n",i+1,result);
		fprintf(out,"Case #%d: %.6f\n",i+1,result);
	}
	fclose(in);
	fclose(out);
	return 0;
}

