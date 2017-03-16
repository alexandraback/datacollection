/**
 * @author - iSea_baidu @ 2016-05-01 00:54
 * @brief - From sky to the sea.
 **/

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;

// SELF TEMPLATE CODE BGEIN

#define LOG(level, fmt, arg...) \
    fprintf(stderr, "[" #level "] [Line:%d] " fmt"\n", __LINE__, ##arg);
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
#define repcase int t, Case = 1; for (scanf("%d", &t); t; --t)
template<class T> inline void to_min(T &a, const T b) { if (b < a) a = b; }
template<class T> inline void to_max(T &a, const T b) { if (b > a) a = b; }

// SELF TEMPLATE CODE END

unordered_map<string, int> topic_map;
int mp_cnt;

void clear_map() {
    topic_map.clear();
    mp_cnt = 0;
}

int get_topic_id(const string& topic) {
    if (topic_map.find(topic) == topic_map.end()) {
        return topic_map[topic] = mp_cnt++;
    }
    return topic_map[topic];
}

const int maxn = 16;

int dp[(1 << maxn) + 10];
int first[maxn], second[maxn], fmask[maxn], smask[maxn];

int main() {
    repcase {
        int n;
        scanf("%d", &n);
        clear_map();
        rep (i, n) {
            char buf[22];
            scanf("%s", buf);
            first[i] = get_topic_id(string(buf));
            scanf("%s", buf);
            second[i] = get_topic_id(string(buf));
        }
        rep (i, n) {
            fmask[i] = smask[i] = 0;
            rep (j, n) {
                if (first[i] == first[j]) {
                    fmask[i] |= (1 << j);
                }
                if (second[i] == second[j]) {
                    smask[i] |= (1 << j);
                }
            }
        }
        int max_state = (1 << n);
        memset(dp, 0, sizeof(dp));
        rep (st, max_state) {
            rep (i, n) {
                if ((st >> i) & 1) continue;
                if ((st & fmask[i]) != 0 && (st & smask[i]) != 0) {
                    // printf("update %d -> %d\n", st, st | (1 << i));
                    to_max(dp[st | (1 << i)], dp[st] + 1);
                } else {
                    to_max(dp[st | (1 << i)], dp[st]);
                }
            }
        }
        printf("Case #%d: %d\n", Case++, dp[max_state - 1]);
    }
    return 0;
}