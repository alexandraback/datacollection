#include<stdio.h>
int main()
{
	int a=1000000;
	int b=2000000;
	int i,j,tmp,t,T,A,B,c=0,s=1,count=0;
	int check[10];
	bool flag;
	FILE *in,*out;
	in=fopen("C-small-attempt2.in","r");
	out=fopen("3out.txt","w");
	fscanf(in,"%d",&T);
	for(int k=0;k<T;k++)
	{
		fscanf(in,"%d%d",&a,&b);
		count=0;
		t=a;
		s=1;
		c=0;
		while((t=t/10)!=0)c++;
		for(i=0;i<c;i++)
		{
			s*=10;
		}
		for(i=a;i<=b;i++)
		{	
			tmp=i;
			for(int k=0;k<c;k++)
			{
				check[k]=0;
			}
			for(j=0;j<c;j++)
			{
				t=tmp%10;
				tmp/=10;
				tmp=t*s+tmp;
				flag=true;
				if(tmp>i&&tmp<=b)
				{
					for(int k=0;k<c;k++)
					{
						if(tmp==check[k])
						{
							flag=false;
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
	fclose(out);
	return 0;
}