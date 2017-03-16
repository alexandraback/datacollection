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

int main() {
    freopen ("C.out", "w", stdout);
    repcase {
        int c, d, v;
        scanf ("%d%d%d", &c, &d, &v);
        bool have[100] = {false};
        rep (i, d) {
            int foo;
            scanf ("%d", &foo);
            have[foo] = true;
        }
        if (v > 15) {
            int num = 0;
            repf (i, 1, 5) {
                if (have[i]) {
                    num++;
                }
            }
            if (have[15] || have[16]) {
                printf ("Case #%d: %d\n", Case++, 5 - num);
            } else {
                printf ("Case #%d: %d\n", Case++, 1 + 5 - num);
            }

        } else {
            int ans = 5;
            for (int i = 0; i < (1 << 5); ++i) {
                bool can[20] = {false};
                for (int j = 0; j < (1 << 5); ++j) {
                    if ((i & j) == j) {
                        int sum = 0;
                        for (int k = 0; k < 5; ++k) {
                            if ((j >> k) & 1) {
                                sum += k;
                            }
                        }
                        can[sum] = true;
                    }
                }
                bool fail = false;
                repf (kk, 1, v) {
                    if (!can[kk]) {
                        fail = true;
                    }
                }
                
                if (!fail) {
                    // DEBUG(i);
                    int need = 0;
                    for (int k = 0; k < 5; ++k) {
                        if (((i >> k) & 1 == 1) && !have[k]) {
                            ++need;
                        }
                    }
                    ans = min(need, ans);
                }
            }
            printf ("Case #%d: %d\n", Case++, ans);
        }
    }
    return 0;
}