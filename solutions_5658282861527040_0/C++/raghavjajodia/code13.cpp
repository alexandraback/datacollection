#include<stdio.h>
int main()
{
int t;
scanf("%d",&t);
for(int i=1;i<=t;i++)
{
    long long count=0;
    int a,b,k;
    scanf("%d %d %d",&a,&b,&k);
    for(int i=0;i<a;i++)
        for(int j=0;j<b;j++){
       // printf("%d\n",i&j);
        if((i&j)<k)
        count++;
        }
    printf("Case #%d: %lld\n",i,count);
}



return 0;}
