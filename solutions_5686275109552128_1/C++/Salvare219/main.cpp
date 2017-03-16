#include<bits/stdc++.h>
using namespace std;


int a[5000];
int main()
{
    freopen("1.in","r",stdin);
    freopen("2.out","w",stdout);
    int ti=1,t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        int ans=10000;
        for(int i=1;i<=1000;i++)
        {
            int sum=i;
            for(int j=0;j<n;j++)
                sum+=(a[j]-1)/i;
            ans=min(sum,ans);
        }
        printf("Case #%d: %d\n",ti++,ans);
    }
    return 0;
}
