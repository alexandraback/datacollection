#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
typedef long long ll;

int main()
{
    int TestCases; scanf("%d", &TestCases);
    for (int testcase = 1; testcase <= TestCases; testcase++) {
        int r, c, w; scanf("%d%d%d", &r, &c, &w);
        printf("Case #%d: ", testcase);
        printf("%d\n", (r-1)*(c/w) + (c-1)/w + w);
    }
}

