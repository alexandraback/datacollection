#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    freopen("gcj\\B-large.in", "r", stdin);
    freopen("gcj\\B-large.out", "w", stdout);

    int T, cases = 1;
    int L, ans;
    char s[128];

    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);

        L = 1;
        for (int i = 1; s[i]; ++i)
        {
            if (s[i] != s[L - 1])
                s[L++] = s[i];
        }
        s[L] = 0;

        if ((s[0] == '-' && L % 2 == 0) ||
            (s[0] == '+' && L % 2 == 1))
            ans = L - 1;
        else
            ans = L;

        printf("Case #%d: %d\n", cases++, ans);
    }

    return 0;
}