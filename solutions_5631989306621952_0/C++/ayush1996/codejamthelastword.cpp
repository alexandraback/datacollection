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
    freopen("codejamthelast.txt","r",stdin);
    freopen("codejamthelastout.txt","w",stdout);
    int t,n,i,j,k,l,r,x;
    char b[1005],a[2005];
    sd(t);
    for(x=1;x<=t;x++)
    {
        ss(b);
        n=strlen(b);
        a[1000]=b[0];
        l=999;
        r=1001;
        for(i=1;i<n;i++)
        {
            if(b[i]>=a[l+1])
            {
                a[l]=b[i];
                l--;
            }
            else
            {
                a[r]=b[i];
                r++;
            }
        }
        printf("Case #%d: ",x);
        for(i=l+1;i<r;i++)
            printf("%c",a[i]);
        printf("\n");
    }
    return 0;
}
