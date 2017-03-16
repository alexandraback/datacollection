#include <iostream>

#include <cstdio>
using namespace std;
int a[205], n;
bool v[205];
double ans[205];
int main()
{
        freopen("A-large.in", "r", stdin);
        freopen("out.txt", "w", stdout);
    int cas;
    scanf("%d", &cas);
    for(int i = 1; i <= cas; i++)
    {
            scanf("%d", &n);
            for(int i = 0; i < n; i++)
                scanf("%d", &a[i]);

            printf("Case #%d:", i);
            for(int i = 0; i < n; i++)
                v[i] = false;
            int tmpn = n;
            int id, msc;


            while(true)
            {
                msc = 0;
                bool flag = false;

                int sum = 0;
                for(int i = 0; i < n ;i++)
                    sum += a[i];
                int tsum = 0;
                for(int i = 0; i < n ;i++)
                    if(v[i])
                        tsum += a[i];

                for(int i = 0; i < n ;i++)
                {
                    if(v[i])continue;

                    ans[i] = 100.0 * ( (sum*2.0 - tsum) / tmpn - a[i]) / sum ;
                    if(ans[i] < 0)
                    {
                        if(a[i] > msc)
                            msc = a[i], id = i;
                        flag = true;
                    }
                }

                if(!flag)
                    break;
                else ans[id] = 0, v[id] = true, tmpn --;
            }
            for(int i = 0; i < n; i++)
                printf(" %.6lf", ans[i]);
            printf("\n");
    }
    return 0;
}
