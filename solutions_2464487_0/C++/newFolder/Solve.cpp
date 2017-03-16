#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;

const int maxn = 105;
const double eps = 1e-6;
LL r, t;

void solved(int cas)
{
    cin >> r >> t;
    LL left = 1, right = min(t / (2 * r - 1) + 1, (LL)sqrt((double)t) + 1);
    while (left <= right)
    {
        LL mid = (left + right) / 2;
        if (mid * mid * 2 + mid * (2LL * r - 1) < 0)
            while (true);
        if (mid * mid * 2 + mid * (2LL * r - 1) <= t)
            left = mid + 1;
        else
            right = mid - 1;
    }
    printf ("Case #%d: ", cas);
    cout << right << endl;
    if (right * right * 2 + right * (2LL * r - 1) > t || (right + 1) * (right + 1) * 2 + (right + 1) * (2LL * r - 1) <= t)
        while (true);
}


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf ("%d", &T);
    for (int i = 1; i <= T; i++)
        solved(i);
    return 0;
}