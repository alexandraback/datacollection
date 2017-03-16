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
     int A, B;
     cin >> A >> B;
     stringstream ss;
     ss << A;
     int len = sz(ss.str());
     int deg = 1;
     for (int i = 0; i + 1 < len; ++i)
         deg *= 10;
     int64 ans = 0;
     for (int n = A; n <= B; ++n) {
         set<int> b;
         int m = n;
         for (int j = 0; j + 1 < len; ++j) {
             m = m / 10 + deg * (m % 10);
             if (m < n && m >= A && b.find(m) == b.end()) {
                b.insert(m);
                ++ans;
             }
         }
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
