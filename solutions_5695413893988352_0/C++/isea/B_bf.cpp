/**
 * @author - iSea_baidu @ 2016-05-01 00:34
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

int len, ret, ret1, ret2;
char sret1[4], sret2[4];

void update_ret(char *s1, char *s2) {
    // NOTICE("update_ret %s %s", s1, s2);
    int x1 = stoi(s1), x2 = stoi(s2);
    if (abs(x1 - x2) < ret) {
        ret = abs(x1 - x2);
        ret1 = x1; ret2 = x2;
        strcpy(sret1, s1); strcpy(sret2, s2);
    } else if (abs(x1 - x2) == ret) {
        if (x1 < ret1 || (x1 == ret1 && x2 < ret2)) {
            ret1 = x1; ret2 = x2;
            strcpy(sret1, s1); strcpy(sret2, s2);
        }
    }
}

void dfs(char *s1, char *s2, int id1, int id2) {
    // NOTICE("%s %s %d %d", s1, s2, id1, id2);
    if (id2 == len) {
        update_ret(s1, s2);
        return;
    }
    if (id1 == len) {
        if (s2[id2] == '?') {
            for (char x = '0'; x <= '9'; ++x) {
                s2[id2] = x;
                dfs(s1, s2, id1, id2 + 1);
                s2[id2] = '?';
            }
        } else {
            dfs(s1, s2, id1, id2 + 1);
        }
        return;
    }
    if (s1[id1] == '?') {
        for (char x = '0'; x <= '9'; ++x) {
            s1[id1] = x;
            dfs(s1, s2, id1 + 1, id2);
            s1[id1] = '?';
        }
    } else {
        dfs(s1, s2, id1 + 1, id2);
    }
}

int main() {
    repcase {
        char s1[4], s2[4];
        scanf("%s%s", s1, s2);
        len = strlen(s1);
        ret = (-1u) >> 1;
        dfs(s1, s2, 0, 0);
        printf("Case #%d: %s %s\n", Case++, sret1, sret2);
    }
    return 0;
}