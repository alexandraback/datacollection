#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define INF 1000000007

using namespace std;

unsigned ll k, c, s, a[110];

int main() {
    
  //  freopen("test.in", "r", stdin);
   // freopen("test.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++ t) {
        scanf("%llu%llu%llu", &k, &c, &s);
        for (int i = 1; i <= k; ++ i) a[i] = i;
        for (int i = 2; i <= c; ++ i)
            for (int j = 1; j <= k; ++ j) a[j] = k * a[j - 1] + a[j];
        printf("Case #%d: ", t);
        for (int i = 1; i <= k; ++ i) printf("%llu ", a[i]);
        printf("\n");
    }
    return 0;

}

