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
     int sum = 0;
     for (int i = 0; i < n; ++i)
         sum += a[i];
     for (int i = 0; i < n; ++i) {
         double left = 0;
         double right = 1;
         for (int step = 0; step < 500; ++step) {
              double m = (left + right) / 2;
              double res = m;
              for (int j = 0; j < n; ++j)
                  if (i != j) {
                      double val = max(0.0, (double)(m * sum + a[i] - a[j]) / sum);
                      res += val;
                  }
              if (res > 1)
                   right = m;
              else
                   left = m;
         }
         printf("%.10lf ",  100.0 * left);
     }
     cout << endl;
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
