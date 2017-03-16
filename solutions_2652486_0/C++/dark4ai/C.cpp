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

int r, n, m, k;
int ps[10];

int x[4];


bool ext = false;

void rec(int d) {
    if(d == n) {
        // printf_debug("%d %d %d\n", x[0], x[1], x[2]);
        ext = true;
        for(int j = 0; j < k; ++j) {
            bool gd = false;
            for(int i = 0; i < (1 << n); ++i) { 
                int pr = 1;
                for(int l = 0; l < n; ++l) {
                    if((i & (1 << l)) > 0)
                        pr *= x[l];
                }
                if(ps[j] == pr) {
                    gd = true;
                }
            }
            if(!gd) {
                ext = false;
                break;
            }
        }
        return;
    }
    for(int i = 2; i <= m; ++i) {
        x[d] = i;
        rec(d + 1);
        if(ext) return;
    }
}

int main() {
#ifdef DEBUG
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
#endif
    int T;
    cin >> T;
    for(int test = 1; test <= T; ++test) {
        cin >> r >> n >> m >> k;
        cout << "Case #1:" << endl;;
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < k; ++j) {
                cin >> ps[j];
            }
            ext = false;
            rec(0);
            for(int i = 0; i < n; ++i) {
                cout << x[i];
            }
            cout << endl;
        }
    }
    return 0;
}