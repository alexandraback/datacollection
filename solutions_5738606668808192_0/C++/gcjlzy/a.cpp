#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const int N=1e5+1;
ll a[9];
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int t,k;
    cin>>t;
    for(k=1;k<=t;k++)
    {
        ll n,m,i,j,ans,x;printf("Case #%d:\n",k);
        cin>>n>>m;
        for(i=0;i<9;i++)
        {
            a[i]=1;
            for(j=0;j<n/2;j++)a[i]*=(i+2);
            a[i]++;
        }
        for(i=0;i<m;i++)
        {
            ans=0;
            x=i*2+(1<<n/2-1)+1;
            while(x){ans=ans*10+x%2;x/=2;}
            printf("%I64d%I64d",ans,ans);
            for(j=0;j<9;j++)printf(" %I64d",a[j]);
            printf("\n");
        }
    }
    return 0;
}
