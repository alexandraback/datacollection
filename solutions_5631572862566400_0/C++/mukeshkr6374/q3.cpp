#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,i,n,k;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%lld",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%lld",&n);
        long long a[n];
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        long long cnt=1,ans=0;
        for(i=1;i<n;i++)
        {
            if(a[i]==a[i-1])
            {
                ans=max(ans,cnt);
                cnt=1;
            }
            else
                cnt++;
        }
        ans=max(ans,cnt);
        printf("Case #%lld: %lld\n",k,ans);
    }
    return 0;
}
