// New Ryan
// Create @ 11:13 04-27 2013
// Comment - 

#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

// Self Template Code BGEIN

#define sz(x) ((int)((x).size()))
#define out(x) printf(#x" %d\n", x)
#define all(x) (x).begin(), (x).end()
#define clz(x) memset (x, 0, sizeof(x))
#define read(x) freopen (x, "r", stdin)
#define wrte(x) freopen (x, "w", stdout)
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

typedef long long int64;
typedef pair<int, int> pii;
typedef pair<int64, int64> pll;
typedef pair<double, double> pdd;

int sgn(double x) { return (x > 1e-8) - (x < -1e-8); }
int count_bit(int x) { return x == 0? 0 : count_bit(x >> 1) + (x & 1); }

template<class T> inline void ckmin(T &a, const T b) { if (b < a) a = b; }
template<class T> inline void ckmax(T &a, const T b) { if (b > a) a = b; }

// Self Template Code END

const int maxn = 10000 + 10;
const int inf = (-1u) >> 1;

int e, r, n, a[maxn], next[maxn];

void use(int64& ans, int& cur, int cur_use, int val) {
    //printf ("use %d\n", cur_use);
    ans += (int64)cur_use * val;
    cur -= cur_use;
    cur += r;
}

int main() {
    wrte ("B2.out");
    
    repcase {
        scanf ("%d%d%d", &e, &r, &n);
        rep (i, n) {
            scanf ("%d", &a[i]);
        }
        stack<int> st;
        a[n] = inf;
        st.push(n);
        repd (i, n - 1, 0) {
            while (a[st.top()] < a[i]) st.pop();
            next[i] = st.top();
            st.push(i);
        }
        r = min(r, e);
        int curE = e;
        int64 ans = 0;
        rep (i, n) {
            //out(next[i]);
            
            if (next[i] == n) {
                use(ans, curE, curE, a[i]);
            } else {
                int dif = next[i] - i;
                if (e / dif <= r) {
                    use(ans, curE, curE, a[i]);
                } else {
                    int mincur = e - r * dif;
                    //out(mincur);
                    int canuse = max(0, curE - mincur);
                    use(ans, curE, canuse, a[i]);
                }
            }
        }
        printf ("Case #%d: %I64d\n", Case++, ans);
    }
    return 0;
}

