#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define fi first
#define se second
#define rep(i, n) for (int i = 0, _##i = (n); i < _##i; ++i)

int motes[1000010];
int armin;
int n;
int pos, steps, mn;

void eat() {
    while (true) {
        mn = min(mn, steps + n - pos);
        if (armin > motes[pos]) {
            armin += motes[pos];
            pos++;
        }
        else break;
        mn = min(mn, steps + n - pos);
        if (pos == n) break;
//        cout << "TEST" << armin << endl;
    }
}

void game() {
    sort(motes, motes+n);
    pos = 0;
    steps = 0;
    mn = n;
    eat();
    while (armin <= motes[n-1]) {
        armin = 2*armin - 1;
        steps++;
        eat();
        if (pos == n) break;
    }
    cout << mn << "\n";
}

int main() {
    freopen("osmos.in","r",stdin); freopen("osmos.out","w",stdout);
    int t;
    cin >> t;
    rep(z, t) {
        cout << "Case #" << z+1 << ": ";
        cin >> armin;
        cin >> n;
	rep(i, n) cin >> motes[i];
        if (armin == 1) {
            cout << n << "\n";
            continue;
        }
        
        game();
    }
}