#include <iostream>
#include <vector>
#include <string>

using namespace std;

int e, r, n;
int v[10000];

inline int gen(int act, int re, int p)
{
    if (re > e)
        re = e;
    if (act == n)
        return p;
    int m = 0;
    for (int i = 0; i <= re; ++i)
    {
        int t = gen(act + 1, min(re - i + r, e), p + i * v[act]);
        if (m < t)
            m = t;
    }
    return m;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t;
    scanf("%i", &t);
    for (int p = 1; p <= t; ++p)
    {

        scanf("%i%i%i", &e, &r, &n);
        for (int i = 0; i < n; ++i)
            scanf("%i", v + i);

        int x = gen(0, e, 0);

        printf("Case #%i: %i\n", p, x);
    }


    return 0;
}