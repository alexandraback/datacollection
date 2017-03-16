#include<stdio.h>

int noOfDigits(int A)
{
	int count=0;
	while(A>0)
	{
		A/=10;
		count++;
	}
	return count;
}

int myPow(int a,int b)
{
	int i,saveA=a;
	for(i=1;i<b;i++)
		a*=saveA;
	return a;
}

int recycle(int i,int j)
{
	int div,term;
	div=myPow(10,j);
	term=i%div;
	i=i/div;
	j=noOfDigits(i);
	div=myPow(10,j);
	i=i+term*div;
	//printf("\n\ndiv: %d,term: %d,j: %d",div,term,j);
	return i;
}

int main(int argc,char *argv[])
{
	FILE *fp,*fp1;
	int T,ite,A,B,i,len,j,newA,count,size,k,array[2000000],flag;
	fp=fopen(argv[1],"r");
	fp1=fopen("output.txt","w");
	fscanf(fp,"%d",&T);
	for(ite=1;ite<=T;ite++)
	{	
		count=0;
		fscanf(fp,"%d%d",&A,&B);
		for(i=A;i<B;i++)
		{
			size=0;
			len=noOfDigits(i);
			for(j=1;j<len;j++)
			{
				newA=recycle(i,j);
				//printf("\n\n\t(%d,%d)",i,newA,count);
				//getchar();
				if((noOfDigits(newA)==len)&&(newA>i)&&(newA<=B))
				{
					flag=0;
					for(k=0;k<size;k++)
					{
						if(array[k]==newA)
							flag=1;
					}
					if(flag!=1)
					{
						count++;
						array[size]=newA;
						size++;
					}
				}
			}
		}
		fprintf(fp1,"Case #%d: %d\n",ite,count);
	}
	return 1;
}
