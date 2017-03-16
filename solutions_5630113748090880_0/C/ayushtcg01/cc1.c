#include<stdio.h>
int main()
{
int t,i,j,k,n,x;
scanf("%d",&t);
for(i=1;i<=t;i++)
{
int arr[2501]={0};
scanf("%d",&n);
for(j=0;j<2*n-1;j++)
{
    for(k=0;k<n;k++)
    {
    scanf("%d",&x);
    arr[x]++;
    }
}
printf("Case #%d: ",i);
for(j=1;j<=2501;j++)
{
    if(arr[j]%2==1)
        printf("%d ",j);
}
printf("\n");
}
return 0;
}
