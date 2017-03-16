#include<algorithm>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include<deque>
#include<climits>
#include<complex>

using namespace std;
//-------------------------------------

#define ll long long
#define ull unsigned long long
#define sc(x) scanf("%lld",&x)
#define sc2(x,y) scanf("%lld%lld",&x,&y)
#define sci(x) scanf("%d",&x)
#define sci2(x,y) scanf("%d%d",&x,&y)

#define mem(x) memset(x,0,sizeof x)
#define all(x) x.begin(),x.end()
#define pb(x)  push_back(x);
#define xx first
#define yy second
#define inf 999999999999999
#define mkp(x,y) make_pair(x,y)
#define pii pair<ll,ll>

//---------------------------------------

#define MX 200007
#define pi 2*acos(0.00)

#define open       freopen("input.txt","r",stdin)
#define close      freopen ("output.txt","w",stdout)

string st1,st2;
ll ar[10][3],n,kk,mn;
pair<ll,ll> pa[MX];
void call(int a,int b,int pos)
{
    if(pos>=n)
    {
        ll df = abs(a-b);
        if(df<mn)
        {
//            cout<<df<<" "<<a<<" "<<b<<endl;
            mn = df;
            kk = 0;
            pa[kk] = {a,b};
            kk++;
        }
        else if(df==mn)
        {
            pa[kk] = {a,b};
            kk++;
        }
        return ;
    }
    if(st1[pos]=='?' && st2[pos]=='?')
    {
        for(int i=0;i<=9;i++)
        {
            for(int j=0;j<=9;j++)
            {
                call(a*10+i,b*10+j,pos+1);
            }
        }
    }
    else if(st1[pos]=='?')
    {
       for(int i=0;i<=9;i++)
       {
           call(a*10+i,b*10+ar[pos][2],pos+1);
       }
    }
    else if(st2[pos]=='?')
    {
       for(int i=0;i<=9;i++)
       {
//           if(a*10+ar[pos][1]==25) cout<<"============="<<endl<<ar[pos][1]<<endl;

           call(a*10+ar[pos][1],b*10+i,pos+1);
       }
    }
    else if(st1[pos]!='?' && st2[pos]!='?')
    {

        call(a*10+ar[pos][1],b*10+ar[pos][2],pos+1);
    }
    return ;
}
int main()
{
    ll i, j, l, u, v, w, x, y, z, a, b, c, d, e, f, t = 1, tc;
    ll flg, sz, cnt, gt, ans, mx;
    ll m, k;
    ll low, hi, md, inp[MX], sm, ff;

    open;
    close;
    sc(tc);
    while(tc--)
    {

    cin >> st1 >> st2;
    sz = st1.size();n=sz;
    for(i=0;i<sz;i++) ar[i][1] = st1[i]-'0',ar[i][2]=st2[i]-'0';

    mn = 99999999;
    kk = 0;
    call(0,0,0);
    sort(pa,pa+kk);
//    cout<<kk<<endl;
//    printf("Case %lld: ",t++);
    a = pa[0].xx,b=pa[0].yy;
    string st="";
    while(a) st+=(a%10+'0'),a/=10;
    while(st.size()!=sz) st+="0";
    reverse(all(st));
    printf("Case #%lld: ",t++);
    cout<<st<<" ";

    st="";
    a = b;
    while(a) st+=(a%10+'0'),a/=10;
    while(st.size()!=sz) st+="0";
    reverse(all(st));
    cout<<st<<endl;
//    printf("%lld %lld\n",pa[0].xx,pa[0].yy);
    }
    return 0;
}













