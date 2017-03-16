#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
#include<deque>
#include<cmath>
#include<ctime>
#include<stack>

using namespace std;

string s[20];
string a[20];
int n;

bool check(int mask) {
    vector <int> q;
    bool used[20];
    for (int i = 0; i < n; ++i) {
        used[i] = false;
    }
    for (int i = 0; i < n; ++i) {
        if ((mask & (1 << i)) == 0) {
            q.push_back(i);
            used[i] = true;
        }
    }
    while(q.size() != n) {
        int cur0 = q.size();
        for (int i = 0; i < n; ++i) {
            bool fl1 = false;
            bool fl2 = false;
            if (!used[i]) {
                for (int j = 0; j < q.size(); ++j) {
                    if (used[j] && s[j] == s[i]) fl1 = true;
                    if (used[j] && a[j] == a[i]) fl2 = true;
                }
            }
            if (fl1 && fl2) {
                used[i] = true;
                q.push_back(i);
            }
        }
        if (q.size() == cur0) return false;
    }
    return true;
}

int main() {
    freopen("C-small-attempt0 (1).in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cout << "Case #" << t + 1 << ": ";
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> s[i] >> a[i];
        int mask = 1 << n;
        int ans = 0;
        for (int i = 0; i < mask; ++i) {
            if (check(i)) {
                int cur = 0;
                for (int j = 0; j < n; ++j) {
                    if (((1 << j) & i) != 0) {
                        cur++;
                    }
                }
                ans = max(ans, cur);
            }
        }
        cout << ans;
        cout << "\n";
    }
    return 0;
}