/**
 * @author - iSea_baidu @ 2016-05-01 01:53
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

struct state {
    long long x, y;
    bool updated;
};

state dp[19][4];

bool can_update(long long x, long long y, long long nx, long long ny) {
    return (nx < x || (nx == x && ny < y));
}

bool can_update(state s, long long x, long long y) {
    return can_update(s.x, s.y, x, y);
}

void update(int i, long long x, long long y) {
    if (x >= y) {
        long long dif = x - y;
        if (!dp[i][0].updated || dif > dp[i][0].x - dp[i][0].y) {
            dp[i][0] = {x, y, true};
        } else if (dif == dp[i][0].x - dp[i][0].y && can_update(dp[i][0], x, y)) {
            dp[i][0] = {x, y, true};
        }

        if (!dp[i][1].updated || dif < dp[i][1].x - dp[i][1].y) {
            dp[i][1] = {x, y, true};
        } else if (dif == dp[i][1].x - dp[i][1].y && can_update(dp[i][1], x, y)) {
            dp[i][1] = {x, y, true};
        }
    } else {
        long long dif = x - y;
        if (!dp[i][2].updated || dif > dp[i][2].x - dp[i][2].y) {
            dp[i][2] = {x, y, true};
        } else if (dif == dp[i][2].x - dp[i][2].y && can_update(dp[i][2], x, y)) {
            dp[i][2] = {x, y, true};
        }

        if (!dp[i][3].updated || dif < dp[i][3].x - dp[i][3].y) {
            dp[i][3] = {x, y, true};
        } else if (dif == dp[i][3].x - dp[i][3].y && can_update(dp[i][3], x, y)) {
            dp[i][3] = {x, y, true};
        }
    }
}

bool can_match(char *s, int i, int num) {
    return s[i] == '?' || (s[i] - '0' == num);
}

void output(int fixlen, long long x) {
    char buf[20];
    sprintf(buf, "%lld", x);
    string s(buf);
    while (SZ(s) != fixlen) {
        s = '0' + s;
    }
    printf(" %s", s.c_str());
}

int main() {
    repcase {
        char s1[19], s2[19];
        scanf("%s%s", s1, s2);
        int len = strlen(s1);
        rep (i, 4) {
            dp[len][i] = {0, 0, true};
        }
        long long w = 1LL;
        for (int i = len - 1; i >= 0; --i) {
            rep (p, 4) {
                dp[i][p] = {0, 0, false};
            }
            rep (x, 10) rep (y, 10) {
                if (can_match(s1, i, x) && can_match(s2, i, y)) {
                    rep (p, 4) if (dp[i + 1][p].updated) {
                        long long next_x = dp[i + 1][p].x + x * w;
                        long long next_y = dp[i + 1][p].y + y * w;
                        update(i, next_x, next_y);
                    }
                }
            }
            w *= 10;
        }
        state ret = {0, 0, false};
        rep (p, 4) {
            if (!dp[0][p].updated) continue;
            if (!ret.updated || abs(ret.x - ret.y) > abs(dp[0][p].x - dp[0][p].y)) {
                ret = dp[0][p];
            } else if (abs(ret.x - ret.y) == abs(dp[0][p].x - dp[0][p].y) 
                        && can_update(ret, dp[0][p].x, dp[0][p].y)) {
                ret = dp[0][p];
            }
        }
        printf("Case #%d:", Case++);
        output(len, ret.x);
        output(len, ret.y);
        puts("");
    }
    return 0;
}