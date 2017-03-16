#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <set>
#include <map>

typedef long long int ll;

using namespace std;

ll a[60];
int mat[60][60];

int main() {
    freopen("B-small-attempt2.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int b;
        ll m;
        scanf("%d %lld", &b, &m);
        a[2] = 1;
        a[b] = 1;
        ll sum = 2 == b ? 1 : 2;
        for (int i = 0; i <= b; ++i)
            for (int j = 0; j <= b; ++j)
                mat[i][j] = 0;
        for (int i = 3; i < b; ++i) {
            a[i] = a[i - 1] * 2;
            sum += a[i];
        }
        for (int i = 1; i < b; ++i)
            for (int j = i + 1; j <= b; ++j)
                mat[i][j] = 1;
        for (int i = b - 1; i > 1; --i) {
            if (sum - a[i] >= m) {
                sum -= a[i];
                mat[i][b] = 0;
            }
        }
        if (sum == m) {
            printf("Case #%d: POSSIBLE\n", t);
            for (int i = 1; i <= b; ++i)
                for (int j = 1; j <= b; ++j){
                    printf("%d", mat[i][j]);
                    if (j == b) printf("\n");
                }
        } else {
            printf("Case #%d: IMPOSSIBLE\n", t);
        }
    }
    return 0;
}