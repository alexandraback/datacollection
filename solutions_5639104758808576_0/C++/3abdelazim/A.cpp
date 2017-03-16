#include <iostream>

using namespace std;

int main() {
    freopen("a_small.in", "r", stdin);
    freopen("a_small.out", "w", stdout);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        int n;
        string s;
        cin >> n >> s;
        int standing = 0;
        int result = 0;
        for (int i = 0; i <= n; i++) {
            if (i > standing) {
                result += i - standing;
                standing = i;
            }
            standing += (s[i] - '0');
        }
        cout << "Case #" << t << ": " << result << endl;
    }
}
