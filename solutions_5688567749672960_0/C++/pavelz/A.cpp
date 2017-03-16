// Just brute force solution
// https://code.google.com/codejam/contest/6224486/dashboard#s=p1
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)

#define MAX_N 1000100

int result[MAX_N];
int digits[20];
int totalDigits;
bool used[20];

char c = 0;
long long int getInt() {
    long long int r = 0;
    while (!(c >= '0' && c <= '9')) c = getc_unlocked(stdin);
    while (c >= '0' && c <= '9') {
        r = r * 10 + (c - '0');
        c = getc_unlocked(stdin);
    }
    return r;
}

void perm(int pos, int index, int value) {
    if (pos < totalDigits) {
        FOR(i, totalDigits)
            //if (!used[i] && (pos > 0 || (pos == 0 && digits[i] != 0))) {
            if (!used[i]) {
                used[i] = true;
                perm(pos + 1, index, value * 10 + digits[i]);
                used[i] = false;
            }
    } else {
        /*if (value < index && result[value] + 1 < result[index]) {
            result[index] = result[value] + 1;
        }*/
        if (value < MAX_N && result[value] > result[index] + 1) {
            result[value] = result[index] + 1;
        }
    }
}

void perm2(int pos, int index, int value) {
    if (pos < totalDigits) {
        FOR(i, totalDigits)
            if (!used[i]) {
                used[i] = true;
                perm2(pos + 1, index, value * 10 + digits[i]);
                used[i] = false;
            }
    } else {
        if (value < MAX_N && (result[index] + 1 < result[value] /*|| result[value] + 1 <= result[index])*/)) {
            printf("Error: %d\n", index);
        }
    }
}

int main(void) {
    FOR(i, MAX_N) result[i] = i;
    result[0] = result[1] = 1;
    FORE(i, 2, MAX_N) {
        if (result[i - 1] + 1 < result[i]) result[i] = result[i - 1] + 1;
        int temp = i;
        int c = 0;
        while (temp > 0) {
            digits[c++] = temp % 10;
            temp /= 10;
        }
        int total = 0;
        FOR(j, c) total = total * 10 + digits[j];
        if (total < MAX_N && result[total] > result[i] + 1) result[total] = result[i] + 1;
    }

    int cases = getInt();
    for(int c=1;c<=cases;c++) {
        long long int n = getInt();
        printf("Case #%d: %d\n", c, result[n]);
    }
}
