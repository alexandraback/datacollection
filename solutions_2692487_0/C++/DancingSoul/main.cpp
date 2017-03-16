#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int cas, CAS, a[1000005], n, i, t, ans, res;
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &CAS);
    for (cas = 1; cas <= CAS; cas++){
        scanf("%d%d", &a[0], &n);
        for (i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        if (a[0] == 1){
            printf("Case #%d: %d\n", cas, n);
            continue;
        }
        ans = 0; res = n;
        for (i = 1; i <= n; i++){
            while (a[i - 1] <= a[i]){
                a[i - 1] += a[i - 1] - 1;
                ans++;
            }
            a[i] += a[i - 1];
            res = min(res, ans + (n - i));
        }
        printf("Case #%d: %d\n", cas, res);
    }

}
