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

// #define DEBUGLEVEL
#ifdef DEBUGLEVEL
#define printf_debug(fmt, args...) fprintf(stderr, fmt, ##args)
#else
#define printf_debug(fmt, args...)
#endif

typedef long long llong;

using namespace std;

const int MAXN = 50;

char world[MAXN][MAXN], world_old[MAXN][MAXN], copy_world[MAXN][MAXN];
int n, m, c;

bool try_solve(int n, int m, int c) {
    //TODO 1, 2
    if(c == 0) {
        memset(world, '.', sizeof(world));
        world[0][0] = 'c';
        return true;
    }
    if(n == 1) return false;
    if(c == n * m - 1) {
        memset(world, '*', sizeof(world));
        world[0][0] = 'c';
        return true;
    }
    if(m == 1) {
        memset(world, '.', sizeof(world));
        if(n - c < 2) return false;
        for(int i = 0; i < c; ++i) {
            world[i][0] = '*';
        }
        world[n - 1][0] = 'c';
        return true;
    }
    if(m == 2) {
        memset(world, '.', sizeof(world));
        if(n > 2) return false;
        return c == 0; 
    }
    assert(m > 2);
    int safe_val = (m - 2) * n;
    if(c <= safe_val - 2 || c == safe_val) {
        if(n == 2 && c % 2 == 1) return false;
        memset(world, '.', sizeof(world));
        int tmp = c;
        for(int j = 0; j < m; ++j) {
            if(tmp == n - 1) {
                tmp--;
                world[0][j + 1] = '*';
            }
            for(int i = 0; i < n && tmp > 0; ++i) {
                world[i][j] = '*';
                tmp--;
            }
        }
        assert(world[0][m - 1] == '.');
        world[0][m - 1] = 'c';
        return true;
    }
    if(c == safe_val - 1 || (c - safe_val) % 2 == 1) {
        memset(world, '*', sizeof(world));
        int dots = n * m - c;
        assert(dots % 2 == 1);
        for(int h = 3; h < dots; ++h) {
            int w = dots / h;
            int carry = dots % h;
            int ww = (w + (carry > 0));
            if((carry == 0 || carry > 1) && ww > 2 && h <= n && ww <= m) {
                for(int i = 0; i < h; ++i) {
                    for(int j = 0; j < w; ++j) {
                        world[i][j] = '.';
                    }
                }
                for(int i = 0; i < carry; ++i) {
                    world[i][w] = '.';
                }
                world[0][0] = 'c';
                return true;
            }
            // if(dots % d == 0 && dots / d > 2) {
            //     int n_dots = d, m_dots = dots / d;
            //     if(n_dots <= n && m_dots <= m) {
            //         for(int i = 0; i < n_dots; ++i) {
            //             for(int j = 0; j < m_dots; ++j) {
            //                 world[i][j] = '.';
            //             }
            //         }
            //         world[0][0] = 'c';
            //         return true;
            //     }
            // }
        }
        // last trie
        return false;
    }
    if((c - safe_val) % 2 == 0) {
        int dots = 2 * n - (c - safe_val);
        if(dots <= 2) {
            return false;
        }
        memset(world, '.', sizeof(world));
        for(int j = 0; j < m - 2; ++j) {
            for(int i = 0; i < n; ++i) {
                world[i][j] = '*';
            }
        }
        for(int i = 0; i < (c - safe_val) / 2; ++i) {
            world[i][m - 1] = world[i][m - 2] = '*';
        }
        assert(world[n - 1][m - 1] == '.');
        world[n - 1][m - 1] = 'c';
        return true;
    }
    return false;
}

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
    int cnt_star = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            c_is_found |= (world[i][j] == 'c');
            cnt_star += (world[i][j] == '*');
        }
    }
    assert(cnt_star == c);
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
    printf_debug("CHECK\n");
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            printf_debug("%c", world[i][j]);
        }
        printf_debug("\n");
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
#ifdef DEBUG
    freopen("C-large.in", "r", stdin);
    freopen("C.out", "w", stdout);
#endif
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        cin >> n >> m >> c;
        bool res1 = try_solve(n, m, c);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                printf_debug("%c", world[i][j]);
            }
            printf_debug("\n");
        }
        printf_debug("%d\n", res1);
        assert(!res1 || (res1 && check_world(n, m, c)));
        memcpy(world_old, world, sizeof(world));
        bool res2 = try_solve(m, n, c);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                printf_debug("%c", world[i][j]);
            }
            printf_debug("\n");
        }
        printf_debug("%d\n", res2);
        assert(!res2 || (res2 && check_world(m, n, c)));
        printf("Case #%d:\n", t);
        if(res1) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    printf("%c", world_old[i][j]);
                }
                printf("\n");
            }
        } else if(res2) {
            printf_debug("OOOK\n");
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    printf("%c", world[j][i]);
                }
                printf("\n");
            }
        } else {
            printf("Impossible\n");
        }
    }
    return 0;
}