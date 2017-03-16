#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 100010;
double p[MAXN];

int main()
{
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T, A, B;
    int con = 1;
    double pi, ans, r, w;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &A, &B);
        ans = B + 2;
        p[0] = 1;
        for(int i = 1; i <= A; i++){
            scanf("%lf", &pi);
            p[i] = pi * p[i - 1];
        }
        r = B - A + 1;
        w = 2 * B - A + 2;
        for(int i = 0; i <= A; i++){
            ans = min(ans, r * p[A - i] + w * (1 - p[A - i]));
            r += 2;
            w += 2;
        }
        printf("Case #%d: %lf\n", con++, ans);
    }
    return 0;
}
