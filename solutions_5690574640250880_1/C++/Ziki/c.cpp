/*==================================================*\
 | Author: ziki
 | Created Time: 
 | File Name: 
 | Description: 
\*==================================================*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <string.h>
 
using namespace std;
using namespace rel_ops;
 
typedef long long int64;
typedef long long ll;
typedef unsigned long long uint64;
typedef unsigned long long ull;
const double pi=acos(-1.0);
const double eps=1e-11;
const int inf=0x7FFFFFFF;
template<class T> inline bool checkmin(T &a,T b){return b<a?a=b,1:0;}
template<class T> inline bool checkmax(T &a,T b){return b>a?a=b,1:0;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define mem(a,b) memset(a, b, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define rep(i,n) for(int i=0; i<n; i++)
#define repit(i,v) for(typeof(v.begin()) i=v.begin(); i!=v.end(); i++)
#define iter(v) typeof(v.begin())
#define ff first
#define ss second
#define sz(x) int(x.size())
#ifdef LOCAL
#define dbg(args...) printf(args); //##__VA_ARGS__
#define dout cout
#define out(x) (cout<<#x<<": "<<x<<endl)
template<class T>void show(T a, int n){for(int i=0; i<n; ++i) cout<<a[i]<<' '; cout<<endl;}
template<class T>void show(T a, int r, int l){for(int i=0; i<r; ++i)show(a[i],l);cout<<endl;}
#else
#define dbg(...)
#define dout if(true);else cout
#define out(...)
#define show(...)
#endif

char s[55][55];
int n, m, k;
int has, ini;
int stk[55];
bool dfs(int cur, int has, int maxi) {
    if (cur == n || has == 0) {
        if (has) return false;
        for (int i = 0; i < cur; i ++) {
            for (int j = 0; j < stk[i]; j++) s[i][j] = '.';
            for (int j = stk[i]; j < m; j++) s[i][j] = '*';
        }
        for (int i = cur; i < n; i++) 
            for (int j = 0; j < m; j ++)
                    s[i][j] = '*';
        s[0][0] = 'c';
        return true;
    }
    if ((has + maxi - 1) / maxi > n - cur) {
        return false;
    }
    for (int j = min(maxi, has); j > 1; j -- ) {
        stk[cur] = j;
        if (dfs(cur+1, has - j, j)) return true;
    }
    return false;
}
int main() {
    int T;
    cin >> T;
    rep (cas, T) {
        cin >> n >> m >> k;
        printf("Case #%d:\n", cas+1);
        has = n * m - k, ini = has;
        //cout << n << ' ' << m << ' ' << has << endl;
        if (has == 1 || n == 1 || m == 1) {
            rep(i,n) {
                rep(j,m) {
                    if (has == n * m - k) putchar('c');
                    else if (has > 0) putchar('.');
                    else putchar('*');
                    has--;
                }
                puts("");
            }
        }
        else {
            clr(s);
            if (has < 4) puts("impossible");
            else {
                bool ansed = false;
                for (int i = 2; i <= m && i * 2 <= has; i++) {
                    stk[0] = stk[1] = i;
                    if (dfs(2, has-i-i, i)) {
                        ansed = true;
                        break;
                    }
                }
                if (ansed)
                    for (int i = 0; i < n; i++)
                        printf("%s\n", s[i]);
                else puts("impossible");
            }
        }
    }
    return 0;
}
