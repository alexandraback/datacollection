#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;


char s[110];

void solve() {
    scanf("%s", s);
    int n = strlen(s);
    bool flag = false;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if ((s[i] == '-') ^ flag) {
            flag = !flag;
            ans++;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int q = 1; q <= tc; q++) {
        printf("Case #%d: ", q);
        solve();
    }
    return 0;
}
