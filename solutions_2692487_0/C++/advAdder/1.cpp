#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 1000000;
int s[MAX_N+3];
int c[MAX_N+3];
int t[MAX_N+3];
int n;

inline int judge(int k)
{
    return c[k]+n-k-1;
}

inline void deal()
{
    int a;
    scanf("%d%d", &a, &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &t[i]);
    if (a == 1) {
        printf("%d\n", n);
        return;
    }
    sort(t, t+n);
    s[0] = a;
    c[0] = 0;
    while (s[0] <= t[0]) {
        ++c[0];
        s[0] += s[0]-1;
    }
    s[0] += t[0];
    for (int i = 1; i < n; ++i) {
        c[i] = c[i-1];
        s[i] = s[i-1];
        while (s[i] <= t[i]) {
            ++c[i];
            s[i] += s[i]-1;
        }
        s[i] += t[i];
    }
    int ans = n;
    for (int i = 0; i < n; ++i)
        if (judge(i) < ans)
            ans = judge(i);
    printf("%d\n", ans);
}

int main()
{
    int cases;
    scanf("%d", &cases);
    for (int i = 1; i <= cases; ++i) {
        printf("Case #%d: ", i);
        deal();
    }
    return 0;
}
