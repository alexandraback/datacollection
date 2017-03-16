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

int64 calc_answer(int64 n) {
    if (n == 0) return -1;
    set<int64> digits;
    for (int64 i = 1; i < 1000; ++i) {
        int64 m = n * i;
        while (m > 0) {
           digits.insert(m % 10);
           m /= 10;
        }
        if (sz(digits) == 10) return n * i;
    }
    return -1;
}

void solve() {
   int64 n;
   cin >> n;
   int64 answer = calc_answer(n);
   if (answer == -1) {
       cout << "INSOMNIA" << endl;
   } else {
       cout << answer << endl;
   }
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
