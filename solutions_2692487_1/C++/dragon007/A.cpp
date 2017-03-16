#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<double> VD;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define A first
#define B second
#define eps 1e-8

int t, a[110], n;

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    scanf("%d", &t);
    for (int ca = 1; ca <= t; ca ++ ) {
        scanf("%d", &a[0]);
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        int ans = n, cnt = 0;
        if (a[0] != 1) {
            for (int i = 1; i <= n; i ++ ) {
                while (a[0] <= a[i]) {
                    a[0] = a[0] * 2 - 1;
                    cnt ++ ;
                }
                a[0] += a[i];
                ans = min(ans, cnt + n - i);
            }
        }
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}
