#include <cstdio>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cstring>
#include <array>
using namespace std;
const int MAXN = 1005;
char s[MAXN];
int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, n;
    scanf("%d", &t);
    for (int _ = 1; _<= t; ++_)
    {
        printf("Case #%d: ", _);
        scanf("%d%s", &n, s);
        int bg = 0, res = 0;
        for (int i = 0; i<= n; ++i)
        {
            int p = s[i] - '0';
            if (i > bg)
            {
                res += i-bg;
                bg += p + i-bg;
            }
            else
            {
                bg += p;
            }
        }
        printf("%d\n", res);
    }
}
