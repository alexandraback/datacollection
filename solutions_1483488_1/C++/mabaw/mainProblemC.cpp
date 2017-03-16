#include <stdio.h>
#include <conio.h>
FILE *fin;
FILE *fout;

unsigned long ten[7] = {1,10,100,1000,10000,100000,1000000};
unsigned long save[100];
int countDigit(unsigned long d)
{
	int c=0;
	for(int i=0;d>0;d/=10)
	{
		c++;
	}

	return c;
}


unsigned long swapDigit(unsigned long d,int n,int maxDigit)
{
	unsigned long lastN = d % ten[n];
	unsigned long first = d / ten[n];
	unsigned long moveNum = first + lastN*ten[maxDigit-n];
	return moveNum;
}

int t,count;
unsigned long a,b;
int main(int argc, char* argv[])
{
	fin = fopen("C-large.in","r");
	fout = fopen("C-large.out","w");
	
	fscanf(fin,"%d",&t);
	for(int i=0;i<t;i++)
	{
		count=0;
		fscanf(fin,"%lu %lu",&a, &b);
		int digit = countDigit(a);
		for(unsigned long j=a;j<=b;j++)
		{
			int zz=0;
			for(int k=1;k<digit;k++)
			{
				unsigned long r = swapDigit(j,k,digit);
				for(int b=1;b<k;b++)
					if(save[b]==r) zz=1;
				save[k] = r;

				if(r>j&&r<=b&&zz==0) 
				{
					//fprintf(fout,"%lu %lu \n",j,r);
					count++;
				}
			}
		}

		fprintf(fout,"Case #%d: %d\n",i+1,count);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}