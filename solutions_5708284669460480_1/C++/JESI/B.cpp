#include <bits/stdc++.h>

using namespace  std;

//using ll = long long;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

//using pii = pair <int , int>;
//using pll = pair <ll , ll>;
//const ll inf = 1;
//const ll mod = 1E9;

#define SZ 110

char kbrd[SZ], trgt[SZ];
int k, l, s;

double dp[SZ][SZ];
int col[SZ][SZ];
int par[SZ];

int dp1[SZ][SZ];
int solve1 (int pos, char ch) {
    int &ret = dp1[pos][ch-'A'];
    if (ret != -1) return ret;
    while (pos && trgt[pos] != ch) pos = par[pos-1];
    if (trgt[pos] == ch) pos++;
    return ret = pos;
}

int mx;

double solve (int pos, int mch) {
    if (mch == l) mch = par[mch-1];
    if (pos == s) return 0;
    double &ret = dp[pos][mch];
    if (col[pos][mch]) return ret;
    col[pos][mch] = 1;
    ret = 0;
    for (int i = 0; i < k; i++) {
        int tpos = solve1(mch, kbrd[i]);
        ret = max(ret, (tpos == l) + solve(pos + 1, tpos));
    }
    return ret;
}

double power (int k, int pos) {
    double ans = 1.0;
    for (int i = 0; i < pos; i++) {
        ans = ans * (double)k;
    }
    return ans;
}

double solve2 (int pos, int mch) {
    if (mch == l) mch = par[mch-1];
    if (pos == s) return (double)mx;
    double &ret = dp[pos][mch];
    if (col[pos][mch]) return ret;
    col[pos][mch] = 1;
    ret = 0;
    for (int i = 0; i < k; i++) {
        int tpos = solve1(mch, kbrd[i]);
        ret = ret + solve2(pos + 1, tpos) - power(k, s - pos - 1) * (tpos == l);
    }
    return ret;
}

int main() {
//    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
//    #endif

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        scanf("%d %d %d", &k, &l, &s);
        scanf("%s %s", kbrd, trgt);

        int K = k;

        mem(col, 0);
        mem(dp1, -1);

        int k = 0;
        par[0] = 0;
        for(int i = 1; i < l; i++) {
            while(k > 0 && trgt[i] != trgt[k]) k = par[k-1];
            if(trgt[i] == trgt[k]) k++;
            par[i] = k;
        }

        mx = solve(0, 0);

        mem(col, 0);

        double ans = solve2(0, 0);

//        cout << "Pre  = " << fixed << setprecision(10) << ans << '\n';

        for (int i = 0; i < s; i++)
            ans = ans / (double)K;

//        cout << "Post = " << fixed << setprecision(10) << ans << '\n';
        printf("Case #%d: %.10lf\n", cs + 1, ans);
    }


    return 0;
}







