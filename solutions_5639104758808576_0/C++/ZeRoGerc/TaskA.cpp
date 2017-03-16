#include <iostream>
#include <string>

using namespace std;

int t, n;
string temp;

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        cin >> n >> temp;
        int cur = 0, ans = 0;
        for (int j = 0; j <= n; j++) {
            if (cur < j) {
                ans += (j - cur);
                cur = j;
            }
            cur += temp[j] - '0';
        }
        printf("Case #%d: %d\n", i + 1, ans);
    }
}