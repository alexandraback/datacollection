#include<bits/stdc++.h>
#define scf scanf
#define ptf printf
#define forp(i,j,k) for(int i=j;i<k;i++)
#define form(i,j,k) for(int i=j;i>k;i--)
#define sz(x) (int)x.size()
#define pb push_back
#define fst first
#define scd second
#define m_p make_pair
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

int p[10000];

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int n,T;
    scf("%d",&T);
    forp(tcnt,0,T)
    {
        scf("%d",&n);
        forp(i,0,n)scf("%d",p+i);
        sort(p,p+n);reverse(p,p+n);
        int ans=1000000,tans;
        forp(mx,1,1001)
        {
            tans=mx;
            form(i,n-1,-1)
            {
                tans+=p[i]/mx;
                if(p[i]%mx==0)tans--;
            }
            ans=min(ans,tans);
        }
        ptf("Case #%d: %d\n",tcnt+1,ans);
    }
    return 0;
}
