#include<bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define ll long long
#define mod 1000000007
#define bitcount    __builtin_popcountll
#define pb push_back
int main()
{
    freopen("codejamrankin.txt","r",stdin);
    freopen("codejamrankout.txt","w",stdout);
    int t,n,i,j,k,x,a[2505];
    sd(t);
    for(x=1;x<=t;x++)
    {
        sd(n);
        for(i=1;i<=2500;i++)
            a[i]=0;
        for(i=1;i<2*n;i++)
        {
            for(j=0;j<n;j++)
            {
                sd(k);
                a[k]++;
            }
        }
        printf("Case #%d: ",x);
        for(i=1;i<=2500;i++)
        {
            if(a[i]%2==1)
                printf("%d ",i);
        }
        printf("\n");
    }
    return 0;
}
