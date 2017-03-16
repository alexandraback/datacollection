#include<iostream>
#include<stdio.h>
#include<climits>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>

using namespace std;

int arr[1005],t,e,r,n;
long long sum[1005];

int main()
{
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d%d",&e,&r,&n);
        sum[0]=0;
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&arr[j]);
            sum[j]=sum[j-1]+arr[j];
        }
        if(r>e)
            r=e;
        long long minim=0;
        long long temp;
        for(int j=1;j<=n;j++)
        {
            temp=sum[j-1]*r+(long long)arr[j]*e+(sum[n]-sum[j])*r;
            if(minim<temp)
                minim=temp;
        }
        printf("Case #%d: %I64d\n",i,minim);
    }
    return 0;
}
