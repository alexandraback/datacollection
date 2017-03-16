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

const int maxn = 100 + 2;

int len1, len2, len3;
char key[maxn], target[maxn];

int get_nextm(int pos, char ch, int off = 0) {
    // for (int i = begin; i <= pos; ++i) {
    //     int len = pos - i;
    //     if (len + 1 > len2) {
    //         continue;
    //     }
    //     bool match = true;
    //     for (int j = 0; j < len2 && j <= len; ++j) {
    //         if (target[j] != target[i + j]) {
    //             match = false;
    //             break;
    //         }
    //     }
    //     if (match && target[len + 1] == ch) {
    //         // match_len = len + 1;
    //         return len + 1;
    //     }
    // }
    // return 0;
    for (int len = len2 - off; len > 0; --len) {
        // end : pos - 1
        bool match = true;
        for (int j = 0; j <= len - 2; ++j) {
            if (target[j] != target[pos - len + 1 + j]) {
                match = false;
                break;
            }
        }
        if (match && target[len - 1] == ch) {
            return len;
        }
    }
    return 0;
}

int get_max_match() {
    int match_len = get_nextm(len2 - 1, target[len2 - 1], 1);
    // DEBUG(match_len);
    int left_len = len2 - match_len;
    return (len3 - len2) / left_len + 1;
}

bool find_all() {
    rep (i, len2) {
        bool find = false;
        rep (j, len1) {
            if (key[j] == target[i]) {
                find = true;
                break;
            }
        }
        if (!find) {
            return false;
        }
    }
    return true;
}

int sgn(double x) { return x > 1e-8 - (x < -1e-8); }

int nextm[maxn][26];
double dp[maxn][maxn][maxn];

int main() {
    freopen ("B.out", "w", stdout);
    repcase {
        scanf ("%d%d%d", &len1, &len2, &len3);
        scanf ("%s%s", key, target);

        if (!find_all()) {
            printf ("Case #%d: %lf\n", Case++, 0);
            continue;
        }

        int ch_cnt[26] = {0};
        rep (nextm_ch, len1) {
            ch_cnt[key[nextm_ch] - 'A'] += 1;
        }

        // calc nextm
        for (int cur_pos = 0; cur_pos <= len2; ++cur_pos) {
            rep (nextm_ch, 26) if (ch_cnt[nextm_ch] != 0) {
                nextm[cur_pos][nextm_ch] = get_nextm(cur_pos, 'A' + nextm_ch);
                // printf("next %d %d -> %d\n", cur_pos, nextm_ch, nextm[cur_pos][nextm_ch]);
            }
        }
        int max_match = get_max_match();
        // DEBUG(max_match);
        double ret = max_match;

        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1.0;
        for (int pos = 0; pos < len3; ++pos) {
            for (int match_cnt = 0; match_cnt <= max_match; ++match_cnt) {
                for (int m_pos = 0; m_pos <= len2; ++m_pos) {
                    if (sgn(dp[pos][match_cnt][m_pos]) == 0) {
                        continue;
                    }
                    // printf("Go %d %d %d -> %lf\n", pos, match_cnt, m_pos, dp[pos][match_cnt][m_pos]);
                    rep (nextm_ch, 26) if (ch_cnt[nextm_ch] != 0) {
                        int nextm_len = nextm[m_pos][nextm_ch];
                        int nextm_match = match_cnt + (nextm_len == len2);
                        dp[pos + 1][nextm_match][nextm_len] += dp[pos][match_cnt][m_pos] * ch_cnt[nextm_ch] / len1;
                    }
                }
            }
        }

        for (int match_cnt = 0; match_cnt <= max_match; ++match_cnt) {
            for (int m_pos = 0; m_pos <= len2; ++m_pos) {
                ret -= match_cnt * dp[len3][match_cnt][m_pos];
            }
        }

        printf ("Case #%d: %.10lf\n", Case++, ret);
    }
    return 0;
}