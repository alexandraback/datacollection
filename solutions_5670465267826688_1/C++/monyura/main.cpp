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
#include <cassert>


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
typedef pair<double, double> pdd;

const pii Go[4][4] = {
    {{0, 1}, {1, 1}, {2, 1}, {3, 1}},
    {{1, 1}, {0, -1},{3, 1}, {2, -1}},
    {{2, 1}, {3, -1},{0, -1},{1, 1}},
    {{3, 1}, {2, 1}, {1, -1}, {0, -1}}
};

pii mul(const pii &a, const pii &b)
{
    pii res = Go[a.first][b.first];
    res.second *= a.second * b.second;
    return res;
}

pii fromChar(char c)
{
    static  const char str[]="1ijk";
    return {strchr(str, c) - str, 1};
}

void test()
{
    int n;
    ll x;
    cin>>n>>x;
    char str[10100];
    scanf("%s",str);
    int mni = -1;
    pii val{0, 1};
    map<pii, int> was;
    pii stVal = val;
    int perLen = -1;
    ll tailLen = x;
    rep(t,0,min(x, 9LL))
    {
        if(was.find(val) != was.end() && perLen == -1)
        {
            perLen = t - was[val];
            tailLen = (x - was[val]) % perLen;
            stVal = val;
        }
        was[val] = t;

        rep(i, 0, n)
        {
            val = mul(val, fromChar(str[i]));
            if (val == Go[0][1] && mni == -1) // i
                mni = t * n + i;
        }
    }
    rep(t,0,tailLen)
        rep(i, 0, n)
            stVal = mul(stVal, fromChar(str[i]));
    if (stVal != Go[3][3]) // -1
    {
        puts("NO");
        return;
    }
    val = {0, 1};
    ll mxk = -1;
    rep(t,0,min(x,9LL))
        for (int i = n-1; i>=0; i--)
        {
            val = mul(fromChar(str[i]), val);
            if (val == Go[0][3] && mxk == -1) // k
                mxk = ll(n) * x - (t * n + (n - i));
        }
    if (mxk == -1 || mni == -1 || mni + 1 >= mxk)
    {
        puts("NO");
        return;
    }
    
//    val = {0, 1}
//    rep(i,mni+1, mxk)
//        val = mul(val, fromChar(str[i%n]));
//    if (val != Go[0][2])
//        cerr<<"ERROR"<<endl;
    puts("YES");
    
}

void run()
{
    int t;
    cin>>t;
    rep(i,0,t)
    {
        printf("Case #%d: ", i + 1);
        test();
    }
}

#define prob "C-large(2)"



int main()
{
#ifdef _MONYURA_
    #ifdef prob
        freopen("../" prob ".in","r",stdin);
        freopen("../" prob ".out","w",stdout);
    #else
        freopen("../test.in","r",stdin);
        freopen("../test.out","w",stdout);
        time_t st=clock();
    #endif
#else
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