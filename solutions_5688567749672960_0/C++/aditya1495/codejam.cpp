//Aditya Shah

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

#define vi vector<int>
#define vs vector<string>
#define vpii vector<pii>
#define all(v) v.begin(), v.end()

#define fr freopen("input.in","r",stdin)
#define fw freopen("output.out","w",stdout)
#define fio fr; fw

#define foreach(i,X) for(__typeof((X).begin()) i = (X).begin(); i != (X).end(); i++)
#define forup(i,a,b) for(int i=(a); i<(b); ++i)
#define fordn(i,a,b) for(int i=(a); i>(b); --i)
#define rep(i,a) for(int i=0; i<(a); ++i)

#define gi(x) scanf("%d",&x)
#define gl(x) cin>>x
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf(" %s",x)

#define F first
#define S second

#define pb push_back
#define pf push_front
#define mp make_pair

#define wait system("pause")

const int inf = numeric_limits<int>::max();
const LL linf = numeric_limits<LL>::max();

int dp[1000005];

int reverse (int n) {
    int res = 0;
    while (n > 0) {
        res = res * 10 + (n % 10);
        n /= 10;

    }
    return res;
}

int main() {
    fio;
    int n, test;
    gi (test);
    fill (dp, dp + 1000001, inf/10);
    dp[1] = 1;
    forup (i, 2, 1000001) {
        dp[i] = dp[i - 1] + 1;
        if (i % 10 != 0) {
            dp[i] = min (dp[i], dp[reverse (i)] + 1);
        }
    }
    rep (t, test) {
        gi (n);
        printf ("Case #%d: %d\n", t + 1, dp[n]);
    }
    return 0;
}
