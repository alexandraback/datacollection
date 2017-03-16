#include<iostream>
#include<fstream>
#include<algorithm>
#define ll long long
using namespace std;

int solve() {
    string s;
    cin >> s;
    int ans = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '-') {
            int pt;
            for (pt = 0; pt <= i; ++pt) {
                if (s[pt] == '-') 
                    break;
            }
            pt--;
            if (pt >= 0) {
                reverse(s.begin(), s.begin() + pt + 1);
                ans++;
                for (int j = 0; j <= pt; ++j) {
                    if (s[j] == '+') s[j] = '-';
                    else s[j] = '+';
                }
            }
            if (pt != i) {
                reverse(s.begin(), s.begin() + i + 1);
                ans++;
                for (int j = 0; j <= i; ++j) {
                    if (s[j] == '+') 
                        s[j] = '-';
                    else 
                        s[j] = '+';
                }

            }
        }
    }
    return ans;
}

int main(void) {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        printf("Case #%d: %d\n", i, solve());
    }
}
