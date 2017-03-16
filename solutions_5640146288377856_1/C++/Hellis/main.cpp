#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
   // freopen("1.txt", "r", stdin);
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++)
    {
        int r, c, w;
        cin >> r >> c >> w;

        int ans = 0;
        ans += (r - 1) * (c / w);
        int m = w + c % w;
        ans += (c - m) / w;
        ans += w + ((m % w) > 0);
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
