#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cassert>
#include<cstdio>
#include<cstring>
#include<ctime>

#define DEBUGLEVEL
#ifdef DEBUGLEVEL
#define printf_debug(fmt, args...) fprintf(stderr, fmt, ##args)
#else
#define printf_debug(fmt, args...)
#endif

typedef long long llong;

using namespace std;

const int MAXN = 30;

char world[MAXN][MAXN], copy_world[MAXN][MAXN];
int n, m, c;

inline bool is_valid(int n, int m, int i, int j) {
    return (0 <= i && i <= n - 1 && 0 <= j && j <= m - 1);
}

int cnt_ceil(int n, int m, int i, int j) {
    int res = 0;
    for(int mi = 0; mi < 3; ++mi) {
        for(int mj = 0; mj < 3; ++mj) {
            int ci = i - 1 + mi;
            int cj = j - 1 + mj;
            res += (is_valid(n, m, ci, cj) && world[ci][cj] == '*');
        }
    }
    return res;
}

int open_ceil(int n, int m, int i, int j) {
    int res = 0;
    if(world[i][j] == 'c') {
        int cur_cnt = cnt_ceil(n, m, i, j);
        assert(cur_cnt < 9);
        if(cur_cnt > 0) {
            world[i][j] = '0' + cur_cnt;
            return 0;
        }
    }
    for(int mi = 0; mi < 3; ++mi) {
        for(int mj = 0; mj < 3; ++mj) {
            int ci = i - 1 + mi;
            int cj = j - 1 + mj;
            if(is_valid(n, m, ci, cj) && (world[ci][cj] == '.' || world[ci][cj] == 'c')) {
                res++;
                world[ci][cj] = '0' + cnt_ceil(n, m, ci, cj);
            }
        }
    }
    return res;
}

bool check_world(int n, int m, int c) {
    memcpy(copy_world, world, sizeof(world));
    bool c_is_found = false;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            c_is_found |= (world[i][j] == 'c');
        }
    }
    if(!c_is_found) {
        memcpy(world, copy_world, sizeof(world));
        return false;
    }
    bool cont = true;
    while(cont) {
        cont = false;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(world[i][j] == 'c' || world[i][j] == '0') {
                    cont |= (open_ceil(n, m, i, j) > 0);
                }
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(world[i][j] == '.') {
                memcpy(world, copy_world, sizeof(world));
                return false;
            }
        }
    }
    memcpy(world, copy_world, sizeof(world));
    return true;
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        printf("Case #%d: \n", t);
        cin >> n >> m >> c;
        assert(n * m <= 28);
        bool res = false;
        for(int mask = 0; mask < (1 << (n * m)); ++mask) {
            int cnt = 0;
            for(int i = 0; i < n * m; ++i) {
                cnt += ((mask & (1 << i)) != 0);
            }
            assert(cnt <= n * m);
            if(cnt == c) {
                memset(world, '.', sizeof(world));
                for(int i = 0; i < n; ++i) {
                    for(int j = 0; j < m; ++j) {
                        if((mask & (1 << (i * m + j))) != 0) {
                            world[i][j] = '*';
                        }
                    }
                }
                for(int i = 0; i < n && !res; ++i) {
                    for(int j = 0; j < m && !res; ++j) {
                        if(world[i][j] == '.') {
                            world[i][j] = 'c';
                            res |= check_world(n, m, c);
                            if(res) {
                                for(int mi = 0; mi < n; ++mi) {
                                    for(int mj = 0; mj < m; ++mj) {
                                        printf("%c", world[mi][mj]);
                                    }
                                    printf("\n");
                                }
                            }
                            world[i][j] = '.';
                        }
                    }
                }
                if(res) break;
            }
        }
        if(!res) printf("Impossible\n");
    }
    return 0;
}