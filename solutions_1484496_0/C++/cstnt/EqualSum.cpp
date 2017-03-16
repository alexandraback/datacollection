#include <iostream>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

int a[500];

int main()
{
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++)
    {
        map<int, int> n2n;
        int n;
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        printf("Case #%d:\n", t + 1);

        for (int i = 0; i < (1 << n); i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    sum += a[j];
                }
            }

            if (n2n.find(sum) != n2n.end())
            {
                bool begin = true;

                for (int j = 0; j < n; j++)
                {
                    if (i &(1 << j))
                    {
                        if (!begin)
                        {
                            printf(" ");
                        }
                        else
                        {
                            begin = false;
                        }

                        printf("%d", a[j]);
                    }
                }
                printf("\n");

                begin = true;
                for (int j = 0; j < n; j++)
                {
                    if (n2n[sum] & (1 << j))
                    {
                           if (!begin)
                        {
                            printf(" ");
                        }
                        else
                        {
                            begin = false;
                        }

                        printf("%d", a[j]);
                    }
                }

                printf("\n");
                goto exit;
            }
            else
            {
                n2n[sum] = i;
            }
        }
        
        printf("Impossible\n");
exit:;
    }
}
