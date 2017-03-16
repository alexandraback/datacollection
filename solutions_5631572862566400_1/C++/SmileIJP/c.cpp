#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <utility>

typedef long long ll;

using namespace std;

template<typename T>
T next() { T tmp; cin >> tmp; return tmp; }

void solve() {
    int n = next< int >();
    vector< int > f(n);
    vector< bool > was(n);
    generate(f.begin(), f.end(), next< int >);
    for (size_t i = 0; i < f.size(); ++i) {
        f[i]--;
    }
    int ans = 0;

    for (size_t i = 0; i < f.size(); ++i) {
        fill(was.begin(), was.end(), false);
        int q = i;
        int size = 0;
        for (; !was[q]; q = f[q]) {
            was[q] = true;
            size++;
        }
        if (q == i) {
            ans = max(ans, size);
        }
    }
    vector< bool > db(n, false);
    vector< int > lng(n, 0);
    for (size_t i = 0; i < n; ++i) {
        if (f[f[i]] == i) {
            db[i] = true;
            db[f[i]] = true;
        }
    }
    for (size_t i = 0; i < n; ++i) {
        fill(was.begin(), was.end(), false);
        int q = i;
        int len = 1;
        int path = true;
        while (!was[q] && !db[q]) {
            was[q] = true;
            q = f[q];
            len++;
        }
        if (db[q]) {
            lng[q] = max(lng[q], len);
        }
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (db[i]) {
            sum += lng[i];
        }
    }
    ans = max(ans, sum);
    cout << ans << endl;
}

int main() {
    int n = next< int >();
    for (int i = 1; i <= n; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
