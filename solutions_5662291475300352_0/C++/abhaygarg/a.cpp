#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define ll long long
#define mod 1000000007LL
#define pii pair<int,int>
#define pll pair<ll,ll>
int d[1001],p[10],s[2];
int main()
{
    freopen("inp.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,c1=1,ans,i,n;
    scanf("%d",&t);
    //printf("%d\n",t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d %d %d",&d[i],&p[i],&s[i]);
        if(n==1)
            ans=0;
        else if(n==2)
        {
            if(s[1]<s[0])
            {
                ans=1;
            }
            else
            {
                double d1=360.0/(double)s[0];
                double d2=360.0/(double)s[1];
                d1=(360.0-(double)d[0])*d1;
                d2=(360.0-(double)d[1])*d2;
                if(d1>d2)
                {
                    ans=1;
                }
                else
                    ans=0;
            }
        }
        printf("Case #%d: %d\n",c1,ans);
        c1++;
    }
    return 0;
}
