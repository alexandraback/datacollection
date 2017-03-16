#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
using namespace std;

typedef long long int64;
#define PB(a) push_back(a)
#define MP(a, b) make_pair(a, b)
#define PROBLEM "B"

const int MAXN = 128;
const int64 MOD = 1000000007;

string a[MAXN];
int mem[256][2][2];
bool was[256];
int64 fact[MAXN];
int bgc[256], enc[256];
int bg[MAXN], en[MAXN];
bool mark[MAXN];

int main() {
    freopen(PROBLEM ".in", "rt", stdin);
    freopen(PROBLEM ".out", "wt", stdout);

    fact[0] = 1;
    for (int64 i = 1; i < MAXN; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }

    int T;
    scanf("%d\n", &T);

    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);

        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cerr << a[i] << " ";
        }
        cerr << endl;
        
        memset(mem, 0, sizeof mem);
        memset(was, 0, sizeof was);
        
                bool ok = true;

        
        for (int i = 0; i < n; i++) {
            int m = a[i].size();
            int p = 0;
            int start = 1;
            for (int j = 0; j < m; j++) {
                int c = a[i][j];
                was[c] = true;
                if (c != p) {
                    if (j > 0) {
                        mem[p][start][0]++;
                        start = 0;
                    }
                    p = c;
                }
            }
            mem[p][start][1]++;
            
            if (a[i][0] == a[i][m-1] && start != 1) {
                ok = false;
            }
        }
        
        for (int c = 'a'; c <= 'z'; c++) {
            if (!was[c]) continue;
            
            if (mem[c][0][0] > 0) {
                if (mem[c][0][0] > 1) {
                    ok = false;
                }
                if (mem[c][1][0] > 0 || mem[c][0][1] > 0 || mem[c][1][1] > 0) {
                    ok = false;
                }
            }
            if (mem[c][1][0] > 1 || mem[c][0][1] > 1) {
                ok = false;
            }
        }
        
        if (!ok) {
            printf("0");
        } else {
            memset(bg, -1, sizeof bg);
            memset(en, -1, sizeof en);
            
            memset(bgc, -1, sizeof bgc);
            memset(enc, -1, sizeof enc);
            
            for (int c = 'a'; c <= 'z'; c++) {
                if (!was[c]) continue;
            
                if (mem[c][1][0] == 1) {
                    for (int i = 0; i < n; i++) {
                        int m = a[i].size();
                        if (a[i][0] == c && a[i][m-1] != c) {
                            assert(bg[i] == -1);
                            bg[i] = c;
                            assert(bgc[c] == -1);
                            bgc[c] = i;
                        }
                    }
                    assert(bgc[c] != -1);
                }
                
                if (mem[c][0][1] == 1) {
                    for (int i = 0; i < n; i++) {
                        int m = a[i].size();
                        if (a[i][m-1] == c && a[i][0] != c) {
                            assert(en[i] == -1);
                            en[i] = c;
                            assert(enc[c] == -1);
                            enc[c] = i;
                        }
                    }
                    assert(enc[c] != -1);
                }
            }
            
//             for (int c = 'a'; c <= 'z'; c++) {
//                 if (!was[c]) continue;
//                 cerr << bgc[c] << "," << enc[c] << " ";
//             }
//             cerr << endl;
//             
//             for (int i = 0; i < n; i++) {
//                 if (bg[i] != -1 || en[i] != -1) {
//                     cerr << bg[i] << "," << en[i] << " ";
//                 }
//             }
//             cerr << endl;

            
            memset(mark, 0, sizeof mark);
            for (int i = 0; i < n; i++) {
                if (bg[i] != -1 && enc[bg[i]] == -1) {
                    int v = i;
                    while (v != -1) {
                        if (mark[v]) {
                            ok = false;
                            cerr << t << " " << "F1" << endl;
                        } else {
                            mark[v] = true;
                        }
                        int c = en[v];
                        assert(c != -1);
                        v = bgc[c];
                    }
                }
            }
            
            for (int i = 0; i < n; i++) {
                if (bg[i] != -1 || en[i] != -1) {
                    if (!mark[i]) {
                        ok = false;
                        cerr << t << " " << "F2" << endl;
                    }
                }
            }

            if (!ok) {
                printf("0");
            } else {
                int64 res = 1;
                int chain = 0;
            
                for (int c = 'a'; c <= 'z'; c++) {
                    if (!was[c]) continue;
                
                    if (mem[c][1][0] == 1 && mem[c][0][1] == 1) {
                        res = (res * fact[mem[c][1][1]]) % MOD;
                    }
                    if (mem[c][1][0] == 1 && mem[c][0][1] == 0) {
                        res = (res * fact[mem[c][1][1]]) % MOD;
                        chain++;
                    }
                    if (mem[c][1][0] == 0 && mem[c][0][1] == 1) {
                        res = (res * fact[mem[c][1][1]]) % MOD;
                        chain++;
                    }
                    if (mem[c][1][0] == 0 && mem[c][0][1] == 0) {
                        if (mem[c][1][1] > 0) {
                            res = (res * fact[mem[c][1][1]]) % MOD;
                            chain += 2;
                        }
                    }
                }
            
                assert(chain % 2 == 0);
                chain = chain / 2;
            
                res = (res * fact[chain]) % MOD;
            
                cout << res;
            }
        }
        
        printf("\n");
    }

    return 0;
}
