#include <cstdio>
#include <string>
#include <memory.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
int main(void)
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for (int q = 1; q <= n; q++)
    {
        int m,s,p,a[105];
        printf("Case #%d: ",q);
        scanf("%d%d%d",&m,&s,&p);
        for (int i = 0 ; i < m; i++)
            scanf("%d",&a[i]);
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            int r =  a[i] / 3;
            if (a[i] % 3)
                r++;
            if (r >= p)
                ans++; else {
                    if (s)
                    {
                        if (r == (p-1))
                        {
                            if (((a[i] % 3 == 0) || (a[i] % 3 == 2)) && a[i])
                            {
                                ans++;
                                s--;
                            }
                        }
                    }
                }
        }
        printf("%d\n",ans);
    }
    return 0;

}