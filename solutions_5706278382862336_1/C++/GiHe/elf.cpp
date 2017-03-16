#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

long long gcd(long long p, long long q)
{
    if (q == 0) return p;
    else return gcd(q, p % q);
}

int main()
{
    freopen("elf2.in","r",stdin);
    freopen("elf2.out","w",stdout);
    int testcase;
    long long p, q;
    scanf("%d", &testcase);
    for (int test = 1; test <= testcase; test++) {
        cin >> p;getchar();cin >> q;
        long long t = gcd(p, q);
        p /= t;
        q /= t;
        long long qq = q;
        int cnt = 0;
        while (q % 2 == 0) {
            cnt++;
            q /= 2;
        }
        printf("Case #%d: ", test);
        if (q == 1) {
                q = qq;
                int ans = 0;
                while (p < q) {
                    q /= 2;
                    ans++;
                }
                printf("%d\n", ans);
            }
        else printf("impossible\n");
    }
    return 0;
}
