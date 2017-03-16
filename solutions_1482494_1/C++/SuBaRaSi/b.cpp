#include <cstdio>
using namespace std;

int as[1024];
int bs[1024];
int main()
{
    int T;
    scanf("%d", &T);
    for(int tn = 1; tn <= T; tn++)
    {
        printf("Case #%d:", tn);

        int N;
        scanf("%d", &N);

        for(int i = 0; i < N; i++)
            scanf("%d%d", as + i, bs + i);

        int now = 0;
        int ans = 0;
        int pass[1024] = {};
        while(now < 2 * N)
        {
            bool check = false;
            for(int i = 0; i < N; i++)
                if(pass[i] < 2 && bs[i] <= now)
                {
                    ans++;
                    now += 2 - pass[i];
                    pass[i] = 2;
                    check = true;
                }

            if(!check)
            {
                int idx = -1;
                for(int i = 0; i < N; i++)
                    if(!pass[i] && as[i] <= now && (idx == -1 || bs[idx] < bs[i]))
                        idx = i;

                if(idx == -1)
                    break;
                else
                {
                    now++;
                    ans++;
                    pass[idx] = 1;
                }
            }
        }

        if(now != 2 * N)
            printf(" Too Bad\n");
        else
            printf(" %d\n", ans);
    }

    return 0;
}
