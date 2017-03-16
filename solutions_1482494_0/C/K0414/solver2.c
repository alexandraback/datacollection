#include <stdio.h>

int Levels[1200][2];
int Played[1200][2];
int cnt, stars, stps;

int main()
{
    int T, t;
    int N;
    int i, flag, act;

    scanf("%d", &T);
    for(t = 0; t < T; t++) {
        scanf("%d", &N);
        for(i = 0; i < N; i++) {
            scanf("%d%d", &Levels[i][0], &Levels[i][1]);
        }
        for(i = 0; i < N; i++) {
            Played[i][0] = 0;
            Played[i][1] = 0;
        }
        cnt = stars = stps = act = 0;
        
        while(cnt < N) {
            flag = 0;
            act = 0;
            for(i = 0; i < N; i++) {
                if(Played[i][1] == 0 && Levels[i][1] <= stars) {
                    stars += 2;
                    Played[i][1] = 1;
                    cnt++;
                    stps++;
                    flag = 1;
                    act = 1;
                }
            }
            if(flag)
                continue;

            flag = 0;
            for(i = 0; i < N; i++) {
                if(Played[i][0] < 2 && Levels[i][0] <= stars) {
                    stars++;
                    Played[i][0]++;
                    flag = 1;
                    stps++;
                    act = 1;
                    break;
                }
            }
            if(!flag)
                break;

            if(!act)
                break;
        }

        if(cnt == N) {
            printf("Case #%d: %d\n", t + 1, stps);
        } else {
            printf("Case #%d: Too Bad\n", t + 1);
        }
    }

    return 0;
}

