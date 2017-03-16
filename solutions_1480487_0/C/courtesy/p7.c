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
void Main()
{
	int n,i,j,k;
	long long int s,s1,s2;
	double ar[200],t1,t2,t3;
	rd(n);
	k=n;
	s=0;
	for(i=0;i<n;i++)
	{
		rlf(ar[i]);
		s+=ar[i];
	}
	s1=s;
	s*=2;
	t1=(double)s/n;
	j=0;
	s2=0;
	k=0;
	for(i=0;i<n;i++)
	{
		if(ar[i]>t1)
		{
			j++;
		}
		else
		{
			s2+=ar[i];
			k++;
		}
	}
	if(j==0)
	{
		
	for(i=0;i<n;i++)
	{
		t2=t1-ar[i];
		if(t2<0)
		{
		fp(f2,"%lf ",0.0);
		continue;
		}
		t2*=100;
		t2/=s1;
		fp(f2,"%lf ",t2);
	}
	}
	else
	{
//		printf("k=%d s1=%lld ",k,s1);
		s2+=s1;
		t2=(double)s2/k;
	//	printf("s2=%lld t2=%lf ",s2,t2);
		for(i=0;i<n;i++)
		{
			if(ar[i]>t2)
			fp(f2,"%lf ",0.0);
			else
			{
				t3=t2-ar[i];
				t3*=100;
				t3/=s1;
				fp(f2,"%lf ",t3);
			}
		}
	}
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
