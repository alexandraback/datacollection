/* 
 
Google Code Jam Round 1B
May 2, 2015

Jesse Pritchard
Public contact: chaserdevelopment@gmail.com
 
Problem A

*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"

void toString(long val, char* buf){
    char comp[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    int negative = 0;
    if (val < 0) {
        negative = 1;
        val *= -1;
    }
    
    long digtest = val;
    int digits = 1;
    while (digtest >= 10) {
        digtest /= 10;
        digits++;
    }
    if (val == 0) {
        digits = 1;
    }
    else if (negative) {
        digits++;
        buf[0] = '-';
    }
    
    long iii, k;
    for (iii = negative; iii < digits; iii++) {
        k = val / 10;
        buf[digits - (iii + (!negative))] = comp[val - (k * 10)];
        val /= 10;
    }
    
    buf[digits] = '\0';
    return;
}

long fromString(char* s){
    long val = 0;
    while (*s){
        val *= 10;
        val += *s++ - 48;
    }
    return val;
}

char* strreverse(char* s) {
    char* c = s;
    int len = 1;
    while (*c++) {
        len++;
    }
    char* o = malloc(len);
    int i;
    for (i = 0; i < len - 1; i++) {
        o[i] = s[len - 2 - i];
    }
    o[len - 1] = 0;
    return o;
}

int test(long N, long test) {
    char buf[100];
    toString(test, buf);
    long l = strlen(buf);
    if (buf[l-1] == '1') {
        return 1;
    }
    else return 0;
}

long reverseint(long N) {
    char buf[100];
    toString(N, buf);
    char* rev = strreverse(buf);
    long t = fromString(rev);
    free(rev);
    return t;
}

long getCorrect(long N) {
    long S = N;
    long tot = 0, newmin = N, saveA, min = 1;
    long A = N, d = 0, c;
    while (!d) {
        for (c=A;!test(A, c); c--);
        tot+=A-c+1;
        A = reverseint(c);
        if(tot + A >= newmin) d = 1;
        else {newmin = tot + A;saveA = A;}
    }
    
    long i, go;
    char buf[100];
    for (i = 1; i != N; i++) {
        toString(i, buf);
        long l = strlen(buf);
        if (l > 1) {
            int j;
            go = 1;
            for (j = 0; j < strlen(buf); j++) {
                if (buf[j] != '9') {
                    break;
                }
            }
            if (j == strlen(buf)) {
                go = 0;
            }
            if (buf[l - 1] == '9' || ((buf[l-1] - 48) * pow(10, l-1) <= N && (buf[l-1] - 47) * pow(10, l-1) > N)) {
                char* rev = strreverse(buf);
                long test = fromString(rev);
                if (test <= N && test > i) {
                    i = test;
                    min++;
                }
                free(rev);
            }
        }
        if (i==N) break;
        min++;
    }
    min = min > saveA ? saveA : min;
    
    long s = 10;
    while (N > s) {
        tot = 1;
        if (N % s > 1) {
            tot += N % s - 1;
            N -= N % s - 1;
            char buf[100];
            toString(N, buf);
            char* rev = strreverse(buf);
            tot += fromString(rev);
            free(rev);
            if (tot < min) min = tot;
            s *= 10;
        }
        else {
            N--;
            tot++;
        }
    }
    long possible = s > 10 ? getCorrect(s/10 - 1) + S - s/10 + 1: min + 1;
    tot = tot < possible ? tot : possible;
    return min < tot ? min : tot;
}


int main() {
    int num, iii;
    scanf(" %d", &num);
    for (iii = 0; iii < num; iii++) {
        long N, tot = 1, min;
        scanf(" %ld", &N);
        printf("Case #%d: %ld\n", iii + 1, getCorrect(N));
    }
    return 0;
}
