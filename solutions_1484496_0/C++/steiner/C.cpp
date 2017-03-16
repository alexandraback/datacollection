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
     int n;
     cin >> n;
     vector<int> a(n);
     for (int i = 0; i < n; ++i)
         cin >> a[i];
     bool ok = false;
     map<int, int> b;
     for (int i = 1; i < (1 << n); ++i) {
         int sum = 0;
         for (int j = 0; j < n; ++j)
            if (i & (1 << j))
                sum += a[j];
         if (b.find(sum) != b.end()) {
              cout << endl;
              for (int j = 0; j < n; ++j)
                  if (b[sum] & (1 << j))
                      cout << a[j] << " ";
              cout << endl;
              for (int j = 0; j < n; ++j)
                  if (i & (1 << j))
                      cout << a[j] << " ";
              cout << endl;
              ok = true;
              break;
         }
         b[sum] = i;
     }
     if (!ok) {
         cout << endl;
         cout << "Impossible" << endl;
     }
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
