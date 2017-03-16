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
#define Maxn 10100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int R, n, m, k;
int b[Maxn];
vi p;
int cnt[20];
void init() {
    memset(b, true, sizeof(b));
    b[1] = false;
    for (int i = 2; i < Maxn; i++) {
        if (b[i]) {
            p.pb(i);
            for (ll j = i*i; j < Maxn; j+=i) b[j] = false;
        }
    
    }
}
int ms[Maxn];
void calc(int x) {
    for (int i = m; i >= 2; i --) {
        int tot = 0;
        while (x % i == 0) {
            tot++;
            x /= i;
        }
        cnt[i] = max(cnt[i], tot);
    }
}
void solve() {
    memset(cnt, 0, sizeof(cnt));
    REP(i, k) {
        calc(ms[i]);
    }
    int tot = 0;
    for (int i = 2; i <= m; i++) {
        while (cnt[i] && tot < n) {
            cout <<i;
            cnt[i]--;
            tot++;
        }
    }
    int tmp;
    while (tot < n) {
        tot ++;
        tmp = rand()%m + 2;
        tmp = min(tmp, m);
        cout <<tmp;
    }
    cout <<endl;
}
int main() {
    freopen("C-small-1-attempt3.in", "r", stdin);
    freopen("C-small-1-attempt3.out", "w", stdout);
    int T, ca = 0;
    cin >>T;
    //init();
    srand(time(NULL));
    while (T--) {
        cout <<"Case #" <<++ca <<":" <<endl;
        cin >>R >>n >>m >>k;
        REP(i, R) {
            REP(j, k) cin >>ms[j];
            solve();
        }
    }
    return 0;
}

