#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<iostream>
#include<sstream>
using namespace std;
int T,cas=0,n;
double a[1005],b[1005];
int main()
{
    freopen("D-small-attempt0.in","r",stdin);
    freopen("D-small-attempt0.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%lf",&a[i]);
        for(int i=0;i<n;i++)scanf("%lf",&b[i]);
        sort(a,a+n);
        sort(b,b+n);
        int ans=0,al=0,ar=n-1,bl=0,br=n-1;
        for(int i=0;i<n;i++)
        {
            if(a[ar]>b[br])
            {
                ans++;
                ar--;
                br--;
            }
            else
            {
                al++;
                br--;
            }
        }
        int ret=0;
        bl=0;br=n-1;
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]>b[br])
            {
                ret++;
                bl++;
            }
            else br--;
        }
        printf("Case #%d: %d %d\n",++cas,ans,ret);
    }
}
