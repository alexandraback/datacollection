#include<bits/stdc++.h>
#define mp make_pair
#define esp 1e-18
#define lson   l, m, rt<<1
#define rson   m+1, r, rt<<1|1
#define sz(x) ((int)((x).size()))
#define lowbit(x) ((x)&(-(x)))
#define pf(x) ((x)*(x))
#define pb push_back
#define pi acos(-1.0)
#define in freopen("subpair.in", "r", stdin);
#define out freopen("subpair.out", "w", stdout);
#define IN freopen("A-small-attempt1.in", "r", stdin);
#define OUT freopen("solve_out.txt", "w", stdout);
#define bug(x) cout << "Line : " << (x) << endl;
#define TL cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#define inf 0x0f0f0f0f
using namespace std;


typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned US;
typedef pair<int, int> PII;
typedef map<PII, int> MPS;
typedef MPS::iterator IT;

const int maxn = (int)1e6 + 10;
int dp[maxn];
int rev(int x) {
    vector<int> dig;
    while (x) {
        dig.push_back(x%10);
        x /= 10;
    }
    int len = dig.size();
    int res = 0;
    for (int i = 0; i < len; i++) {
        res = res * 10 + dig[i];
    }
    return res;
}
int n;

int dfs(int x) {
//    if (x >= (int)1e6 + 10)
//        bug(1)
    int &res = dp[x];
    if (res != -1) return res;
    res = 1+dfs(x+1);
    if (rev(x) > x && rev(x) <= n) res = min(res, 1+dfs(rev(x)));
    return res;
}
int main() {
//    IN
//    OUT
int ss = 256 << 20; // 256MB
char *p = (char*)malloc(ss) + ss;
__asm__("movl %0, %%esp\n" :: "r"(p));
    int T;
//    int n;
    for (int t = scanf("%d", &T); t <= T; t++) {
        scanf("%d", &n);
//        cout << n << endl;
        memset(dp, -1, sizeof dp);
        dp[n] = 1;
        printf("Case #%d: %d\n", t, dfs(1));
    }
    return 0;
}
