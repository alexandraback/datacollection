#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// for qsort
/*
int compare(int *t, int *s) {
    return *t - *s;
}
*/

long long N;
char buf[20];
char rev[20];
int len;

int need_rev(void) {
    int i;
    if(buf[0] != '1') return 1;
    for(i = 1; i < len/2; ++i) {
        if(buf[i] != '0') return 1;
    }
    return 0;
}

int latter_0(void) {
    int i;
    for(i = len/2; i < len; ++i) {
        if(buf[i] != '0') return 0;
    }
    return 1;
}

int is_pow10(void) {
    int i;
    if(buf[0] != '1') return 0;
    for(i = 1; i < len; ++i) {
        if(buf[i] != '0') return 0;
    }
    return 1;
}

int main(void) {
    int dataset_num, case_num;
    int i, j;
    int t;

    scanf("%d", &dataset_num);
    gets(buf);
    for(case_num = 1; case_num <= dataset_num; ++case_num) {
        fgets(buf, 19, stdin);
        N = 0LL;
        len = strlen(buf)-1; // ‰üs•¶ŽšH
        buf[len] = '\0';

        if(len == 1) {
            N = buf[0] - '0';
        }
        else {
            for(i = 1; i < len; ++i) { // Œ…‡‚í‚¹
                t = 1;
                for(j = 0; j < i/2; ++j) {
                    t *= 10;
                }
                N += (long long)t; // ‰º”¼•ª‚ð9‚Å–„‚ß‚Ä‚Ð‚Á‚­‚è•Ô‚·
                
                t = 1;
                for(j = 0; j < i - i/2; ++j) {
                    t *= 10;
                }
                N += (long long)(t-1); // ˆê”Ô‰º‚ª1‚È‚Ì‚ÅŒJ‚èã‚°‚Ü‚Å‚Í‚±‚ê‚¾‚¯
            }
            
            
            if(!is_pow10()) {
                if(latter_0()) {
                    long long x;
                    sscanf(buf, "%lld", &x);
                    sprintf(buf, "%lld", x-1);
                    ++N;
                }
                //fprintf(stderr, "%s\n", buf);
                if(need_rev()) {
                    for(i = 0; i < len/2; ++i) {
                        rev[len/2-i-1] = buf[i];
                    }
                    for(i = 0; i < len/2; ++i) {
                        if(rev[i] != '0') break;
                    }
                    sscanf(rev+i, "%d", &t);
                    N += t; // t‚É‚µ‚Ä‚Ð‚Á‚­‚è•Ô‚µ‚½
                    for(i = 0; i < len-len/2; ++i) {
                        rev[i] = buf[i+len/2];
                    }
                    for(i = 0; i < len-len/2; ++i) {
                        if(rev[i] != '0') break;
                    }
                    sscanf(rev+i, "%d", &t);
                    if(t == 0) fprintf(stderr, "what??\n");
                    N += t;
                }
                else {
                    for(i = 0; i < len-len/2; ++i) {
                        rev[i] = buf[i+len/2];
                    }
                    for(i = 0; i < len-len/2; ++i) {
                        if(rev[i] != '0') break;
                    }
                    sscanf(rev+i, "%d", &t);
                    if(t == 0) fprintf(stderr, "what??\n");
                    N += t;
                }
            }
        }

        printf("Case #%d: %lld\n", case_num, N);
    }

    return 0;
}
