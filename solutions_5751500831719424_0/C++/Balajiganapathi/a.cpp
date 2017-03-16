//Coder: Balajiganapathi
#define TRACE
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

const int mx = 155;

char str[mx][mx];
int idx[mx];

int n;

bool left() {
    fr(i, n) if(str[i][idx[i]]) return true;
    return false;
}

int solve() {
    int ret = 0;
    ini(idx, 0);
    //trace1(left());
    while(left()) {
        char c = str[0][idx[0]];
        //trace1(c);
        vi v;
        fr(i, n) {
            if(str[i][idx[i]] != c) return -1;
            int cnt = 0;
            while(str[i][idx[i]] == c) {
                ++cnt;
                ++idx[i];
            }
            v.pu(cnt);
        }
        sort(all(v));
        int target = v[n / 2];
        //trace2(c, target);
        //fr(i,sz(v)) trace2(i, v[i]);
        fr(i, n) ret += abs(target - v[i]);
    }
    fr(i, n) if(str[i][idx[i]]) return -1;

    return ret;
}

int main() {
    //freopen("sample.txt", "r", stdin);
    freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-large.in", "r", stdin);

    //freopen("output.txt", "w", stdout);
    freopen("small0.txt", "w", stdout);
    //freopen("large.txt", "w", stdout);
    
    int kases, kase;
    scanf("%d", &kases);
    for(kase = 1; kase <= kases; ++kase) {

        //trace2(n, kase);
        scanf("%d", &n);
        fr(i, n) scanf("%s",str[i]);
        printf("Case #%d: ", kase);
        int ans = solve();
        if(ans == -1) printf("Fegla Won\n");
        else printf("%d\n", ans);
    }
    
	return 0;
}
