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
int ar[1000][1000];
int n,f[1000];
int p(int i,int j)
{
//	printf("p %d %d\n",i,j);
	int k,m,l;
	
	if(ar[i][j])
	return(1);
	for(k=0;k<n;k++)
	{
//		printf("p %d %d\n",ar[i][k],j);
		if(ar[i][k])
		{
		if(p(k,j))
		return(1);
		}
	}
	return(0);
}
int path2(int i,int j)
{
	
	int r=0,k,l,m;
	if(ar[i][j])
	r++;
	for(k=0;k<n;k++)
	{
		
		if(ar[i][k])
		{
		if(p(k,j))
		{
			r++;
			if(r==2)
			{
			//	printf("path2 %d %d y\n",i,j);
			return(1);
			}
		}
	//	else
		//printf("p %d %d n\n",k,j);
		}
	}
//	printf("path2 %d %d %dn\n",i,j,r);
	return(0);
}
int Main()
{
	rd(n);
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		ar[i][j]=0;
	}
	for(i=0;i<n;i++)
	{
		rd(f[i]);
		for(j=0;j<f[i];j++)
		{
			rd(k);
			ar[i][k-1]=1;
		}
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
//			printf("%d ",ar[i][j]);
			if(i!=j)
			{
			
			if(path2(i,j))
			{
	//			printf("i=%d j=%d\n",i,j);
				fp(f2,"Yes");
				return(1);
			}
			}
		}
	//	printf("\n");
	}
	fp(f2,"No");
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
