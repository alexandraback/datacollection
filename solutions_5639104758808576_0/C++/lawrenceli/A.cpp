#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

bool good(string s, int cnt) {
    for (int i=0; i<s.length(); i++) {
        if (cnt < i) return 0;
        cnt += s[i]-'0';
    }
    return 1;
}

void go(int casenum) {
    int n;
    string s;
    cin >> n >> s;
    for (int i=0; i<MAXN; i++)
        if (good(s, i)) {
            printf("Case #%d: %d\n", casenum, i);
            return;
        }
    assert(0);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for (int i=1; i<=t; i++) go(i);
}
