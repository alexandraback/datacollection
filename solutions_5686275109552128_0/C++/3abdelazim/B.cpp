#include <iostream>
#include <algorithm>

using namespace std;


int n, arr[1001];

int solve(int x) {
    int ret = x;
    for (int i = 0; i < n; i++) {
        ret += (arr[i] - 1) / x;
    }
    return ret;
}

int main() {
    freopen("b_small.in", "r", stdin);
    freopen("b_small.out", "w", stdout);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        cin >> n;
        int maximum = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            maximum = max(maximum, arr[i]);
        }
        int result = maximum;
        for (int i = 1; i <= maximum; i++) {
            result = min(result, solve(i));
        }
        cout << "Case #" << t << ": " << result << endl;
    }
}
