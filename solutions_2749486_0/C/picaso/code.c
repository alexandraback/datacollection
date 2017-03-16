#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int vowel(char c){
    if(c!='a' && c!='e' && c!='u' && c!='o' && c!='i')
        return 0;
    else return 1;
}
int main(){
    int tt=1,t;
    FILE *fr=fopen("/Users/akshaykhanna/Downloads/B-small-attempt1.in.txt", "r");
    FILE *fw=fopen("/Users/akshaykhanna/Desktop/o.txt", "w");
    fscanf(fr,"%d",&t);
    while (tt<=t) {
        int a=0,x1=1,x,y;
        fscanf(fr,"%d %d",&x,&y);
        fprintf(fw, "Case #%d: ",tt);
        if(x>=0){
            while(a!=x){
                fprintf(fw,"W");
                a-=x1;
                x1++;
                fprintf(fw,"E");
                a+=x1;
            }
        }
        else {
            while(a!=x){
                fprintf(fw,"E");
                a+=x1;
                x1++;
                fprintf(fw,"W");
                a-=x1;
            }
        }
        
        if(y>=0){
            x=y;a=0;
            while(a!=x){
                fprintf(fw,"S");
                a-=x1;
                x1++;
                fprintf(fw,"N");
                a+=x1;
            }
        }
        else{
            x=y;a=0;
            while(a!=x){
                fprintf(fw,"N");
                a+=x1;
                x1++;
                fprintf(fw,"S");
                a-=x1;
            }
        }
        tt++;
    }
    return 0;
}