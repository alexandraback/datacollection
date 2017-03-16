//Coder: Balajiganapathi
//#define TRACE
#define DEBUG

#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;

// Basic macros
#define st          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define rep(i,s,n)  for(int i=s;i<=(n);++i)
#define fr(i,n)     re(i,0,n)
#define repv(i,f,t) for(int i = f; i >= t; --i)
#define rev(i,f,t)  repv(i,f - 1,t)
#define frv(i,n)    rev(i,n,0)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (int)(x.size())

const int oo = 2000000009;
const double eps = 1e-9;

#ifdef TRACE
    #define trace1(x)                cerr << #x << ": " << x << endl;
    #define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
    #define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
    #define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
    #define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
    #define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

    #define trace1(x)
    #define trace2(x, y)
    #define trace3(x, y, z)
    #define trace4(a, b, c, d)
    #define trace5(a, b, c, d, e)
    #define trace6(a, b, c, d, e, f)

#endif

int a, b, c;

ll dp[33][2][2][2];

#define get(x, i) ((x & (1 << i))? 1: 0)

ll solve(int i, int af, int bf, int cf) {
    if(i == -1) {
        return (af + bf + cf == 0);
    }
    ll &ret = dp[i][af][bf][cf];
    if(ret != -1) return ret;
    ret = 0;

    bool aa[2], bb[2], cc[2];
    fr(j, 2) aa[j] = bb[j] = cc[j] = true;

    if(af && get(a, i) == 0) aa[1] = false;
    if(bf && get(b, i) == 0) bb[1] = false;
    if(cf && get(c, i) == 0) cc[1] = false;

    fr(an, 2) fr(bn, 2) fr(cn, 2) if(aa[an] && bb[bn] && cc[cn] && ((an & bn) == cn)) {
        trace4(i, an, bn, cn);
        int afn = af, bfn = bf, cfn = cf;
        if(afn && get(a, i) && an == 0) afn = 0;
        if(bfn && get(b, i) && bn == 0) bfn = 0;
        if(cfn && get(c, i) && cn == 0) cfn = 0;
        ret += solve(i - 1, afn, bfn, cfn);
    }
    trace5(i, af, bf, cf, ret);

    return ret;
}

int main() {
    //freopen("sample.txt", "r", stdin);
    freopen("B-small-attempt0.in", "r", stdin);
    //freopen("B-large.in", "r", stdin);

    //freopen("output.txt", "w", stdout);
    freopen("small0.txt", "w", stdout);
    //freopen("large.txt", "w", stdout);
    
    int kases, kase;
    scanf("%d", &kases);
    for(kase = 1; kase <= kases; ++kase) {
        scanf("%d %d %d", &a, &b, &c);
        trace3(a, b, c);
        printf("Case #%d: ", kase);
        ini(dp, -1);
        printf("%lld\n", solve(30, 1, 1, 1));
    }
    
    
	return 0;
}
