#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main () {
    FILE *fin  = fopen ("C-large.in", "r");
    FILE *fout = fopen ("output.txt", "w");
    /* -------------- START -------------- */
    int testcase; long int answer;
    int t; long int a,b;
    int i,j,k,m,l,out;
    /**/ int check[7]={0}; int top; int c,same;
    char bef[50],aft[50];
    fscanf(fin,"%d",&t);
    for(testcase=1;testcase<=t;testcase++){
        answer=0;
        fscanf(fin,"%ld%ld",&a,&b);
        for(i=a;i<=b;i++){
            for(k=0;k<7;k++) check[k]=0;
            top=0;
            itoa(i,bef,10);
            l=strlen(bef);
            for(k=1;k<=l;k++){
                for(m=0;m<l;m++){
                    aft[m]=bef[(m+k)%l];
                }
                out=atol(aft);
                same=0;
                for(c=0;c<=top;c++){
                    if(out==check[c]) same=1;
                }
                if(same==0){ check[top]=out; top++; }
                for(m=0;m<50;m++) aft[m]='\0';
                if(out>=a&&out<=b&&out>i&&same==0){
                    answer++;
                    //fprintf(fout,"%d %d\n",i,out);
                }
            }
        }
        fprintf(fout,"Case #%d: %ld\n",testcase,answer);
    }
    /* --------------- END --------------- */
}
