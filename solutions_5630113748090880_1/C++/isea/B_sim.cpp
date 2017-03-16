/**
 * @author - iSea_baidu @ 2016-04-16 09:37
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

const int maxn = 100 + 5;

deque<deque<int>> seqs;
int n;

void recover_first_col() {
    int sz = (int)seqs.size();

    vector<bool> used(sz, false);
    vector<bool> used_col((sz + 1) / 2, false);
    repf (i, 1, sz - 1) {
        rep (j, (sz + 1) / 2) {
            if (seqs[i][0] == seqs[0][j] && !used_col[j]) {
                used[i] = true;
                used_col[j] = true;
            }
        }
    }
    printf(" %d", seqs[0][0]);
    repf (i, 1, sz - 1) {
        if (!used[i]) {
            printf(" %d", seqs[i][0]);
        }
    }
    puts("");
}

void recover() {
    // NOTICE("recover");
    int sz = (int)seqs.size();
    int n = (sz + 1) / 2;

    sort(seqs.begin(), seqs.end());
    if (sz == 1 || seqs[1][0] != seqs[0][0]) {
        // miss first col
        recover_first_col();
        return;
    }
    int ret = 0;
    rep (i, n) {
        ret ^= seqs[0][i];
        ret ^= seqs[1][i];
    }
    for (int i = 2; i < sz; ++i) {
        ret ^= seqs[i][0];
        seqs[i].pop_front();
    }
    seqs.pop_front();
    seqs.pop_front();
    printf(" %d", ret);
    recover();
}

int main() {
    repcase {
        scanf("%d", &n);
        seqs.clear();
        rep (i, 2 * n - 1) {
            deque<int> tmp;
            rep (j, n) {
                int bar;
                scanf("%d", &bar);
                tmp.push_back(bar);
            }
            seqs.push_back(tmp);
        }
        printf("Case #%d:", Case++);
        recover();
    }
    return 0;
}