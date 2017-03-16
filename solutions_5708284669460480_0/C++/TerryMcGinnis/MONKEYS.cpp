#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

inline int fast_input(void)
{
	char t;
	int x=0;
	int neg=0;
	t=getchar();
	while((t<48 || t>57) && t!='-')
		t=getchar();
	if(t=='-')
		{neg=1; t=getchar();}
    while(t>=48 && t<=57)
    {
        x=(x<<3)+(x<<1)+t-48;
        t=getchar();
    }
	if(neg)
		x=-x;
	return x;
}

inline void fast_output(int x)
{
	char a[20];
	int i=0,j;
	a[0]='0';
	if (x<0) {putchar('-'); x=-x;}
	if (x==0) putchar('0');
	while(x)
	{
		a[i++]=x%10+48;
		x/=10;
	}
	for(j=i-1;j>=0;j--)
	{
		putchar(a[j]);
	}
	putchar('\n');
}

int finder(char x[8], char y[8])
{
	int a=strlen(x),b=strlen(y),i,ans=0,j,flag;
	for(i=0;i<b-a+1;i++)
	{
		flag=0;
		for(j=0;j<a;j++) if (x[j]!=y[j+i]) {flag=1; break;}
		if (!flag) ans++;
	}
	return ans;
}

int main()
{
int t,i,k,l,s,j,num,ispa[26],ispb[26],disa,x,jc,n,max,flag;
char a[8],b[8],dis[8],gen[8];
double ans,prob;
t=fast_input();
for(i=1;i<=t;i++)
{
flag=0;
memset(ispa,0,sizeof(ispa));
memset(ispb,0,sizeof(ispb));
k=fast_input();
l=fast_input();
s=fast_input();
scanf("%s",a);
scanf("%s",b);
ans=0.0;
disa=0;
for(j=0;j<k;j++)
{
	if (ispa[a[j]-'A']==0)
	{
		disa++;
		dis[disa-1]=a[j];
	}
	ispa[a[j]-'A']++;
}
for(j=0;j<l;j++) ispb[b[j]-'A']=1;
for(j=0;j<26;j++) if (ispa[j]==0&&ispb[j]==1) {flag=1; break;}
if (flag) {printf("Case #%d: 0.0\n",i); continue;}
num=1;
for(j=0;j<s;j++) num*=disa;
max=0;
for(j=0;j<num;j++)
{
	jc=j;
	prob=1;
	for(x=0;x<s;x++)
	{
		gen[x]=dis[jc%disa];
		prob*=ispa[gen[x]-'A']/(k*1.0);
		jc/=disa;
	}
	gen[s]='\0';
	n=finder(b,gen);
	if (n>max) max=n;
	//printf("%s %d %lf\n",gen,n,prob);
	ans+=prob*n;
}
ans=max*1.0-ans;
printf("Case #%d: %lf\n",i,ans);
}
return 0;
}