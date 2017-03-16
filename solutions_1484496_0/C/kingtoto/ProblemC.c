#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *entree="C-small-attempt0.in.txt";
char *sortie="C-small-attempt0.out";

int T, N;

int val[20];
int somme[2000000];

int main(void)
{
    FILE *fin, *fout;
    unsigned int I;
    int i, j, tmp, yes;

    if((fin=fopen(entree,"r")) == 0) {
        printf("Impossible d'ouvrir %s\n", entree);
        return(10);
    }

    if((fout=fopen(sortie,"w")) == 0) {
        printf("Impossible d'ouvrir %s\n", sortie);
        return(11);
    }

    fscanf(fin, "%d\n", &T);

    for(I=0; I<T; I++) {

        fscanf(fin, "%d", &N);
        for(i=0; i<N; i++)
            fscanf(fin, "%d", &val[i]);

        for(i=0; i<2000000; i++)
            somme[i] = 0;

        yes = 0;
        for(i=0; i<(1<<20); i++) {
            tmp = 0;
            for(j=0; j<20; j++)
                if((i >> j) & 1)
                    tmp += val[j];
            if(somme[tmp] == 0)
                somme[tmp] = i;
            else {
                yes++;
                fprintf(fout, "Case #%d:\n", I+1);
                for(j=0; j<20; j++)
                    if((i >> j) & 1)
                        fprintf(fout, "%d ", val[j]);
                fprintf(fout, "\n");
                for(j=0; j<20; j++)
                    if((somme[tmp] >> j) & 1)
                        fprintf(fout, "%d ", val[j]);
                fprintf(fout, "\n");
                i = 1<<20;
            }
        }

        if(!yes)
            fprintf(fout, "Case #%d:\nImpossible\n", I+1);
    }

    fclose(fin);
    fclose(fout);

    return(0);
}
