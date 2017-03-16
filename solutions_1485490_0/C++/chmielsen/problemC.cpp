#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

const int MAXN = 103;
const int MAXM = 103;

#define LL long long

typedef struct {
    LL val;
    int type;
} Seq;

Seq boxes[MAXN];
Seq toys[MAXM];


int main() {
    int tests;
    scanf("%d", &tests);
    for(int t = 1; t <= tests; t++) {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 0 ; i < n; i++) {
            LL val;
            int type;
            scanf("%lld %d", &val, &type);
            boxes[i].val = val;
            boxes[i].type = type;
        }
        for(int i = 0; i < m; i++) {
            LL val;
            int type;
            scanf("%lld %d", &val, &type);
            toys[i].val = val;
            toys[i].type = type;
        }
        int l, s, p;
        LL maks = 0;
        for(l = 0; l < m; l++)
            for(s = 0; s < m; s++)
                for(p = 0; p < m; p++) {
                    Seq curBoxes[3];
                    Seq curToys[m];
                    for(int i = 0; i < m; i++)
                        curToys[i] = toys[i];
                    for(int i = 0 ; i < 3; i++)
                        curBoxes[i] = boxes[i];
                    LL res = 0;
                    int i = 0;
                    //printf("PROBA\n");
                    for(i = 0 ; i < l; i++) {
                        if(boxes[0].type == curToys[i].type) {
                           LL odjemna = min(max(curBoxes[0].val, 0LL), curToys[i].val);
                           res += odjemna ;
                           curBoxes[0].val -= odjemna;
                           curToys[i].val -= odjemna;
                        }
                    }
                    i = max(0, i - 1);
                    for(int j = 0; j < s && i < m; j++) {
                        if(boxes[1].type == curToys[i].type) {
                            LL odjemna = min(max(curBoxes[1].val, 0LL), curToys[i].val);
                           res += odjemna ;
                           curBoxes[1].val -= odjemna;
                           curToys[i].val -= odjemna;
                        }
                        i++;
                    }
                    for(int j = 0; j < p && i < m; j++) {
                        if(boxes[2].type == curToys[i].type) {
                            //printf("curBoxes[2] = %d, curToys[%d] = %d\n", curBoxes[2].val, i, curToys[i]);
                           LL odjemna = min(max(curBoxes[2].val, 0LL), curToys[i].val);
                           res += odjemna ;
                           curBoxes[2].val -= odjemna;
                           curToys[i].val -= odjemna;
                           //printf("i = %d  ", i);
                           //printf("curBox[2].val: = %d, curToys[%d] = %d\n", curBoxes[2].val, i, curToys[i]);
                        }
                        i++;
                    }
                    //printf("%d %d %d res: %d\n", l, s, p, res);
                    //printf("KONIECPROBY\n");
                    /*
                    if(l == 3 && s == 0)
                        printf("\t BOX: %d %d %d\n", curBoxes[0].val, curBoxes[1].val, curBoxes[2].val);
                    *
                     if(l == 2 && s == 0)
                        printf("\t BOX: %d %d %d\n", curBoxes[0].val, curBoxes[1].val, curBoxes[2].val);
                    */
                    maks = max(maks, res);
                }
        printf("Case #%d: %lld\n", t, maks);
    }
}
