//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 1005
#define maxX 2500

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int nTest, n, f[maxN], ans, dp[maxN], cnt;
vector<int> rf[maxN];

void DFS(int u, int block) {
    dp[u] = 1;
    forit(it, rf[u]) {
        int v = *it;
        if (v != block) {
            DFS(v, block);
            dp[u] = max(dp[u], dp[v]+1);
        }
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &nTest);
    fto(iTest, 1, nTest) {
        scanf("%d", &n);
        fto(i, 1, n) rf[i].clear();
        fto(i, 1, n) {
            scanf("%d", &f[i]);
            rf[f[i]].pb(i);
        }
        ans = 0;
        fto(i, 1, n) {
            memset(dp, 0, sizeof dp);
            cnt = 0;
            int x = i;
//            debug(i);
            while (dp[x] == 0) {
//                printf("%d ", x);
                dp[x] = ++cnt;
                x = f[x];
            }
//            puts("");
            ans = max(ans, cnt+1-dp[x]);
        }
//        debug(ans);
        cnt = 0;
        memset(dp, 0, sizeof dp);
        fto(u, 1, n) {
            fto(v, u+1, n) {
                if (f[u] == v && f[v] == u) {
//                    debug(u);
//                    debug(v);
//                    cnt += 1;
                    DFS(u, v);
                    DFS(v, u);
                    cnt += dp[u]+dp[v];
                }
            }
        }
//        fto(i, 1, n) printf("%d ", dp[i]);
//        puts("");
        //if (ans == 2) ans = 0;
        ans = max(ans, cnt);
        printf("Case #%d: %d\n", iTest, ans);
    }


    return 0;
}
