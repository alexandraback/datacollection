#pragma  comment(linker, "/STACK:36777216")
#include <bits/stdc++.h>
#define  lc(x) (x << 1)
#define  rc(x) (lc(x) + 1)
#define  lowbit(x) (x & (-x))
#define  PI    (acos(-1))
#define  lowbit(x) (x & (-x))
#define  LL    long long
#define  DB    double
#define  ULL   unsigned long long
#define  PII   pair<int, int>
#define  PLL   pair<LL, LL>
#define  PB    push_back
#define  MP    make_pair

using namespace std;

const int N = 2005;
const int M = N * N * 2;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const DB  EPS = 1e-8;

int T, cas, n, a[N];

int main(){
    freopen("B-large.in", "r", stdin);
    freopen("test.out", "w", stdout);
    cin >> T;
    while (T --) {
        cin >> n;
        for (int i = 0; i < n; i ++)
            scanf("%d", &a[i]);
        int result = INF;
        for (int i = 1; i <= 1000; i ++) {
            int sum = i;
            for (int j = 0; j < n; j ++) {
                sum += (a[j] - 1) / i;
            }
            result = min(result, sum);
        }
        printf("Case #%d: %d\n", ++ cas, result);
    }
}
