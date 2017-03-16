#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, M;
int map[110][110];
int real[110][110];
struct rec_t
{
    int x,y;
}rec[11000];
int rcnt;
int locked[110][110];

int compare_record(const void *a, const void *b)
{
    struct rec_t *na=(struct rec_t *)a,
                 *nb=(struct rec_t *)b;
    return map[nb->x][nb->y] - map[na->x][na->y];
}

int main()
{
    int T, Tcnt=0;
    for(scanf("%d", &T); T; T--) {
        int i;
        rcnt=0;
        scanf("%d%d", &N, &M);
        for(i=0; i<N; i++) {
            int j;
            for(j=0; j<M; j++) {
                scanf("%d", map[i]+j);
                rec[rcnt].x=i;
                rec[rcnt].y=j;
                rcnt++;
                real[i][j]=100;
            }
        }
        qsort(rec, rcnt, sizeof(struct rec_t), compare_record);
        memset(locked, 0, sizeof(locked));
        for(i=0; i<rcnt; i++) {
            int j, hei=map[rec[i].x][rec[i].y];
            for(j=0; j<N; j++) {
                if(real[j][rec[i].y]>hei && locked[j][rec[i].y]) break;
            }
            if(j>=N) {
                for(j=0; j<N; j++) {
                    if(real[j][rec[i].y]>hei) {
                        real[j][rec[i].y] = hei;
                    }
                }
            } else {
                for(j=0; j<M; j++) {
                    if(real[rec[i].x][j]>hei && locked[rec[i].x][j]) break;
                }
                if(j>=M) {
                    for(j=0; j<M; j++) {
                        if(real[rec[i].x][j]>hei) {
                            real[rec[i].x][j]=hei;
                        }
                    }
                } else {
                    break;
                }
            }
            locked[rec[i].x][rec[i].y]=1;
        }
        printf("Case #%d: ", ++Tcnt);
        if(i>=rcnt) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
