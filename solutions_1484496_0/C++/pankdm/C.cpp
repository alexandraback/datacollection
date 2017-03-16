#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <queue>
#include <assert.h>
#include <deque>
#include <string.h>


using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

typedef vector <int> vi;
typedef vector <vi> vvi;

void output(int mask, const vi& a) {
    for (int i = 0; i < sz(a); ++i) {
        int bit = (1 << i);
        if (mask & bit) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}


void solve() {
    cout << endl;
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map <int, int> sums;
    map <int, int>::iterator it;

    for (int mask = 1; mask < (1 << n); ++mask) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int bit = (1 << i);
            if (mask & bit) {
                sum += a[i];
            }
        }
        it = sums.find(sum);
        if (it != sums.end()) {
            output(mask, a);
            output(it->second, a);
            return;
        } else {
            sums[sum] = mask;
        }
    }
    cout << "Impossbile" << endl;

}


int main () {
	//freopen("", "rt", stdin);
	//freopen("", "wt", stdout);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cout << "Case #" << t + 1 << ": ";
        solve();
    }

    return 0;
}

