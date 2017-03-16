#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n, ar[MAXN];

void go(int casenum) {
    cin >> n;
    for (int i=0; i<n; i++) cin >> ar[i];
    int ans = 1e9;
    for (int i=1; i<MAXN; i++) {
        int cur = 0;
        for (int j=0; j<n; j++)
            cur += max(0, (ar[j]-1)/i);
        ans = min(ans, cur+i);
    }
    printf("Case #%d: %d\n", casenum, ans);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for (int i=1; i<=t; i++) go(i);
}
