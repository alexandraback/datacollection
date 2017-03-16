#include<stdio.h>

int A[20],B[20],cas,cas1;
int a,b,h,t,i,j,k,x,flag,count;

int main()
{

A[0]=1;

for(i=1;i<=8;i++)
A[i]=A[i-1]*10;

    freopen("C-large.in","r",stdin);
    freopen("C-output.out","w",stdout);


scanf("%ld",&cas);

for(cas1=1;cas1<=cas;cas1++)
{

scanf("%d %d",&a,&b);

t =  a;
h=0;

while(t!=0)
{
t/=10;
h++;
}

count = 0;

for(i=a;i<=b;i++)
{

for(j=1;j<h;j++)
{
x = (i%A[j])*A[h-j]+i/A[j];
B[j]=x;
if(x>=a&&x<=b && x>i)
{
flag = 1;
for(k=1;k<j;k++)
if(B[k]==x)
{flag = 0; break;}
if(flag==1)
count++;
}
}
}

printf("Case #%ld: %ld\n",cas1,count);                            
}    

return 0;    
}
