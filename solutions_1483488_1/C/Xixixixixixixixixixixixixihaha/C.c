#include <stdio.h>
#include <stdlib.h>
#define false 0
#define true !false

typedef int bool;
int main(void)
{
    
    FILE *in, *out;
	int a = 1000000;
	int b = 2000000;
	int i, j, k, h, tmp;
	int check[10];
	bool flag;
	int A, T, B, t;
	int c = 0;
	int s = 1;
	int count = 0;
	
	
	in = fopen("C-large.in","r");
	out = fopen("out.txt","w");
	fscanf(in, "%d", &T);
	for(k=0;k < T;k++)
	{
		fscanf(in,"%d%d",&a,&b);
		count=0;
		t=a;
		s=1;
		c=0;
		while((t=t/10)!=0)c++;
		for(i=0;i < c;i++)
		{
			s*=10;
		}
		for(i=a;i <= b;i++)
		{	
			tmp=i;
			for(h = 0; h < c; h++)
			{
				check[h]=0;
			}
			for(j=0;j < c;j++)
			{
                
				t=tmp%10;
				tmp/=10;
				tmp=t*s+tmp;
				flag=true;
				if(tmp>i&&tmp <= b)
				{
					for(h = 0; h < c; h++)
					{
						if(tmp == check[h])
						{
							flag = false;
							break;
						}
					}
					if(flag)
					{
						check[j]=tmp;
						count++;
					}
				}
			}
		}
		fprintf(out,"Case #%d: %d\n",k+1,count);
	}
	fclose(in);
	fclose(out);
	return 0;
}
