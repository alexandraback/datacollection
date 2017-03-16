#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int a[1010];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int test;scanf("%d",&test);
    for (int t=1;t<=test;t++)
    {
        int n;scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        int ans=1000;
        for (int i=1;i<=1000;i++)
        {
            int s=i;
            for (int j=1;j<=n;j++) s+=((a[j]-1)/i);
            ans=min(ans,s);
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
