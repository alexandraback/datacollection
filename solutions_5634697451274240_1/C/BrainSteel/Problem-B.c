/* 
 
Google Code Jam Qualification Round
April 8, 2016

Jesse Pritchard
Public contact: chaserdevelopment@gmail.com
 
Problem B

*/

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

void strreverse(char* src, long num) {
    long i;
    char* mod = malloc(num);
    
    for (i = 0; i < num; i++) {
        mod[i] = src[num - i - 1];
    }
    
    for (i = 0; i < num; i++) {
        src[i] = mod[i];
    }
    
    free(mod);
}

void panflip(char* src, long num) {
    long i;
    for (i = 0; i < num; i++) {
        if (src[i] == '+') {
            src[i] = '-';
        }
        else {
            src[i] = '+';
        }
    }
    
    strreverse(src, num);
}

long ishappy(char* src) {
    long i;
    for (i = 0; i < strlen(src); i++) {
        if (src[i] != '+') {
            return 0;
        }
    }
    return 1;
}

long firstsadindex(char* src) {
    
    if (ishappy(src)) {
        return -1;
    }

    long i;
    for (i = 0; i < strlen(src); i++) {
        if (src[i] == '-') {
            return i;
        }
    }
    return i;
}

long numtoflip(char* src) {
    // Find the first sad character
    long first = firstsadindex(src);
    
    if (first == -1) {
        // The string was happy
        return 0;
    }
    
    // If it's 0, find the first happy character and flip just before it
    if (first == 0) {
        long i;
        for (i = 0; i < strlen(src); i++) {
            if (src[i] == '+') {
                break;
            }
        }
        return i;
    }
    // Otherwise, flip up to, but not including, first
    else {
        return first;
    }

}

long findtotalflips(char* src) {
    if (ishappy(src)) {
        return 0;
    }
    
    panflip(src, numtoflip(src));
    return findtotalflips(src) + 1;
}

int main() {
    int num, T;
    char buf[100];
    scanf(" %d", &num);
    for (T = 0; T < num; T++) {
        
        scanf(" %[+-]", buf);
        
        printf("Case #%d: %ld\n", T + 1, findtotalflips(buf));
    }
    return 0;
}
