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

char ch[N];

int T, cas, n;

int main(){
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> T;
    while (T --) {
        cin >> n;
        scanf(" %s", ch);
        int result = 0, tot = 0;
        for (int i = 0; i <= n; i ++) {
            int t = ch[i] - '0';
            if (tot + result < i) {
                result ++;
            }
            tot += t;
        }
        printf("Case #%d: %d\n", ++ cas, result);
    }
}
