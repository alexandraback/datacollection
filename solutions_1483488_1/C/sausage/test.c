#include <stdio.h>
#include <math.h>
long num[8];
int num_index;
int main() {
	long i,len,k,m,t;
	long j,buf,min,max,count = 0;
	long r;
	int flag;
	FILE *in,*out;
	in = fopen("test.in","r");
	out = fopen("test.out","w");

	fscanf(in,"%ld",&t);
	for (i = 0; i < t; i++)
	{
		count = 0;
		fscanf(in,"%ld%ld",&min,&max);
		
		buf = min;
		len = 0;
		while (buf > 0)
		{
			buf /= 10;
			len++;
		}
		
		for (j = min; j <= max; j++)
		{
			buf = j;
			for (k = 1,num_index=0; k < len; k++)
			{
				r = buf%10;
				buf /= 10;
				buf += r*(long)pow((double)10,(int)(len-1));
				
				if ( buf > j && buf <= max)
				{
					for (m = 0,flag = 0; m < num_index; m++)
					{
						if (num[m] == buf)
						{
							flag = 1;
							break;
						}
					}
					if (flag == 0)
					{
						num[num_index++] = buf;
						count++;
					}
				}
			}
		}
		fprintf(out,"Case #%ld: %ld\n",i+1,count);		
	}
	
	//fprintf(out,"Case #%d: %d %d\n",count,i+1,j+1);
    return 0;	
}