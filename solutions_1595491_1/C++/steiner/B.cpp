#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

void solve() {
     int n, s, p;
     cin >> n >> s >> p;
     vector<int> a(n);
     for (int i = 0; i < n; ++i)
        cin >> a[i];
     sort(all(a));
     int ans = 0;
     for (int i = 0; i < n; ++i)
         if ((a[i] + 2) / 3 >= p)
            ++ans;
     for (int i = n - 1; i >= 0; --i)
         if (s > 0 && (a[i] + 2) / 3 == p - 1 && a[i] % 3 != 1 && a[i] >= 2 && a[i] <= 28) {
               ++ans;
               --s;
         }
     cout << ans << endl;
}
 
int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int t;
    cin >> t;
    for (int tests = 0; tests < t; ++tests) {
        cout << "Case #" << tests + 1 << ": ";
        solve();
    }   
    return 0;
}
