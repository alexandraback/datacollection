
#include <stdio.h>

char keys[101];

char target[101];

char typed[101];


int matches;
int maxmatches;
int lines;
int K,L,S;

int cmpN(char *a, char *b, int n) {
    int i;
    for (i=0;i<n;i++) {
        if (a[i]!=b[i]) return 0;
    }
    return 1;
}

void score(void) {
    int i;
    int m=0;
    typed[S]=0;
    for (i=0;i<S;i++) {
        if (cmpN(typed+i,target,L)) m++;
    }
    if (m>maxmatches) maxmatches=m;
    matches+=m;
    lines++;
}

void countBaseK(int i) {
    int j;
    if (i==S) {score();return;}
    for (j=0;j<K;j++) {
        typed[i]=keys[j];
        countBaseK(i+1);
    }
}

void docase(void) {
    scanf("%d %d %d",&K,&L,&S);
    scanf("%s",keys);
    scanf("%s",target);
    matches=maxmatches=lines=0;
    countBaseK(0);
    if (lines!=0) 
        printf("%.7f\n",maxmatches-1.0*matches/lines);
    else
        printf("0\n");
}

int main(int argc, char **argv) {
    int T;
    int casenum;
    scanf("%d",&T);
    for (casenum=1;casenum<=T;casenum++) {
        printf("Case #%d: ",casenum);
        docase();
    }
    return 0;
}
