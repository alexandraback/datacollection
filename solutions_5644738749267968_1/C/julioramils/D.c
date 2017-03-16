#include <stdio.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define true 1
#define false 0

static int compareK2 (const void * a, const void * b)
{
  if (*(double*)a < *(double*)b) return 1;
  else if (*(double*)a > *(double*)b) return -1;
  else return 0;
}

int main(){
    freopen ("D-large.in","r",stdin);
    freopen ("D_out_large","w",stdout);
    int T;
    int N;
    int caso=0;
    double naomi[1000];
    double ken[1000];
    int i,j;
    int dw;
    int w;
    double aux;


    scanf("%d", &T);
    while(T--){
        caso++;
        scanf("%d", &N);
        dw=0;
        w=0;
        for(i=0;i<N;i++){
            scanf("%lf", &aux);
            naomi[i]=aux;
        }
        for(i=0;i<N;i++){
            scanf("%lf", &aux);
            ken[i]=aux;
        }

        qsort (naomi, N, sizeof(double), compareK2);
        qsort (ken, N, sizeof(double), compareK2);


        i=0;j=0;
        while(j<N){
            if(naomi[i]>ken[j++]){
                i++;
                dw++;
            }

        }
        i=j=0;
        while(i<N){
            if(naomi[i++]>ken[j]){
                w++;
            }else{
                j++;
            }

        }

        printf("Case #%d: %d %d\n", caso, dw, w);


    }
    return 0;
}
