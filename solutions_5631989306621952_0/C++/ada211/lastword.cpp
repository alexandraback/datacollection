#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int T;
char strings[105][1005];
char last[105][3005];
char first;
int len;

main(){
    FILE *inp = fopen("lastwordS.in", "r"), *outp = fopen("lastword.out", "w");
    fscanf(inp, "%d", &T);
    int i, j, before, after;
    char temp;
    fscanf(inp, "%c", &temp);
    for(i = 0; i < T; i++){
        len = 0;
        before = 0;
        after = 0;
        for(j = 0; j < 1005; j++){
            fscanf(inp, "%c", &temp);
            if(temp >= 'A' && temp <= 'Z'){
                len++;
                strings[i][j] = temp;
                if(j == 0){
                    last[i][1000] = temp;
                    first = temp;
                }
                else{
                    if(temp >= first){
                        before++;
                        first = temp;
                        last[i][1000-before] = temp;
                    }
                    else{
                        after++;
                        last[i][1000+after] = temp;
                    }
                }
            }
            else break;
        }
        fprintf(outp, "Case #%d: ", i+1);
        for(j = 1000-before; j < 1000 - before + len; j++){
            fprintf(outp, "%c", last[i][j]);
        }
        fprintf(outp, "\n");
    }
    return 0;
}
