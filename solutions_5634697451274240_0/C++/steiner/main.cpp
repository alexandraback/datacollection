#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <functional>


#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

void solve() {
   string s;
   cin >> s;
   int n = sz(s);
   s.pb('+');
   int cnt = 0;
   for (int i = 0; i < n; ++i) {
      if (s[i] != s[i + 1]) ++cnt;
   }
   cout << cnt << endl;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int t;
    cin >> t;
    for (int test = 1; test <= t; ++test) {
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}
