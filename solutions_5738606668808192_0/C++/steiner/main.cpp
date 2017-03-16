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
    int n = 16;
    int j = 50;
    vector<string> answers;
    for (int i1 = 1; i1 < n - 1; i1 += 2)
    for (int i2 = i1 + 2; i2 < n - 1; i2 += 2)
    for (int j1 = 2; j1 < n - 1; j1 += 2)
    for (int j2 = j1 + 2; j2 < n - 1; j2 += 2) {
       string result(n, '0');
       result[0] = '1';
       result[n - 1] = '1';
       result[i1] = '1';
       result[i2] = '1';
       result[j1] = '1';
       result[j2] = '1';
       answers.pb(result);
       if (sz(answers) == j) break;
    }
    for (int i = 0; i < j; ++i) {
        cout << answers[i];
        for (int k = 2; k <= 10; ++k) {
           if (k % 2 == 0) {
               cout << " " << k + 1;
           } else {
               cout << " " << 2;
           }
        }
        cout << endl;
    }
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int t;
    cin >> t;
    for (int test = 1; test <= t; ++test) {
        cout << "Case #" << test << ":" << endl;
        solve();
    }
    return 0;
}
