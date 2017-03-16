#include <stdio.h>
#include <string.h>

int Nodes[1200][20];
int N, M;

int walk(int i, int dst);

int main()
{
    int T, t;
    int i, j;
    int cnt, flag;

    scanf("%d", &T);
    for(t = 0; t < T; t++) {
        scanf("%d", &N);
        for(i = 0; i < N; i++) {
            scanf("%d", &M);
            Nodes[i][0] = M;
//printf("%d: ", i);
            for(j = 1; j <= M; j++) {
                scanf("%d", &Nodes[i][j]);
                Nodes[i][j]--;
//printf("%d ", Nodes[i][j]);
            }
//printf("\n");
        }

        flag = 0;
        for(i = 0; i < N; i++) {
            for(j = 0; j < N; j++) {
                if(Nodes[j][0] == 0) {
                    cnt = walk(i, j);
//printf("\n");
                    if(cnt > 1) {
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag)
                break;
        }

        if(flag)
            printf("Case #%d: Yes\n", t+1);
        else
            printf("Case #%d: No\n", t+1);
    }

    return 0;
}

int walk(int i, int dst)
{
    int j, cnt;
    cnt = 0;

//printf("$%d", i);

    if(Nodes[i][0] == 0) {
        if(i == dst)
            return 1;
        else
            return 0;
    } else {
        for(j = 0; j < Nodes[i][0]; j++) {
            cnt += walk(Nodes[i][j+1], dst);
            if(cnt > 1) {
                return cnt;
            }
        }
    }
    return cnt;
}
