#include<iostream>
#include<stdio.h>

using namespace std;

long gcd(long x,long y)
{
if(y==0)
return x;
else
return gcd(y,x%y);
}

int main(){
int t,n,i,j,k;
long a,b,c,d,x;
//FILE *fp=fopen("attempt1.in","r");
//FILE *fpo=fopen("out.txt","w");
cin>>t;
//fscanf(fp,"%d",&t);
for(i=1;i<=t;i++)
{
//fscanf(fp,"%d",&a);
scanf("%ld/%ld",&c,&d);
a=c;
b=d;

for(k=0;a<b;k++)
a=a*2;

x=gcd(a,b);
b=b/x;

while(b%2==0)
b=b/2;

if(b==1 && k<=40)
//fprintf(fpo,"Case #%d: Bad magician!\n",i+1);
printf("Case #%d: %d\n",i,k);
else
printf("Case #%d: impossible\n",i);
}
}

