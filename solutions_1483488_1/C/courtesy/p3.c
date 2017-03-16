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
int str1[8],str2[8],len;
long long int te[7],co;
int ln(long long int i)
{
	int r=0;
	while(i>0)
	{
		r++;
		i/=10;
	}
	return(r-1);
}
void conv(long long int i)
{
	int j,k;
	for(j=len;j>=0;j--)
	{
		str1[j]=i%10;
		i/=10;
	}
}
long long int get()
{
	long long int j=0;
	int i;
	for(i=0;i<=len;i++)
	{
		j+=str2[i];
		j=j*10;
	}
	j/=10;
	return(j);
}
int eq(long long int j)
{
	int i;
	for(i=0;i<=len;i++)
	{
		if(str1[i]!=str2[i])
		return(0);
	}
	return(1);
}
void sh()
{
	int i,j,k;
	i=str2[len];
	for(j=(len-1);j>=0;j--)
	str2[j+1]=str2[j];
	str2[0]=i;
}
int chk(long long int i,long long int m,long long int n)
{
	if(str1[0]==0)
	return(0);
	int j,k=0;
	for(j=0;j<=len;j++)
	str2[j]=str1[j];
	int ch;
	long long int f;
	co=-1;
	for(j=1;j<=len;j++)
	{
		sh();
		f=get();
		for(ch=0;ch<=co;ch++)
		{
			if(te[ch]==f)
			goto lst;
		}
		if((f>i)&&(f>=m)&&(f<=n))
		{
			k++;
			co++;
			te[co]=f;
		}
		lst:
		k+=0;
	}
	return(k);
}
void Main()
{
	long long int m,n,i;
	long int r=0,k;
	rlld(m);
	rlld(n);
	len=ln(m);
	if(len==0)
	goto end;
	for(i=m;i<=n;i++)
	{
		conv(i);
		k=chk(i,m,n);
		r+=k;
		if(k>0)
		printf("%lld:%ld\t",i,k);
	}
	end:
	fprintf(f2,"%ld",r);
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
//		printf("%d",i);
	}
	return(1);
}
