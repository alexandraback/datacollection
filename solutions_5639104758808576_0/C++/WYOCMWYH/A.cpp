#include <bits/stdc++.h>

using namespace std;

void Solve (int test_num) {
    int n;
    scanf("%d", &n);
    vector<int> a(n + 1);
    for (auto& i : a) {
        char c;
        cin >> c;
        i = c - '0';
    }
    int tot = 0;
    int ans = 0;
    for (int i = 0; i < n + 1; ++i) {
        if (a[i] != 0) {
            ans = max(ans, i - tot);
        }
        tot += a[i];
    }
    printf("Case #%d: %d\n", test_num, ans);
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        Solve(i + 1);
    }
}
