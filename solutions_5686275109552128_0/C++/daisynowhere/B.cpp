#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <sstream>
#include <iomanip>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair <int, int> PII;
const int N = 1005;
int Tc, n;
int a[N];

int main() {
    scanf("%d", &Tc);
    rep (ri, Tc) {
        scanf("%d", &n);
        rep (i, n) scanf("%d", &a[i]);
        int ans = 0x7FFFFFFF;
        for (int i = 1; i <= 1000; i++) {
            int movecnt = 0;
            rep (j, n) {
                movecnt += (a[j] + i - 1) / i - 1;
            }
            ans = min(ans, i + movecnt);
        }
        printf("Case #%d: %d\n", ri + 1, ans);
    }
}

