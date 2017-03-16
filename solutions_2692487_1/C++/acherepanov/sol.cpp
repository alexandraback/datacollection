#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ok (int k, vector<int> const & a, int x) {
    int n = a.size();
    for (int i = 0; i < n; ) {
        if (a[i] < x) {
            x += a[i];
            ++i;
        }
        else {
            if (n - i <= k) {
                return true;
            }
            else {
                if (k == 0) {
                    return false;
                }
                else {
                    x += x - 1;
                    --k;
                }
            }
        }
    }
    return true;
}

int sol (int x, vector<int> a) {
    sort(a.begin(), a.end());
    int n = a.size();
    int left = -1, right = n;
    while (left + 1 < right) {
        int middle = (left + right) / 2;
        if (ok(middle, a, x)) {
            right = middle;
        }
        else {
            left = middle;
        }
    }
    return right;
}

void sol (int testNum) {
    int n, x;
    cin >> x >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << "Case #" << testNum + 1 << ": " << sol(x, a) << "\n";
}

int main () {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        sol(i);
    }
    return 0;
}
