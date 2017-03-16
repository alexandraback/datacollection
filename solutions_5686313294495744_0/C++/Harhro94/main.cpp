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
//typedef long double LD;
typedef long long LL;

const int N = 1007;
int n;
string A[N], B[N];

bool can(int mask) {
    set<string> as, bs;
    FOR(j, n) {
        if (((mask >> j) & 1) == 0) {
            as.insert(A[j]);
            bs.insert(B[j]);
        }
    }
    FOR(j, n) {
        if ((mask >> j) & 1) {
            if (!as.count(A[j])) return false;
            if (!bs.count(B[j])) return false;
        }
    }
    return true;
}

int brute_force() {
    int ans = 0;
    FOR(mask, (1 << n)) {
        int cnt = 0;
        FOR(j, n) {
            if ((mask >> j) & 1) ++cnt;
        }
        if (can(mask)) ans = max(ans, cnt);
    }
    return ans;
}

void solve() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        cerr << "test = " << test << endl;
        printf("Case #%d: ", test);
        cin >> n;
        FOR(i, n) {
            cin >> A[i] >> B[i];
        }
        int ans = brute_force();
        printf("%d\n", ans);
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