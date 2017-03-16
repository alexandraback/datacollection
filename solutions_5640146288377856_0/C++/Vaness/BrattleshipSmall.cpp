#include <bits/stdc++.h>
using namespace std;

int T;
int R, C, W;

int solve()
{
    scanf("%d%d%d", &R, &C, &W);
    int ans = (C + W - 1) / W + (W - 1);
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int test = 1; test <= T; test++)
        printf("Case #%d: %d\n", test, solve());
}
