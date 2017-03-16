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

LL reverse (LL n) {
    LL res = 0;
    while (n > 0) {
        res = res * 10 + (n % 10);
        n /= 10;

    }
    return res;
}

int Digits (LL n) {
    int res = 0;
    while (n > 0) {
        ++res;
        n /= 10;
    }
    return res;
}

LL p (LL base, LL power) {
    LL res = 1;
    while (power) {
        if (power & 1) {
            res = (res * base);
        }
        base = (base * base);
        power >>= 1;
    }
    return res;
}

LL solve (LL n) {
    if (n == 1) {
        return 1;
    }
    int digit = Digits (n);
    digit = (digit + 1) / 2;
    LL m = n % p (10, digit);
    LL ans = 0;
    if (m == 1 && n == reverse (n) ) {
        --n;
        ans = solve (n) + 1;
        return ans;
    } else if (n % 10 == 0) {
        --n;
        ans = solve (n) + 1;
        return ans;
    } else {
        ans = m;
        n -= (m - 1);
        if (n == reverse (n) ) --ans;
        n = reverse (n);
        ans += solve (n);
        return ans;
    }
}

int main() {
    fio;
    LL n, test;
    cin >> test;
    rep (t, test) {
        cin >> n;
        printf ("Case #%d: ", t + 1);
        cout << solve(n) << "\n";
    }
    return 0;
}
