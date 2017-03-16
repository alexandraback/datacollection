#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int p[1005];

int main() {
    int cn;
    scanf("%d", &cn);
    for(int ci = 1; ci <= cn; ci++) {
        int d, maxn;
        scanf("%d", &d);
        maxn = 0;
        for(int i = 0; i < d; i++) {
            scanf("%d", &p[i]);
            maxn = max(p[i], maxn);
        }
        int ans = 1000005;
        for(int m = 1; m <= maxn; m++) {
            int cost = m;
            for(int i = 0; i < d; i++) {
                if(p[i] > m) cost += (p[i] / m) - (p[i] % m == 0);
            }
            ans = min(ans, cost);
        }
        printf("Case #%d: %d\n", ci, ans);
    }
    return 0;
}

