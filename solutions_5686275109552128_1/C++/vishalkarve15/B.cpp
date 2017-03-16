#include<bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define ll long long

int a[1010];

int main()
{
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int mx=-1;
        for(int i=0;i<n;i++)
            mx=max(mx,a[i]);
        int ans=mx;
        for(int m=1;m<=mx;m++)
        {
            if(m>ans)
                break;
            int newans=m;
            for(int i=0;i<n;i++)
            {
                if(a[i]%m==0)
                    newans+=a[i]/m-1;
                else
                    newans+=a[i]/m+1-1;
            }
            if(newans<ans)
                ans=newans;
        }
        printf("Case #%d: %d\n",tt,ans);
    }
    return 0;
}
