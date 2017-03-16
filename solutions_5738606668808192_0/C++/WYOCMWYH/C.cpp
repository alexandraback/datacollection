#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll from_base(int base, const vector<int> &num) {
    ll cur = 1, ans = 0;
    for (auto i : num) {
        ans += cur * i;
        cur *= base;
    }
    return ans;
}
 
vector<int> to_base(int base, ll num) {
    vector<int> ans;
    while(num) {
        ans.push_back(num % base);
        if (ans.back() > 1) return {-1};
        num /= base;
    }
    return ans;
}

int check(const vector<int> &num, int base) {
    ll m = from_base(base, num);
    for (ll i = 2; i * i <= m; ++i) {
        if (m % i == 0) return i;
    }
    return 0;
}

bool check(ll i) {
    vector<int> num;
    num.push_back(1);
    for (int j = 0; j < 14; ++j) {
        num.push_back(i % 2);
        i /= 2;
    }
    num.push_back(1);
    vector<int> ans(9);
    for (int j = 0; j < 9; ++j) {
        ans[j] = check(num, j + 2);
        if (!ans[j]) return 0;
    }
    for (int j = 15; j >= 0; --j) printf("%d", num[j]);
    for (int j = 0; j < 9; ++j) printf(" %d", ans[j]);
    printf("\n");
    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    printf("Case #1:\n");
    int j = 50;
    for (ll i = 0; j && i < (1LL << 16); ++i) {
        if (check(i)) --j; 
    }
}
