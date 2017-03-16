#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for(int z = 1; z <= t; z++) {
        int n;
        scanf("%d", &n);

        double values[2][n];
        for(int p = 0; p < 2; p++) {
            for(int i = 0; i < n; i++)
                scanf("%lf", &values[p][i]);

            sort(values[p], values[p] + n);
        }


        int ans = 0;
        for(int i = 0; i < n; i++)
            if(values[0][i] > values[1][ans])
                ans++;

        int ans2 = 0, ptr = n-1;
        for(int i = n-1; i >= 0; i--)
            if(values[0][i] > values[1][i+ans2])
                ans2++;

        printf("Case #%d: %d %d\n", z, ans, ans2);
    }
}
