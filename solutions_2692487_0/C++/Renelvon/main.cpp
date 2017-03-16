#include <algorithm>
#include <iostream>

using namespace std;

int solve (const int a, int n, int m[]) {
    int minops = n;
    for (int i = 0; i <= n; ++i) {
        int ac = a, ops = n - i;
        for (int j = 0; j < i; ++j) {
            if (m[j] < ac) {
                ac += m[j];
            } else {
                if (ac == 1) {
                    ops = n;
                    break;
                }
                ac += ac - 1;
                ++ops;
                --j;
            }
        }
        minops = min(minops, ops);
    }

    return minops;
}
       

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int a, n;
        cin >> a >> n;
        int m[n];
        for (int j = 0; j < n; ++j) {
            cin >> m[j];
        }
        
        sort(m, m + n);
        cout << "Case #" << i << ": " << solve(a, n, m) << endl;
    }
}
