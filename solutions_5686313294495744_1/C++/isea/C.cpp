/**
 * @author - iSea_baidu @ 2016-05-01 01:13
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

unordered_map<string, int> topic_map[2];
int mp_cnt[2];

void clear_map(int id) {
    topic_map[id].clear();
    mp_cnt[id] = 0;
}

int get_topic_id(int id, const string& topic) {
    if (topic_map[id].find(topic) == topic_map[id].end()) {
        return topic_map[id][topic] = mp_cnt[id]++;
    }
    return topic_map[id][topic];
}

const int maxn = 1000 + 10;

int first[maxn], second[maxn];
int match[maxn], lmatch[maxn];
bool vis[maxn], g[maxn][maxn];

bool dfs(int x) {
    rep (j, mp_cnt[1]) {
        if (g[x][j] && !vis[j]) {
            vis[j] = true;
            if (match[j] == -1 || dfs(match[j])) {
                lmatch[x] = j;
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int max_match() {
    int ret = 0;
    memset(lmatch, -1, sizeof(lmatch));
    memset(match, -1, sizeof(match));
    rep (i, mp_cnt[0]) {
        memset(vis, 0, sizeof(vis));
        ret += dfs(i);
    }
    rep (i, mp_cnt[0]) {
        if (lmatch[i] == -1) {
            ++ret;
        }
    }
    rep (i, mp_cnt[1]) {
        if (match[i] == -1) {
            ++ret;
        }
    }
    return ret;
}

int main() {
    repcase {
        int n;
        scanf("%d", &n);
        clear_map(0); clear_map(1);
        rep (i, n) {
            char buf[22];
            scanf("%s", buf);
            first[i] = get_topic_id(0, string(buf));
            scanf("%s", buf);
            second[i] = get_topic_id(1, string(buf));
        }
        memset(g, 0, sizeof(g));
        rep (i, n) {
            g[first[i]][second[i]] = true;
        }
        printf("Case #%d: %d\n", Case++, n - max_match());
    }
    return 0;
}