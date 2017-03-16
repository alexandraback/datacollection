#include <bits/stdc++.h>

using namespace std;

void Solve (int test_num) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (auto& i : a) {
        scanf("%d", &i);
    }
    sort(a.rbegin(), a.rend());
    int ans = a[0];
    for (int h = 1; h < a[0]; ++h) {
        int cur_ans = h;
        for (auto i : a) {
            cur_ans += (i - 1) / h;
        }
        ans = min(ans, cur_ans);
    }
    printf("Case #%d: %d\n", test_num, ans);
}

int main() {
    freopen("B.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        Solve(i + 1);
    }
}
