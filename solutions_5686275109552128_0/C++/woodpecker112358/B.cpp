#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int cost[1005][1005];
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("Bout.txt","w",stdout);
    int T;
    cin>>T;
    for(int cas=1;cas<=T;cas++)
    {
        int d,val,a[1000],ans=1000000000,cst;
        cin>>d;
        for(int i=0;i<d;i++)
        {
            scanf("%d",&a[i]);
        }
        int mx=*max_element(a,a+d);
        for(int mn=1;mn<=mx;mn++)
        {
            cst=0;
            for(int j=0;j<d;j++)
            {
                if(a[j]>mn)
                {
                    cst+=a[j]/mn-1;
                    if(a[j]%mn)
                        cst++;
                }
            }
            cst+=mn;
            ans=min(ans,cst);
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
