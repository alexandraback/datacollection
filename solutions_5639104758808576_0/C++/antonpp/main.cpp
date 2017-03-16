#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    for (int u = 0; u < t; ++u) {
        int n;
        string s;
        vector<int> a;
        cin >> n >> s;
        for (char c : s) {
            a.push_back(c - '0');
        }
        int k = 0;
        int res = 0;
        for (int i = 0; i <= n; ++i) {
            if (k < i) {
                res += i - k;
                k = i;
            }
            k += a[i];
        }
        printf("Case #%d: %d\n", u + 1, res);
    }

    return 0;
}