#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int sizes[100];

int main() {
    int t;
    scanf("%d", &t);

    for(int z = 1; z <= t; z++) {
        int a, n;
        scanf("%d %d", &a, &n);

        for(int i = 0; i < n; i++)
            scanf("%d", &sizes[i]);
        sort(sizes, sizes+n);

        if(a == 1) {
            printf("Case #%d: %d\n", z, n);
            continue;
        }

        int ans = n;
        for(int j = 1; j <= n; j++) {
            int cur = n-j, a2 = a;

            for(int i = 0; i < j; i++) {
                while(a2 <= sizes[i]) {
                    cur++;
                    a2 += a2-1;
                }

                a2 += sizes[i];
            }

            ans = min(ans, cur);
        }

        printf("Case #%d: %d\n", z, ans);
    }
}
