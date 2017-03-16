#include<iostream>
#include<stdlib.h>
#include<cstdio>
#include<cmath>
using namespace std;

long long gcd(long long a, long long b)
{
 if(b) return gcd(b, a%b);
 return a; 
}

int two(long long n)
{
  if (n == 0)
    return 0;
  while (n != 1)
  {
    if (n%2 != 0)
      return 0;
    n = n/2;
  }
  return 1;
}

int main(int argc,char *argv[])
{
int i=0;
long long p,q,num=0;
FILE *fp,*fp1;
fp=fopen(argv[1],"r+");
fp1=fopen(argv[argc-1],"w+");
int test;
int res;
fscanf(fp,"%d",&test);
while(i++<test)
{
res=1;
fscanf(fp,"%lld/%lld",&p,&q);
if(!p || p>q)
{
fprintf(fp1,"Case #%d: impossible\n",i);
continue;
}
if(p==1 && q==1)
{
fprintf(fp1,"Case #%d: 0\n",i);
continue;
}
num=gcd(p,q);
p=p/num;
q=q/num;
if(two(q))
{
while(p<q/2)
{
res++;
q=q/2;
}
fprintf(fp1,"Case #%d: %d\n",i,res);
}
else
{
fprintf(fp1,"Case #%d: impossible\n",i);
}
}
return 0;
}
