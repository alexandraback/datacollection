#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

long long Work(vector<long long> a, long long k) {
    long long ans = 0;
    long long p = 1;
    for (int i = a.size() - 1; i >= 0; i--) {
        ans += (long long)(a[i] - 1) * p;
        p *= k;
    }
    ans++;
    return ans;
}

int test;
int main() {
    freopen("D-large.in", "r", stdin);
    freopen("D-large.out", "w", stdout);
    scanf("%d", &test);
    for (int t = 1; t <= test; t++) {
        printf("Case #%d:", t);
        int k, c, s;
        scanf("%d%d%d", &k, &c, &s);
        int lower = k / c + ((k % c == 0) ? 0 : 1);
        if (s < lower) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        for (int i = 1; i <= k; i += c) {
            vector<long long> temp;
            for (int j = 0; (j < c) && (i + j <= k); j++) {
                temp.push_back(i + j);
            }
            printf(" %lld", Work(temp, k));
        }
        printf("\n");
    }
    return 0;
}
