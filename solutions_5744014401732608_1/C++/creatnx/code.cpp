#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <complex>
#include <cstring>

using namespace std;
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define repd(i, a, b) for(int i = (a); i > (b); i--)
#define forIt(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define forRev(it, a) for(__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
#define ft(a) __typeof((a).begin())
#define ll long long
#define ld long double
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define sz(a) (a).size()
#define all(a) (a).begin(), (a).end()
#define Rep(i,n) for(int i = 0; i < (n); ++i)

typedef complex<ld> cplex;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int N = 1e6 + 7;
const int M = 107;
const int mod = 998244353;
const int inf = 1e9 + 7;
const double pi = acos(-1);
const int maxn = N * 2;
const double PI = acos(-1);

int dp[10][30];
int can[30];
int b;
ll m;
int a[60][60];
ll lt[60];

void init() {
    lt[1] = lt[2] = 1;
    rep(i, 3, 60) lt[i] = lt[i - 1] * 2;
    //cout << lt[5] << "\n";
}

void solve() {
    cin >> b >> m;
    //cout << m << " " <
    rep(i, 1, b + 1) rep(j, 1, b + 1) a[i][j] = 0;
    if (m <= lt[b]) {
        puts("POSSIBLE");
        rep(i, 1, b) {
            rep(j, i + 1, b) {
                a[i][j] = 1;
            }
        }
        if (m == lt[b]) {
            rep(i, 1, b) a[i][b] = 1;
        } else {
            rep(i, 1, b - 1) {
                if (m & 1) a[i + 1][b] = 1;
                m >>= 1;
            }
        }
        rep(i, 1, b + 1) {
            rep(j, 1, b + 1)
            printf("%d", a[i][j]);
            puts("");
        }
    } else {
        puts("IMPOSSIBLE");
    }
    
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    init();
    int T = 1;
    cin >> T;
    rep(i, 1, T + 1) {
        printf("Case #%d: ", i);
        solve();
        //puts("");
    }
}