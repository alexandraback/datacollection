#include<stdio.h>
int main()
{
int t,i,j,k,n,x,count,y,z,l,flag;
scanf("%d",&t);
for(i=1;i<=t;i++)
{
scanf("%d",&n);
int arr[n+1];
count=1;
x=1;
arr[0]=0;
for(j=1;j<=n;j++)
scanf("%d",&arr[j]);
while(1)
{
    flag=1;
z=x;
x=arr[z];
if(x==-1)
break;
if(arr[x]==-1)
break;
if(z==arr[x])
{
    arr[z]=-1;
    count++;
    arr[x]=-1;
    for(l=0;l<n+1;l++)
    {
     if(arr[l]==x)
        {count++;
     x=l;
     flag=0;
     break;
        }
     else
     {
         flag=7;
     }
    }
}
else
{count++;
arr[z]=-1;
}
if(flag==7)
break;
}
printf("Case #%d: %d\n",i,count);
}
return 0;
}
