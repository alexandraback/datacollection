#include <vector>
#include <iostream>

int solve() {
    int n, s, p, ans = 0;
    std::cin >> n >> s >> p;
    for (int i = 0; i < n; ++i) {
        int sum;
        std::cin >> sum;
        if (sum >= 2 * std::max(0, p - 1) + p)
            ++ans;
        else if (s && sum >= 2 * std::max(0, p - 2) + p)
            ++ans,
            --s;
    }
    return ans;
}

int main() {
    freopen("b_in.txt", "r", stdin);
    freopen("b_out.txt", "w", stdout);
    int t;
    scanf("%d\n", &t);
    for (int i = 0; i < t; ++i) {
        std::cout << "Case #" << i + 1 << ": " << solve() << "\n";
    }
}