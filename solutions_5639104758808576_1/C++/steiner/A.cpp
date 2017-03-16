#include <iostream>
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
    int s_max;
    cin >> s_max;
    string s;
    cin >> s;
    int ans = 0;
    int sum = 0;
    for (int i = 0; i <= s_max; ++i) {
       if (sum < i) {
           ans += (i - sum);
           sum = i;
       }
       sum += (s[i] - '0');
    }
    cout << ans << endl;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}
