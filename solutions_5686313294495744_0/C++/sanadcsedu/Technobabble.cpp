#include <bits/stdc++.h>
using namespace std;
#define SD(a) scanf("%d", &a)
char a[20][30];
char b[20][30];
int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("hogamara.txt", "w", stdout);

    int tcase,n, t, i, j, k, flag;

    SD(tcase);
    for(t = 1; t <= tcase; t++)
    {
        SD(n);
        for(i =0; i < n; i++)
        {
            scanf("%s %s", a[i], b[i]);
        }
        int fake = 0;
        for(i =0; i <n; i++)
        {
            flag = 0;
            for(j =0; j < n; j++)
            {
                if(i == j) continue;
                if(strcmp(a[i], a[j]) == 0)
                {
                    flag = 0;
                    for(k = 0; k < n; k++)
                    {
                        if(i == k) continue;
                        if(strcmp(b[i], b[k]) == 0)
                        {
                            flag = 1;
                            break;
                        }
                    }
                }
                if(flag)
                {
                    fake++;
                    break;
                }
            }
        }
        printf("Case #%d: %d\n", t, fake);
    }
    return 0;
}
