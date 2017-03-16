#include <stdio.h>
#include <istream>
#include <string.h>

#define abs(a,b) a>b? a-b : b-a
FILE *fs,*fp;
int main()
{
	fs=fopen("input.in","rt");
	fp=fopen("output.out","wt");

	int n,a,b,c;

	fscanf(fs,"%d\n",&n);

	for(int i=0;i<n;i++)
	{
		fscanf(fs,"%d %d %d",&a,&b,&c);
		
		int min=a*b+1;
		int stone,num_st;
		for(int j=1;j<=a;j++)
		{
			for(int t=1;t<=b;t++)
			{
				if(j<=2||t<=2)
				{
					stone=t*j;
					if(stone>=c&&min>=stone)
					{
						min=stone;
					}
					if(stone+1>=c&&min>=stone+1)
					{
						min=stone+1;
					}
				}
				if(t<a-1&&j<b-1)
				{
					stone=t*2+j*2;
					if(stone+t*j>=c&&min>stone)
					{
						min=stone;
					}if(stone+t*j+1>=c&&min>stone+1)
					{
						min=stone+1;
					}if(stone+t*j+2>=c&&min>stone+2)
					{
						min=stone+2;
					}if(stone+t*j+3>=c&&min>stone+3)
					{
						min=stone+3;
					}if(stone+t*j+4>=c&&min>stone+4)
					{
						min=stone+4;
					}
				}
			}
		}
		fprintf(fp,"Case #%d: %d\n",i+1,min);
	}

	fclose(fs);
	fclose(fp);
	return 0;
}