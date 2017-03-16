#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <bitset>
#define INF 0x3f3f3f3f
#define eps 1e-8
#define FI first
#define SE second
using namespace std;
typedef long long LL;

int main() {
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {
        int n, m, X;
        scanf("%d%d%d", &X, &n, &m);
        printf("Case #%d: ", ca);
        if(X >= 7 || X > max(n, m) || n * m % X) {
            puts("RICHARD");
            continue;
        }
        if(X <= 2) {
            puts("GABRIEL");
            continue;
        }
        if(X / 2 + 1 > min(n, m)) {
            puts("RICHARD");
            continue;
        }
        puts("GABRIEL");
    }
    return 0;
}
