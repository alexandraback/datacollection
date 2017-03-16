/*
#include <stdio.h>

int checkint(int a,int b)
{
	
	int i,j=0,z,num;
	int re=0;

	if(a<10) return 0;
	i=1;
	while(1)
	{
		if(i>a)
		{
			i/=10;
			j--;
			break;
		}
		i*=10;
		j++;
	}
	z=10;
	for(j;j>0;j--)
	{
		num=(a%i)*z+(a/i);
		if(num==b)
			return 1;
		i/=10;
		z*=10;
	}
	return 0;
}

int main()
{
	int t,tcase;
	int a,b,i,j,re,cp;

	FILE *in,*out;
	in=fopen("input.txt","r");
	out=fopen("output.txt","w");

	fscanf(in,"%d",&tcase);
	for(t=0;t<tcase;t++)
	{
		fscanf(in,"%d%d",&a,&b);
		re=0;
		for(i=a;i<=b;i++)
		{
			cp=0;
			for(j=i+1;j<=b;j++)
			{
				if(checkint(i,j)==1)
				{
					re++;
					cp++;
				}
			}
			fprintf(out,"i=%d %d\n",i,cp);
		}
		fprintf(out,"Case #%d: %d\n",t+1,re);
	}

	return 0;
}
*/

#include <stdio.h>

int countt(int x,int mx)
{
	int i,j=0,z,num,p;
	int re=0,check[12],cnt=0;

	if(x<10) return 0;
	i=1;
	while(1)
	{
		if(i>x)
		{
			i/=10;
			j--;
			break;
		}
		i*=10;
		j++;
	}
	z=10;
	for(j;j>0;j--)
	{
		num=(x%i)*z+(x/i);
		if(num<=mx && x<num)
		{
			for(p=0;p<cnt;p++)
			{
				if(check[p]==num)
					break;
			}
			if(p==cnt)
			{
				re++;
				check[cnt++]=num;
			}
		}
		i/=10;
		z*=10;
	}
	return re;
}

int main()
{
	int t,tcase;
	int a,b,i,re;

	FILE *in,*out;
	in=fopen("C-large.in","r");
	out=fopen("output.txt","w");

	fscanf(in,"%d",&tcase);
	for(t=0;t<tcase;t++)
	{
		fscanf(in,"%d%d",&a,&b);
		re=0;
		for(i=a;i<=b;i++)
			re+=countt(i,b);
		fprintf(out,"Case #%d: %d\n",t+1,re);
	}

	return 0;
}

