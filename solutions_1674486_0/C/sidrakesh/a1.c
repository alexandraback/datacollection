#include<stdio.h>
struct a{
       int num;
       int in[11];
       };
int incheck(struct a a[],int curr,int req)
{    int i,sum=0;
     for(i=1;i<=a[curr].num;i++)
     {if(a[curr].in[i]==req)
     sum++;
     else
     sum+=incheck(a,a[curr].in[i],req);
     }
     return sum;
}

int main()
{struct a a[51];
int flag,t,n,m,i,j,sum,count=1,tar;
scanf("%d",&t);
while(t--)
{scanf("%d",&n);
for(i=1;i<=n;i++)
{scanf("%d",&a[i].num);
for(j=1;j<=a[i].num;j++)
scanf("%d",&a[i].in[j]);
}
sum=0;
flag=0;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{if(j==i)
continue;
else
sum=incheck(a,j,i);
if(sum>=2)
{printf("Case #%d: Yes\n",count);
flag=1;
break;
}
sum=0;
}
if(flag==1)
break;
}
if(flag==0)
printf("Case #%d: No\n",count);
count++;
}
return 0;
}
