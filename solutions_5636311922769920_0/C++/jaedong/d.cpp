#include <bits/stdc++.h>
using namespace std;

int main() {
    int cases;
    scanf("%d", &cases);
    for (int cs = 1; cs <= cases; cs++) {
        int k, c, s;
        scanf("%d%d%d", &k, &c, &s);

        long long pw = 1, check = 0;
        int exp = 0;
        vector<long long> sol;
        for (int i = 0; i < k; i++) {
            check += i * pw;
            if (exp == c - 1) {
                sol.push_back(check + 1);
                check = 0;
                pw = 1;
                exp = 0;
            } else {
                pw *= k;
                exp++;
            }
        }
        if (exp)
            sol.push_back(check + 1);

        if (sol.size() <= s) {
            printf("Case #%d:", cs);
            for (auto c: sol)
                printf(" %lld", c);
            puts("");
        } else {
            printf("Case #%d: IMPOSSIBLE\n", cs);
        }
    }
}
