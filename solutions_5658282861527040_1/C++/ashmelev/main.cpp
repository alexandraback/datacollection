#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define y0 y32479
#define y1 y95874
#define fill(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define unq(x) (x.resize(unique(all(x)) - x.begin()))
#define spc(i,n) " \n"[i == n - 1]

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

template<class T> T abs(T x) { return x > 0 ? x : -x;}

#define FILENAME ""

int m;
int n;

int aa[50], bb[50], cc[50];
ll table[50][2][2][2];

void parse(int x, int* a) {
    rep(i, 31) {
        if (x & (1 << i))
            a[i] = 1;
        else
            a[i] = 0;
    }
}

ll getans(int p, int f1, int f2, int f3) {
    if (p < 0)
        re 1;
    ll &ans = table[p][f1][f2][f3];
    if (ans != -1)
        re ans;
    ans = 0;

    rep(i, 2) rep(j, 2) {
        int c = (i & j);
        if (!f3 && c == 1 && cc[p] == 0)
            continue;
        if (!f1 && i == 1 && aa[p] == 0)
            continue;
        if (!f2 && j == 1 && bb[p] == 0)
            continue;

        ans += getans(p - 1,
                f1 || (aa[p] == 1 && i == 0),
                f2 || (bb[p] == 1 && j == 0),
                f3 || (c == 0 && cc[p] == 1));
    }
    re ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tc;
    cin >> tc;
    rep(tt, tc) {
        int a, b, c;
        cout << "Case #" << tt + 1 << ": ";
        cin >> a >> b >> c;
        a--;
        b--;
        c--;
        fill(table, -1);
        parse(a, aa);
        parse(b, bb);
        parse(c, cc);
        cout << getans(30, 0, 0, 0) << endl;
    }

    re 0;
}
