#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int main()
{
    int T,i;
    scanf("%d",&T);
    for (i=1;i<=T;i++) {
        int resC,C,D,V;
        resC=0;
        scanf("%d%d%d",&C,&D,&V);
        int j;
        bool possible[V];
        for (j=0;j<V;j++) {
            possible[j]=false;
        }
        int tab[D];
        for (j=0;j<D;j++) {
            int res;
            scanf("%d",&res);
            tab[j]=res;
        }
        // On a parsé
        // On vérifie qu'on peut faire <=V
        for (j=1;j<=V;j++) {
            int k,l;
            for (k=0;k<D;k++){
                for (l=0;l<D;l++) {
                   // printf("tab[l] vaut %d et tab[k} vaut %d et j vaut %d ",tab[l],tab[k],j);
                    if ((tab[l]+tab[k]==j)||(tab[l]==j)||(tab[k]==j)) {
                            if (tab[l]!=tab[k]) {
                                possible[j-1]=true;
                                }
                    }
                    //printf("possible de j-1 vaut %d",possible[j-1]);
                }
            }
        }
        for (j=0;j<V;j++) {
            if (possible[j]==false) {
                resC=1;
            }
        }



        printf("Case #%d: %d\n",i,resC);
    }
    return 0;
}
