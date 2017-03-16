#include <iostream>
#include <cstdio>
using namespace std;
#define rep(i,n) for (int i=1,n__=n;i<=n__;i++)
#define repb(i,b,n) for (int i=b,n__=n;i<=n__;i++)
const int mN=150;
string s[mN];
int n;
typedef long long LL;
LL ans;
LL jc[mN];
int fa[mN];
const int md=1000000007;
int gf(int x)
{
    if (fa[x]==x)
        return x;
    else
        fa[x]=gf(fa[x]);
    return fa[x];
}
int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int ta;
    cin>>ta;
    jc[0]=1;
    rep(i,100)
        jc[i]=(jc[i-1]*i)%md;
    rep(tz,ta)
    {
        int tb[mN]={0},te[mN]={0},tj[mN]={0},tq[mN]={0},ts[mN]={0};
        cin>>n;
        rep(i,n)
            fa[i]=i;
        ans=1;
        bool can=true;
        rep(i,n)
        {
            cin>>s[i];
//            cout<<s[i]<<endl;
            char chb=s[i][0];
            char che=s[i][s[i].size()-1];
//            cout<<"chb"<<chb<<endl;
//            cout<<tq[]
            if (chb==che)
            {
                repb(j,0,s[i].size()-1)
                    if (s[i][j]!=chb)
                        can=false;
                if (can)
                {
                    if (tq[chb]==0)
                        tq[chb]=i;
                    else
                    {
                        int v=gf(tq[chb]);
                        fa[i]=v;
                        ts[v]++;
                    }
                }
            }
            else
            {
                if (tb[chb]!=0)
                    can=false;
                if (te[che]!=0)
                    can=false;
                tb[chb]=i;
                te[che]=i;
                int j=0;
                while (s[i][j]==chb)
                    j++;
                int rj=s[i].size()-1;
                while (s[i][rj]==che)
                    rj--;
                repb(k,j,rj)
                {
                    if (tj[s[i][k]]!=0)
                        can=false;
                    tj[s[i][k]]=i;
                }
            }
        }
//        cout<<tq['o']<<endl;
        if (can)
            repb(ch,'a','z')
            {
                if (tj[ch]>0)
                    if (te[ch]>0 || tb[ch]>0 || tq[ch]>0)
                        can=false;
                int u=gf(te[ch]),v=gf(tb[ch]),w=gf(tq[ch]);
//                cout<<char(ch)<<u<<v<<w<<endl;
                ans=(ans*jc[ts[w]+1])%md;
                if (u!=0 && v!=0)
                    fa[u]=v;
                if (w!=0 && v!=0)
                    fa[w]=v;
                if (v==0 && w!=0 && u!=0)
                        fa[w]=u;
            }
//        cout<<"ans"<<ans<<endl;
        int now=0;
        rep(i,n)
            if (fa[i]==i)
                now++;
        ans=(ans*jc[now])%md;
//        cout<<"fa[0]"<<fa[0]<<endl;
//        cout<<"ans"<<ans<<endl;
        printf("Case #%d: %I64d\n",tz,can?ans:0);
    }
    return 0;
}
