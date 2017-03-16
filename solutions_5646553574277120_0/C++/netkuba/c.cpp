#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void solve(int t) {
    int c, d, v;
    cin >> c >> d >> v;
    vector<int> nominal;
    for (int i=0; i<d; ++i) {
        int n;
        cin >> n;
        nominal.push_back(n);
    }

    int used = 0;
    int result = 0;
    long long maximal = 0;
    while (maximal < v) {
        if (used < nominal.size() && nominal[used] <= maximal + 1) {
            maximal += (long long)nominal[used] * c;
            ++used;
            continue;
        }
        maximal += (maximal+1) * c;
        result += 1;
    }
    
    printf("Case #%d: %d\n", t, result);
}

int main() {
    int t;
    cin >> t;
    for (int tt=1; tt<=t; ++tt) {
        solve(tt);
    }
}
