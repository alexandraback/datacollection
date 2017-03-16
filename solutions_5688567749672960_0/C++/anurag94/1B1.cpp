#include<iostream>
#include<cstdio>
using namespace std;
#define min1(a,b) a<b?a:b
int a[1000005];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,i,j,n,m,ca,r,temp;
    for(i=0;i<=1000002;i++)
    {
        a[i]=-1;
    }
    for(i=1;i<=20;i++)
    {
        a[i]=i;
    }
    for(i=21;i<=1000001;i++)
    {
        temp=i;
        r=0;
        while(temp>0)
        {
            r=(r*10)+(temp%10);
            temp/=10;
        }
        if(a[r]==-1 || (i%10)==0)
        {
            a[i]=a[i-1]+1;
        }
        else if((i%10)!=0)
        {
            a[i]=min1(a[i-1]+1,a[r]+1);
        }
    }
    scanf("%d",&t);
    for(ca=1;ca<=t;ca++)
    {
        scanf("%d",&n);
        printf("Case #%d: %d\n",ca,a[n]);
    }
    return 0;
}
