#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
void process(long long int i)
{
char a[1000005];
long long int l,n,j,x,p;
scanf("%s %lld",a,&n);
l=strlen(a);
long long sum=0;
long long res=0;
p=0;
for(j=0;j<l;j++)
if(a[j]!='a'&&a[j]!='e'&&a[j]!='i'&&a[j]!='o'&&a[j]!='u')
{
sum++;
if(sum==n)
{
    x=j-n+1-p;
    res=res +((x+1)*(l-j)) ;
p=j-n+2;
sum=sum-1;
}
}
else
sum=0;
printf("Case #%lld: %lld\n",i,res);
}


int main()
{

long long int t,i;
scanf("%lld",&t);

for(i=0;i<t;i++)
process(i+1);
return 0;
}
