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

const int MAXN = 2000;

double a[MAXN], b[MAXN];

int main() {
#ifdef DEBUG
    freopen("D-large.in", "r", stdin);
    freopen("D.out", "w", stdout);
#endif
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for(int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + n);
        int cnt[2] = {0, n}, pa = n - 1, pb = n - 1;
        while(pa >= 0 && pb >= 0) {
            if(a[pa] > b[pb]) {
                cnt[0]++, pa--, pb--;
            } else {
                pb--;
            }
        }
        pa = n - 1, pb = n - 1;
        while(pa >= 0 && pb >= 0) {
            if(a[pa] < b[pb]) {
                cnt[1]--, pa--, pb--;
            } else {
                pa--;
            }
        }
        printf("Case #%d: %d %d\n", t, cnt[0], cnt[1]);
    } 
    return 0;
}