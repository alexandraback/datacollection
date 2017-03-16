/**
 * @author - iSea_baidu @ 2016-04-16 09:14
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
#include <map>
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

const int maxn = 10 + 2;

int n, ans, bff[maxn];
bool vis[maxn];

void try_update(int len, vector<int>& seq) {
    // printf("%d : ", len);s

    rep (i, len) {
        int lf = seq[(i + len - 1) % len];
        int rt = seq[(i + 1) % len];
        if (lf != bff[seq[i]] && rt != bff[seq[i]]) {
            return;
        }
    }
    to_max(ans, len);
}

void dfs(int len, vector<int>& seq) {
    if (len >= 2) {
        try_update(len, seq);
    }
    if (len == n) {
        return;
    }
    rep (i, n) {
        if (!vis[i]) {
            vis[i] = true;
            seq.push_back(i);
            dfs(len + 1, seq);
            seq.pop_back();
            vis[i] = false;
        }
    }
}

int main() {
    repcase {
        NOTICE("solving case %d...", Case);
        scanf("%d", &n);
        rep (i, n) {
            scanf("%d", &bff[i]);
            --bff[i];
            vis[i] = false;
        }
        ans = 1;
        vector<int> seq;
        dfs(0, seq);
        printf("Case #%d: %d\n", Case++, ans);
    }
    return 0;
}