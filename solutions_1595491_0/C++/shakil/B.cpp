#include<stdio.h>

int cas,cas1,n,s,p,count,x,flag,i;

int main()
{

    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-output.out","w",stdout);


scanf("%d",&cas);

for(cas1=1;cas1<=cas;cas1++)
{
scanf("%d %d %d",&n,&s,&p);

count = 0;

for(i=0;i<n;i++)
{
scanf("%d",&x);

if(x-p>=(2*p-2))
count++;
else if(x>=p && s>0)
{
flag = 0;

if(x>=2*p && x-2*p>=p-2)
flag = 1;
else if((x-p)%2==0 && (x-p)/2>=p-2)
flag = 1;
else if(p+1<=10 && (x-p-1)/2>=p-1)
flag = 1;
else if(x>=3*p-3)
flag = 1;

if(flag==1)
{
count++;
s--;
}
}                
}

printf("Case #%d: %d\n",cas1,count);                            
}    

return 0;    
}
