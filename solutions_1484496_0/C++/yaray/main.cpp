#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

const int N = 20;
int n;
int a[N];
pli b[1 << N];

void go(int k, ll sum, int mask)
{
    if (k == n) {
        b[mask] = pli(sum, mask);
        return;
    }
    go(k+1, sum, mask);
    go(k+1, sum + a[k], mask | 1 << k);
}

void output(int n, int m)
{
    bool f = true;
    for (int i = 0; i < n; ++i) {
        if (m & 1 << i) {
            if (f) f = false;
            else putchar(' ');
            printf("%d", a[i]);
        }
    }
    puts("");
}

int main()
{
    int cases;
    scanf("%d", &cases);
    for (int T = 1; T <= cases; ++T) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        go(0, 0, 0);
        sort(b, b + (1 << n));
        printf("Case #%d:\n", T);
        for (int j = 1; j < (1 << n); ++j)
            if (b[j-1].first == b[j].first) {
                output(n, b[j-1].second);
                output(n, b[j].second);
                break;
            }
    }
}
