#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++)
    {
        int a, b, k, ans = 0;
        scanf("%d%d%d", &a, &b, &k);
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                if ((i & j) < k)
                {
                    ans++;
                }
            }
        }
        printf("Case #%d: %d\n", cases, ans);
    }
    return 0;
}
