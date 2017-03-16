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


int main()
{
    ll i, j, l, u, v, w, x, y, z, a, b, c, d, e, f, t = 1, tc;
    ll flg, sz, cnt, gt, ans, mx, mn;
    ll m, k, n;
    ll low, hi, md, inp[MX], sm, ff,ase[40];

    open;
    close;
    string st;
    sc(tc);
    while(tc--)
    {

    cin >> st;

    vector<ll> tk;
    mem(ase);
    sz = st.size();
    for(i=0;i<sz;i++) ase[st[i]-'A']++;

    while(ase['Z'-'A'])
    {
        tk.pb(0);
        ase['Z'-'A']--;
        ase['E'-'A']--;
        ase['R'-'A']--;
        ase['O'-'A']--;
    }

    while(ase['W'-'A'])
    {
        tk.pb(2);
        ase['T'-'A']--;
        ase['W'-'A']--;
        ase['O'-'A']--;
    }

    while(ase['U' - 'A'])
    {
        tk.pb(4);
        ase['F'-'A']--;
        ase['O'-'A']--;
        ase['U'-'A']--;
        ase['R'-'A']--;
    }

    while(ase['X' - 'A'])
    {
        tk.pb(6);
        ase['S'-'A']--;
        ase['I'-'A']--;
        ase['X'-'A']--;
//        ase['R'-'A']--;
    }

    while(ase['G' - 'A'])
    {
        tk.pb(8);
        ase['E'-'A']--;
        ase['I'-'A']--;
        ase['G'-'A']--;
        ase['H'-'A']--;
        ase['T'-'A']--;
    }

    while(ase['O' - 'A'])
    {
        tk.pb(1);
        ase['O'-'A']--;
        ase['N'-'A']--;
        ase['E'-'A']--;
//        ase['R'-'A']--;
    }

    while(ase['S' - 'A'])
    {
        tk.pb(7);
        ase['S'-'A']--;
        ase['E'-'A']--;
        ase['V'-'A']--;
        ase['E'-'A']--;
        ase['N'-'A']--;
    }

    while(ase['V' - 'A'])
    {
        tk.pb(5);
        ase['F'-'A']--;
        ase['I'-'A']--;
        ase['V'-'A']--;
        ase['E'-'A']--;
    }

    while(ase['R' - 'A'])
    {
        tk.pb(3);
        ase['T'-'A']--;
        ase['H'-'A']--;
        ase['R'-'A']--;
        ase['E'-'A']--;
        ase['E'-'A']--;
    }

    while(ase['I' - 'A'])
    {
        tk.pb(9);
        ase['N'-'A']--;
        ase['I'-'A']--;
        ase['N'-'A']--;
        ase['E'-'A']--;
    }

    sort(all(tk));
    sz=tk.size();
    printf("Case #%lld: ",t++);
    for(i=0;i<sz;i++) printf("%lld",tk[i]);printf("\n");

    }


    return 0;
}












