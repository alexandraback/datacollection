#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


const int maxn = 1000;

int p[maxn];

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);

    int test = 1, tests;
    for (scanf("%d", &tests); test <= tests; ++ test) {
        int n, answer = 1000;
        scanf("%d", &n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &p[i]);
        }
        for (int maxi = 1; maxi <= 1000; ++ maxi) {
            int sum = maxi;
            for (int i = 0; i < n; ++ i) {
                if (p[i] > maxi) {
                    sum += (p[i] + maxi - 1) / maxi - 1;
                }
            }
            answer = min(answer, sum);
        }
        printf("Case #%d: %d\n", test, answer);
    }
    return 0;
}
