/**
 * @author - INFO
 * @brief - From sky to the sea.
 **/

#include <bits/stdc++.h>

using namespace std;

// SELF TEMPLATE CODE BGEIN

#define LOG(level, fmt, arg...) \
    printf("[" #level "] [Line:%d] " fmt"\n", __LINE__, ##arg);

#define NOTICE(fmt, arg...) LOG(NOTICE, fmt, ##arg)
#define FATAL(fmt, arg...) LOG(FATAL, fmt, ##arg)

#define DEBUG(x) do { \
    stringstream ss; \
    ss << #x << ": " << x; \
    NOTICE("%s", ss.str().c_str()) \
} while(0)

#define SZ(x) ((int)((x).size()))
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repcase int t, Case = 1; for (cin >> t; t; --t)

template<class T> inline void to_min(T &a, const T b) { if (b < a) a = b; }
template<class T> inline void to_max(T &a, const T b) { if (b > a) a = b; }

// SELF TEMPLATE CODE END

int solve(int r, int w) {
    if (r == w || w == 1) return r;
    return r / w + w - (r % w == 0? 1 : 0);
}

int main() {
    freopen ("A.out", "w", stdout);
    repcase {
        int c, r, w;
        scanf ("%d%d%d", &c, &r, &w);
        if (w == 1) {
            printf ("Case #%d: %d\n", Case++, c * r);
            continue;
        }
        int ans = solve(r, w);
        ans += (c - 1) * (r / w);
        printf ("Case #%d: %d\n", Case++, ans);
    }
    return 0;
}