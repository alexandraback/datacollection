#include <stdio.h>
int cz(int a){
    if(a<1) return 1;
    else return a;
}
int main () {
    FILE *fin  = fopen ("B-large.in", "r");
    FILE *fout = fopen ("output.txt", "w");
    /* -------------- START -------------- */
    int testcase,answer,tmp;
    int t,n,s,p,score[125];
    int i;
    fscanf(fin,"%d",&t);
    for(testcase=1;testcase<=t;testcase++){
        answer=0; tmp=0;
        fscanf(fin,"%d%d%d",&n,&s,&p);
        for(i=0;i<n;i++){
            fscanf(fin,"%d",&score[i]);
        }
        for(i=0;i<n;i++){
            if(p==0) answer++;
            else if(score[i]>=cz((3*p)-2)) answer++;
            else if(score[i]>=cz((3*p)-4)) tmp++;
            //printf("%d %d %d\n",testcase,answer,tmp);
        }
        if(tmp<=s) answer+=tmp;
        else if(tmp>s) answer+=s;
        fprintf(fout,"Case #%d: %d\n",testcase,answer);
    }
    /* --------------- END --------------- */
    exit (0);
}

/*
fscanf(fin, "%d", &a);
fprintf(fout, "%d", a);
*/
