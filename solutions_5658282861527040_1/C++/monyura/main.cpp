#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>
#include <bitset>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double, int> pdi;

ll getBF( int a, int b ,int c)
{
    ll res = 0;
    rep(i,0,a)
    rep(j,0,b)
    if ((i&j) < c)
        ++res;
    return res;
}

ll power3[63];
map<pair<pii,int>, ll> mp;
ll getCnt(int a, int b, int c, int len)
{
    if (len == 0)
        return 1;
    int tmp = ((1<<len)-1);
    a &= tmp;
    b &= tmp;
    c &= tmp;
    pair<pii, int> p(pii(a,b),len);
    if (mp.find(p) != mp.end())
        return mp[p];
    --len;
    int x = (a>>len)&1;
    int y = (b>>len)&1;
    int z = (c>>len)&1;
    if (x == 0 && y == 0 && z == 0)
        return mp[p] = getCnt(a,b,c,len);
    if ((x&y) == 0 && z == 1)
        return mp[p] = (a+1) * ll(b+1);
    int nxt = (1<<len)-1;
    if (x == 1 && y == 0 && z == 0)
    {
        return mp[p] = getCnt(a,b,c,len) + getCnt(nxt,b,c,len);
    }
    if (x == 0 && y == 1 && z == 0)
    {
        return mp[p] = getCnt(a,b,c,len) + getCnt(a, nxt,c,len);
    }
    if (z == 1)
    {
        return mp[p] = ll(a+1) * (nxt+1) + ll(b+1)*(nxt+1) - ll(nxt+1)*(nxt+1) + getCnt(a,b,c,len);
    }
    return mp[p] = getCnt(nxt,nxt,c,len) + getCnt(nxt,b,c,len) + getCnt(a,nxt,c,len);
}

void test()
{
    mp.clear();
    ll a,b,c;
    cin>>a>>b>>c;
    ll res = getCnt(a-1,b-1,c-1,30);
    cout<<res<<endl;
}

void run()
{
    power3[0] = 1;
    rep(i,1,63)
        power3[i] = power3[i-1] * 3;
    int t;
    cin>>t;
    rep(i,0,t)
    {
        printf("Case #%d: ",i+1);
        test();
    }
}


#define prob "B-large(1)"


int main()
{
#ifdef _MONYURA_
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#else
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#endif
#else
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#endif
#endif
    run();
#ifdef _MONYURA_
#ifndef prob
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
#endif
    
    return 0;
}
