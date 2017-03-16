#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int panc[1000];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int ct = 1; ct <= T; ct++)
    {
        int D;
        scanf("%d", &D);

        int M = 0;
        for(int i = 0; i < D; i++)
        {
            scanf("%d", &panc[i]);
            M = max(M, panc[i]);
        }

        int t_min = 2000;

        for(int manger = 1; manger <= M; manger++)  //on veut que toutes les piles soient <= à manger
        {
            int t = 0;
            for(int i = 0; i < D; i++)
                if(panc[i] > manger)
                    t += (panc[i]-1)/manger;
            t_min = min(t_min, t+manger);
        }

        printf("Case #%d: %d\n", ct, t_min);
    }
    return 0;
}
