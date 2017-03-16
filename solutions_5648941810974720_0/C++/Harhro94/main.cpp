#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <cassert>
#include <map>
#include <string>
#include <iomanip>
#include <set>
#include <queue>
#include <ctime>
#include <vector>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define sz(v) (int)(v).size()
#define mp make_pair
#define all(v) (v).begin(), (v).end()
typedef long double LD;
//typedef long long LL;

const int N = 2007;
char st[N];
LD mat[26][11], x[10];
int cnt[26];
string names[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void solve() {
    int T;
    scanf("%d", &T);
    for (int test = 1; test <= T; ++test) {
        scanf("%s", st);
        int st_len = strlen(st);
        memset(cnt, 0, sizeof cnt);
        FOR(i, st_len) ++cnt[st[i] - 'A'];
        memset(mat, 0, sizeof mat);
        FOR(r, 26) {
            mat[r][10] = cnt[r];
            FOR(j, 10) {
                mat[r][j] = count(all(names[j]), 'A'+r);
            }
        }
        FOR(r, 10) {
            int pos = r;
            for (int i = r + 1; i < 26; ++i) {
                if (fabsl(mat[i][r]) > fabsl(mat[pos][r])) pos = i;
            }
            FOR(j, 11) swap(mat[r][j], mat[pos][j]);
            for (int i = r + 1; i < 26; ++i) {
                for (int j = 10; j >= r; --j) {
                    mat[i][j] += -mat[i][r] / mat[r][r] * mat[r][j];
                }
            }
        }
        for (int i = 9; i >= 0; --i) {
            LD cur = mat[i][10];
            for (int j = i + 1; j < 10; ++j) cur -= mat[i][j] * x[j];
            cur /= mat[i][i];
            x[i] = cur;    
        }

        printf("Case #%d: ", test);
        FOR(i, 10) {
            int cnt = (int)(x[i] + 0.5);
            FOR(j, cnt) putchar('0' + i);
        }
        puts("");
    }
}

void testgen() {
    FILE *f = fopen("input.txt", "w");
    srand(time(0));
    fclose(f);
}

int  main(int argc, char* argv[]) {
#ifdef harhro94
    //testgen();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    #define task "estimate"
    //freopen(task".in", "r", stdin);
    //freopen(task".out", "w", stdout);
#endif

    solve();

#ifdef harhro94
    cerr << "\ntime = " << clock() / 1000.0 << endl;
#endif
    return 0;
}