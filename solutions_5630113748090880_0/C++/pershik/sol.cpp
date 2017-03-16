#include <bits/stdc++.h>

#define NAME "test"

#define EPS (1e-9)
#define INF ((int)(1e+9))
#define LINF ((long long)(1e+18))

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long li;

void solve(int test_number);

int main() {
#ifdef _GEANY
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(9);
    cerr.setf(ios::fixed);
    cerr.precision(3);
    int n = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve(i + 1);
    }
    return 0;
}

void solve(int test_number) {
    int n;
    cin >> n;
    set<int> q;
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            if (q.count(a) != 0) {
                q.erase(a);
            } else {
                q.insert(a);
            }
        }
    }
    cout << "Case #" << test_number << ": ";
    for (auto c : q) {
        cout << c <<  ' ';
    }
    cout << endl;
}

