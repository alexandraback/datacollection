#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define red(i, a, b) for(int i = a; i > b; i--)
#define RED true
#define BLACK false
#define pb push_back
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ii, int> iii;
typedef vector<int> vi;
const int N = 20 + 7;
const int M = 1e9;
const int inf = 1e9 + 7;
const ll base = 1e18;
const double pi = acos(-1);
const double ep = 1e-9;


ll L[N][N];
ll dp[N][120];
int n, p[N];

void init(){
    rep(i, 0, N)
        rep(j, 0, N)
            L[i][j] = inf;
    L[0][0] = 0;
    L[1][0] = 1;
    rep(i, 2, N - 3){
        rep(j, 0, i + 1){
            L[i][j] = L[i-1][j] + 1;
            rep(t, 0, j){
                rep(u, 1, i)
                    L[i][j] = min(L[i][j], max(L[u][t]+j-1-t, L[i-u][j-1-t] + t) + 1);
            }
            if (L[i][j] > inf) L[i][j] = inf;
        }
    }
}

int go(){
    scanf("%d", &n);
    int mx = 0;
    rep(i, 1, n + 1){
        scanf("%d", &p[i]);
        mx = max(mx, p[i]);
    }
    mx = 10 * n;
    rep(i, 0, n + 1){
        rep(j, 0, mx + 1)
            dp[i][j] = inf;
    }

    dp[0][0] = 0;
    rep(i, 1, n + 1){
        dp[i][0] = max(L[p[i]][0], dp[i-1][0]);
        //int k = log(p[i]) / log(2);
        rep(j, 1, mx + 1){
            dp[i][j] = max(L[p[i]][0] + j, dp[i-1][j]);
            rep(t, 0, p[i] + 1){
                if (j >= t){
                    dp[i][j] = min(dp[i][j], max(dp[i-1][j-t] + t, L[p[i]][t] + j - t));
                }
            }
        }
    }
    int res = 0;
    rep(i, 0, mx + 1)
        if (dp[n][res] > dp[n][i])
            res = i;
    return dp[n][res];
}



int main(){
    freopen("B-small-attempt3.in", "r", stdin);
    //freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    init();
    int test;
    cin >> test;
    rep(i, 1, test + 1){
        printf("Case #%d: %d\n", i, go());
    }

}
