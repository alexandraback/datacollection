#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

int main()
{
    int t, teste;
    int n;
    int i, j;
    int a;
    int mote[200];
    scanf("%d\n", &teste);
    for (int t = 0; t < teste; t++)
    {
        scanf("%d %d\n", &a, &n);
        for (i = 0; i < n; i++)
        {
            scanf("%d\n", &mote[i]);
        }
        sort(&mote[0],&mote[n]);

        int best = n;
        int created = 0;
        if (a > 1)
        {
            for (i = 0; i < n; i++)
            {
                while (a <= mote[i])
                {
                    a += a - 1;
                    created++;
                }
                a += mote[i];
                int cand = n - i - 1 + created;
                if (best > cand)
                    best = cand;
            }
        }
        printf("Case #%d: %d\n", t+1, best);
    }
    return 0;
}
