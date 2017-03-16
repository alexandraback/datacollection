#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;


#define INF 1e+9
#define mp make_pair
#define lint long long
#define pii pair<int, int>

int main() {
    freopen("inp", "r", stdin);
    freopen("outp", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        long double c, f, x;
        scanf("%Lf %Lf %Lf", &c, &f, &x);
        long double v = 2;
        long double res = 0;
        while (x / v >= x / (v + f) + c / v) {
            res += c / v;
            v += f;
        }
        res += x / v;
        printf("Case #%d: %.10Lf\n", i + 1, res);
    }
}
