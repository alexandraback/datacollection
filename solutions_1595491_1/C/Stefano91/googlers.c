#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 100
#define VERBOSE 0

typedef struct {
    int s1;
    int s2;
    int s3;
    int max;
} Scores;

typedef struct {
    Scores score;
    Scores scoresurprising;
    int existssurprising;
} PossibilitiesArray;

PossibilitiesArray possibilities[31];


int solve(int googlers[],PossibilitiesArray possibilities[], int N, int S, int p) {
    int i;
    int total, surp=0;
    int result=0;
    for (i=0;i<N;i++) {
        total = googlers[i];

        if (possibilities[total].score.max >= p) {
            result++;
        }
        else if (surp < S && possibilities[total].existssurprising == 1 && possibilities[total].scoresurprising.max >= p) {
            result++;
            surp++;
        }

    }
    return result;
}

int main() {
    FILE *finput,*foutput,*fexinput,*fexoutput;
    int i,j;
    int T,N,S,p,R;
    int googlers[MAX];
    Scores exscore;

    finput = fopen("input.txt","r");
    foutput = fopen("output.txt","w");




    for (exscore.s1=0;exscore.s1<=10;exscore.s1++) {
        for (exscore.s2=exscore.s1;exscore.s2<=exscore.s1+2 && exscore.s2<=10;exscore.s2++) {
            for (exscore.s3=exscore.s2;exscore.s3<=exscore.s1+2 && exscore.s3<=10;exscore.s3++) {
                if (exscore.s1+exscore.s2+exscore.s3 <= 30) {
                    exscore.max = exscore.s3;
                    if (exscore.s3-exscore.s1 == 2) {
                        possibilities[exscore.s1+exscore.s2+exscore.s3].scoresurprising = exscore;
                        possibilities[exscore.s1+exscore.s2+exscore.s3].existssurprising = 1;
                    }
                    else
                        possibilities[exscore.s1+exscore.s2+exscore.s3].score = exscore;
                }
            }
        }
    }

/*
    for (i=0;i<31;i++) {
        printf("\n");
        printf("\n%d %d %d",possibilities[i].score.s1,possibilities[i].score.s2,possibilities[i].score.s3);
        printf("\n%d %d %d",possibilities[i].scoresurprising.s1,possibilities[i].scoresurprising.s2,possibilities[i].scoresurprising.s3);
    }
*/

    fscanf(finput, "%d\n", &T);

    for (i=1;i<=T;i++) {

        fscanf(finput,"%d %d %d",&N,&S,&p);

        for (j=0;j<N;j++)
            fscanf(finput,"%d",&(googlers[j]));

        R = solve(googlers,possibilities,N,S,p);

        if (VERBOSE)
            printf("\n => Case #%d: %d", i, R);

        fprintf(foutput, "Case #%d: %d", i, R);

        if (i<T)
            fprintf(foutput, "\n");
    }


    fclose(finput);
    fclose(foutput);

    return 0;
}
