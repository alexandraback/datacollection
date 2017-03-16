#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(i,a,b) for(int i=a; i>=b; i--)
#define FORAD(i,u) for(int i=0; i < (int)u.size();i++)
#define BUG(x) cout << x << endl
#define BUGA(x, n, a, b) for (int i = a; i <= b; i++) cout << x[i] << ' '; cout << endl;
#define ll long long
#define fi first
#define sd second
#define pb push_back
#define two(i) (1 << i)
#define getbit(x, pos) ((x >> (pos - 1)) & 1)
#define sz(x) (int)x.size()

template <class T> T gcd(T x, T y) {
    if (x > y) swap(x, y); while (x != 0) {T r = y % x; y = x; x = r; } return y;
}
template<class T> int cntbit(T s) { return __builtin_popcountll(s);}


const int esp = (int)(1e9);
const double pi = acos(-1);
const int base = 1;
typedef pair<int,int> II;

int main() {
    // freopen("A-small-attempt0.in","r",stdin);
    // freopen("ans.out", "w", stdout);
    int test, n;
    string s;
    cin >> test;
    FOR(t, 1, test) {
        cin >> n >> s;
        int res = 0, sum = 0;
        FOR(i, 0, sz(s) - 1) {
            if (s[i] != '0' && sum < i) {
                res += i - sum;
                sum = i;
            }
            sum += s[i] - '0';
        }
        printf("Case #%d: %d\n", t, res);
    }
    // freopen("","w",stdout);
     return 0;
}

