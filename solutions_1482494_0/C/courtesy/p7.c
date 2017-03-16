#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define fs fscanf
#define fp fprintf
#define rd(x) fscanf(f1,"%d",&x)
#define rld(x) fscanf(f1,"%ld",&x)
#define rlld(x) fscanf(f1,"%lld",&x)
#define rf(x) fscanf(f1,"%f",&x)
#define rlf(x) fscanf(f1,"%lf",&x)
#define rs(x) fscanf(f1,"%s",x)
FILE *f1,*f2;
int n,ar[1005][3],re,curs;
int finish()
{
	int i;
	for(i=0;i<n;i++)
	{
		if(ar[i][2]!=2)
		return(0);
	}
	return(1);
}
int Main()
{
	rd(n);
	int i,j,k;
	for(i=0;i<n;i++)
	{
		rd(ar[i][0]);
		rd(ar[i][1]);
		ar[i][2]=0;
	}
	curs=0;
	re=0;
	while(!finish())
	{
		k=0;
		for(i=0;i<n;i++)
		{
			if(ar[i][2]==0)
			{
				if(ar[i][1]<=curs)
				{
					re++;
					curs+=2;
					ar[i][2]=2;
					k=1;
					goto lst2;
				}
			}
		}
		k=0;
		for(i=0;i<n;i++)
		{
			if(ar[i][2]==1)
			{
				if(ar[i][1]<=curs)
				{
					re++;
					curs++;
					ar[i][2]=2;
					k=1;
					goto lst2;
				}
			}
		}
		k=0;
		for(i=0;i<n;i++)
		{
			if(ar[i][2]==0)
			{
				if(ar[i][0]<=curs)
				{
					re++;
					curs++;
					ar[i][2]=1;
					k=1;
					goto lst2;
				}
			}
		}
		fp(f2,"Too Bad");
		return(1);
		lst2:
		k=1;
	}				
	fp(f2,"%d",re);
	return(1);
}
int main()
{
	f1=fopen("/home/vivek/Desktop/s.in","r");
	f2=fopen("/home/vivek/Desktop/s.out","w");
	int cs,i;
	char c;
	fscanf(f1,"%d",&cs);
	for(i=1;i<=cs;i++)
	{
		fprintf(f2,"Case #%d: ",i);
		Main();
		c='\n';
		fputc(c,f2);
		printf("%d",i);
	}
	return(1);
}
