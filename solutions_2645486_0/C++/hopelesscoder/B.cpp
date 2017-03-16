#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int num = 1; num <= T; num++)
    {
        int e,r,n;
        scanf("%d %d %d",&e,&r,&n);
        int value[n+5];
        int maxi = 1;
        for (int i = 0; i < n; i++)
            maxi *= 6;
        for (int i = 0; i < n; i++)
            scanf("%d",&value[i]);
        int energy = e;
        int res = 0;
        for (int i = 0; i < maxi; i++)
        {
            int temp = i;
            bool can = true;
            int tempres = 0;
            energy = e;
            for (int j = 0; j < n; j++)
            {
                int x = temp % 6;
                if (x <= energy)
                    tempres += x*value[j];
                else {
                    can = false;
                    break;
                }
                temp /= 6;
                energy = energy - x + r;
                if (energy > e) energy = e;
            }
            if ((tempres > res) && can)
                res = tempres;
        }
        printf("Case #%d: %d\n",num,res);
    }
    return 0;
}
