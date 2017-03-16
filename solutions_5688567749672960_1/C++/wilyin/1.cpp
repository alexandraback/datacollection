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
#define pct __builtin_popcount
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

LL pw[20];
vector<int>lis;
LL rv(LL x)
{
    lis.clear();
    for(;x;x/=10)lis.pb(x%10);
    LL res=0;
    forp(i,0,sz(lis))
        res=res*10+lis[i];
    return res;
}

int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    pw[0]=1;
    forp(i,1,17)pw[i]=pw[i-1]*10;
    int T;LL n;
    scf("%d",&T);
    forp(tcnt,0,T)
    {
        scf("%lld",&n);
        LL x=1,ans=1,tt=*(upper_bound(pw,pw+16,n)-1);
        for(int len=0;x<tt;len++)
        {
            ans+=pw[(len+1)/2]-1+pw[len/2+1]-2+1;
            if(len>0)ans++;
            x=pw[len+1];
        }
        int len=upper_bound(pw,pw+16,n)-pw;
        LL t0=rv(n),mn=n-tt,ttt;
        if(n%10)
            mn=min(mn,rv(n)-tt+1);

        LL tans;
        forp(i,1,len)
        {
            ttt=n/pw[len-i]%10;
            forp(j,0,10)
            {
                tans=0;
                if(j<=ttt)
                {
                    tt=(n/pw[len-i+1])*10+j;
                    x=rv(pw[len-1]+rv(tt));
                    if(x>n)continue;
                    tans+=rv(tt)+1;
                    tans+=n-x;
                }
                else
                {
                    if(n/pw[len-i+1]==0)continue;
                    tt=(n/pw[len-i+1]-1)*10+j;
                    x=rv(pw[len-1]+rv(tt));
                    if(x>n)continue;
                    tans+=rv(tt)+1;
                    tans+=n-x;
                }
                mn=min(mn,tans);
            }
        }
        ans+=mn;
        ptf("Case #%d: %lld\n",tcnt+1,ans);
    }
    return 0;
}
