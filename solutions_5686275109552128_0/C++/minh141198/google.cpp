#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int n, a[1024], c[1024];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int tc;
    scanf("%d", &tc);
    for(int cs = 1; cs <= tc; cs ++){
        scanf("%d", &n);
        int ma = 0;
        for(int i = 1; i <= n; i ++){
            scanf("%d", a + i);
            ma = max(ma, a[i]);
        }
        int ans = 1024;

        for(int i = 1; i <= ma; i ++){
            int sum = i;
            for(int j = 1; j <= n; j ++) sum += a[j]/i - (a[j] % i == 0);

            ans = min(ans, sum);

        }
        printf("Case #%d: %d\n", cs, ans);
    }
    return 0;
}
