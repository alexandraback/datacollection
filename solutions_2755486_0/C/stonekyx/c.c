#include <stdio.h>
#include <string.h>

struct tribe_t
{
    int d, n, w, e, s, deld, delp, dels, attcnt;
}tribe[11];

int main()
{
    int T, Tcnt=0;
    for(scanf("%d", &T); T; T--) {
        int N;
        int i;
        static int hei[10000];
        int ans=0;
        scanf("%d", &N);
        for(i=0; i<N; i++) {
            scanf("%d%d%d%d%d%d%d%d", &tribe[i].d, &tribe[i].n, &tribe[i].w, &tribe[i].e, &tribe[i].s, &tribe[i].deld, &tribe[i].delp, &tribe[i].dels);
            tribe[i].attcnt=0;
            tribe[i].e--;
        }
        memset(hei, 0, sizeof(hei));
        for(i=0; i<1000; i++) {
            int t;
            int newhei=-1;
            for(t=0; t<N; t++) {
                int j;
                if(i<tribe[t].d || (i-tribe[t].d)%tribe[t].deld) continue;
                if(tribe[t].attcnt>=tribe[t].n) continue;
                for(j=tribe[t].w; j<=tribe[t].e; j++) {
                    if(hei[j+5000]<tribe[t].s) {
                        ans++;
                        break;
                    }
                }
                if(newhei<tribe[t].s) {
                    newhei=tribe[t].s;
                }
            }
            for(t=0; t<N; t++) {
                int j;
                if(i<tribe[t].d || (i-tribe[t].d)%tribe[t].deld) continue;
                if(tribe[t].attcnt>=tribe[t].n) continue;
                for(j=tribe[t].w; j<=tribe[t].e; j++) {
                    if(hei[j+5000]<newhei) hei[j+5000]=newhei;
                }
                tribe[t].attcnt++;
                tribe[t].w+=tribe[t].delp;
                tribe[t].e+=tribe[t].delp;
                tribe[t].s+=tribe[t].dels;
            }
        }
        printf("Case #%d: %d\n", ++Tcnt, ans);
    }
    return 0;
}
