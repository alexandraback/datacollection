/// ///////////////////// ///
///                       ///
///      Silver Rain      ///
///                       ///
///         JU            ///
///                       ///
/// ///////////////////// ///

#include<iostream>
#include<sstream>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdlib>
#include<cctype>
#define read(a) freopen("a.txt","r",stdin)
#define write(a) freopen("a.txt","w",stdout)
#define pb(a) push_back(a)
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))

#define S(a) scanf("%d",&a)
#define PS() printf(" ")
#define PN() puts("")
#define PCASE() printf("Case #%d:",kk++)

using namespace std;

int n,dp[(1<<20)+5],K,opn[25],fl;
int loc[24][205];
vector<int>res;
bool check(int bt, int nd)
{
    nd=opn[nd];
    int cnt=loc[0][nd],b,i;
    for(i=0;i<n;i++)
    {
        b=(1<<i);
        if((b&bt)!=0) cnt+=(loc[i+1][nd] + (opn[i+1]==nd?-1:0));
    }
    if(cnt>0)return true;
    return false;
}

int func(int bt)
{
    if(bt==fl)return 1;
    if(dp[bt]!=-1)return dp[bt];
    int chk=0,i;
    for(i=0;i<n;i++)
    {
        int b=(1<<i);
        if((bt&b)==0 && check(bt,i+1))
        {
            chk=func((bt|b));
            if(chk==1){res.pb(i+1);break;}
        }
    }
    return dp[bt]=chk;
}

int main()
{
    int t,kk=1;
    int i,j,k,x,chk,l;
    freopen("d.in","r",stdin);
    freopen("dout.txt","w",stdout);
    S(t);
    while(t--)
    {
        CLR(loc);res.clear();
        S(K);S(n);
        fl=(1<<n)-1;
        for(i=0;i<K;i++){S(j);loc[0][j]++;}
        for(i=1;i<=n;i++)
        {
            S(opn[i]);
            S(k);
            for(j=1;j<=k;j++)
            {
                S(x);
                loc[i][x]++;
            }
        }
        SET(dp);
        chk=func(0);

        PCASE();
        if(!chk)puts(" IMPOSSIBLE");
        else{
            l=res.size();
            reverse(res.begin(),res.end());
            for(i=0;i<l;i++)printf(" %d",res[i]);
            puts("");
        }
    }
    return 0;
}
