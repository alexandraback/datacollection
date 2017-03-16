#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
long long a, b, k;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int test_case;
    scanf("%d", &test_case);
    for (int case_number = 1; case_number <= test_case; case_number++) {
        cin >> a >> b >> k;
        a--;
        b--;
        k--;
        long long ans = 0;
        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= b; j++) {
                if ((i & j) <= k) {
                    ans++;
                }
            }
        }
        cout << "Case #" << case_number << ": " << ans << endl;
    }
    return 0;
}
