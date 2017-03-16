// "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"

/**
 * @author - iSea_baidu @ 2016-05-01 00:04
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

int id(char ch) {
    return ch - 'A';
}

int main() {
    repcase {
        char buf[2012];
        scanf("%s", buf);
        int cnt[26];
        auto update_cnt = [&cnt](const char *s, int n) {
            for (int i = 0; s[i]; ++i) {
                cnt[id(s[i])] -= n;
            }
        };
        for (int i = 0; buf[i]; ++i) {
            cnt[id(buf[i])]++;
        }
        int num[10] = {0};
        // 0 - ZERO
        num[0] = cnt[id('Z')];
        update_cnt("ZERO", num[0]);
        // 2 - TWO
        num[2] = cnt[id('W')];
        update_cnt("TWO", num[2]);
        // 4 - FOUR
        num[4] = cnt[id('U')];
        update_cnt("FOUR", num[4]);
        // 3 - THREE
        num[3] = cnt[id('R')];
        update_cnt("THREE", num[3]);
        // 6 - SIX
        num[6] = cnt[id('X')];
        update_cnt("SIX", num[6]);
        // 8 - EIGHT
        num[8] = cnt[id('G')];
        update_cnt("EIGHT", num[8]);
        // 5 - FIVE
        num[5] = cnt[id('F')];
        update_cnt("FIVE", num[5]);
        // 7 - SEVEN
        num[7] = cnt[id('V')];
        update_cnt("SEVEN", num[7]);
        // 1 - ONE
        num[1] = cnt[id('O')];
        update_cnt("ONE", num[1]);
        // 9 - NINE
        num[9] = cnt[id('I')];
        update_cnt("NINE", num[9]);

        rep (i, 26) {
            if (cnt[i] != 0) {
                while(true);
            }
        }

        printf("Case #%d: ", Case++);
        rep (i, 10) {
            while (num[i] > 0) {
                --num[i];
                printf("%d", i);
            }
        }
        puts("");
    }
    return 0;
}