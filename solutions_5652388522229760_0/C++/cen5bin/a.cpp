#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
#define esp 1e-9
typedef long long LL;
const int MOD = 1e9+7;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        static int cas = 1;
        if (n == 0) {
            printf("Case #%d: INSOMNIA\n", cas++);
            continue;
        }
        int all = (1<<10)-1;
        int st = (1<<10)-1;
        int y = n;
        do {
            int x = n;
            while (x) st &= (all^(1<<(x%10))), x/=10;
            n += y;
        } while(st);
        printf("Case #%d: %d\n", cas++, n - y);
    }
    return 0;
}

