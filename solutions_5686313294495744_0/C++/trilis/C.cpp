#include <iostream>
#include <set>

using namespace std;

int t;
string a[16];
string b[16];
bool fake[16];
int ans;
int n;

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int r = 0; r < t; r++) {
        cin >> n;
        ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }
        for (int m = 0; m < (1 << n); m++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                fake[i] = (m >> i) & 1;
                if (fake[i]) {
                    cnt++;
                }
            }
            set<string> s1;
            set<string> s2;
            for (int i = 0; i < n; i++) {
                if (!fake[i]) {
                    s1.insert(a[i]);
                    s2.insert(b[i]);
                }
            }
            bool flag = 0;
            for (int i = 0; i < n; i++) {
                if (fake[i]) {
                    if (s1.find(a[i]) == s1.end() || s2.find(b[i]) == s2.end()) {
                        flag = 1;
                    }
                }
            }
            if (!flag) {
                ans = max(ans, cnt);
            }
        }
        cout << "Case #" << r + 1 << ": " << ans << "\n";
    }
}


