#define CONSONATS
#ifdef CONSONATS
#include "stdio.h"
#include "string.h"
//#define _DEBUG_

inline bool isConsonat(char ch){
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main(){
#ifdef _DEBUG_
    FILE *infile = stdin,
    *outfile = stdout;
#else
    FILE *infile = fopen("/CodeJam/A-large.in", "r"),
    *outfile = fopen("/CodeJam/A-large.txt", "w");
#endif
    int T;
    fscanf(infile, "%d", &T);
    
    char str[1000010] = {0};
    for (int t = 1; t <= T; t++) {
        long long result = 0;
        long con = 0;
        long prev = 0;
        long cnt = 0;
        
        fscanf(infile, "%s%ld", str, &con);
        long len = strlen(str);
        
        for (long i = 0; i < len; i++) {
            if (!isConsonat(str[i])){
                cnt++;
                
                if (cnt == con) {
                    result += (long long)(i + 2 - con - prev) * (len - i);
                    prev = i + 2 - con;
                    cnt--;
                }
            }
            else {
                cnt = 0;
            }
        }
        
        fprintf(outfile, "Case #%d: %lld\n", t, result);
    }
    
    fclose(infile);
    fclose(outfile);
}
#endif