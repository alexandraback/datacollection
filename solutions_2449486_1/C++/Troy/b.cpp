#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define ll long long
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

const int Maxn = 111;
int a[Maxn][Maxn];
int r[Maxn], c[Maxn];
int n, m;
bool solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] < r[i] && a[i][j] < c[j]) return false;
        }
    }
    return true;
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    //freopen("B-small-attempt0.in", "r", stdin);
    //freopen("B-small-attempt0.out", "w", stdout);
    int T, ca = 0;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        memset(r, 0, sizeof(r));
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                r[i] = max(r[i], a[i][j]);
                c[j] = max(c[j], a[i][j]);
            }
        }
        cout <<"Case #" <<++ca <<": ";
        if (solve()) cout <<"YES" <<endl;
        else cout <<"NO" <<endl;
    }
    return 0;
}

