#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <ctime>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define rep(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define sz size()
typedef long long ll;
const int N = 1000 + 11;

int ar[N];
int n, s, p;

bool ok(int t) {
    if (t >= 3 * p) return true;
    if (t < p) return false;

    int a = p;
    int b = (t - p + 1) / 2, c = t - a - b;
    if (c + 2 > a) return true;
    if (c + 2 == a) {
        if (s) {
            --s;
            return true;
        }
        return false;
    }
    return false;
}

int solve() {
    cin >> n >> s >> p;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
        if (ok(ar[i])) ++res;
    }
    return res;
}

int main() {
    int cas, tcas = 0;
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    for (cin >> cas, getchar(); cas; --cas) {
        printf("Case #%d: ", ++tcas);
        printf("%d\n", solve());
    }
}