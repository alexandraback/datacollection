#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;

map<long long, int> f;
int n;
long long arr[505];

void dfs(long long first) {
    if (first) {
        long long delta = f[first];
        printf(" %lld", arr[delta]);
        dfs(first - arr[delta]);
    }
}

int main() {
    freopen("D:\\C-large.in", "r", stdin);
    freopen("D:\\C-large.out", "w", stdout);
    int tc, c = 0, i;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%lld", arr + i);
        f.clear();
        f[0] = -1;
        bool flag = false;
        map<long long, int>::iterator it;
        for (i = 0; i < n; i++) {
            it = f.end();
            do {
                --it;
                if (f.find(it->first + arr[i]) != f.end()) {
                    flag = true;
                    break;
                }
                f[it->first + arr[i]] = i;
            } while (it != f.begin());
            if (flag || f.size() > 100000000)
                break;
        }
        printf("Case #%d:\n", ++c);
        if (!flag)
            puts("Impossible");
        else {
            printf("%lld", arr[i]);
            dfs(it->first);
            putchar('\n');
            long long sum = it->first + arr[i];
            long long delta = f[sum];
            printf("%lld", arr[delta]);
            dfs(sum - arr[delta]);
            putchar('\n');
        }
    }
    return 0;
}