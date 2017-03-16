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

int numDigits(long long int n) {
    int c = 0;
    while (n > 0) {
        c++;
        n /= 10;
    }
    return c;
}

int firstDigit(long long int n) {
    while (n >= 10) n /= 10;
    return n;
}

int lastDigit(long long int n) {
    return n % 10;
}

long long int power(int digits) {
    long long int result = 1;
    FOR(i, digits) result *= 10;
    return result;
}

long long int reverse(long long int n) {
    int c = 0;
    while (n > 0) {
        digits[c++] = n % 10;
        n /= 10;
    }
    FOR(j, c) n = n * 10 + digits[j];
    return n;
}

int main(void) {
    int cases = getInt();
    for(int c=1;c<=cases;c++) {
        long long int n = getInt();
        long long int result = 0;
        while (n > 20) {
            int tg = numDigits(n) / 2;
            long long int secondHalf = n % power(tg);
            if (secondHalf > 1) {
                result += secondHalf - 1;
                n -= secondHalf - 1;
            }
            if (lastDigit(n) != 0 && reverse(n) < n) {
                result++;
                n = reverse(n);
            }
            secondHalf = n % power(tg);
            result += secondHalf + 1;
            n -= secondHalf + 1;
            //printf("%lld %lld\n", n, result);
        }
        result += n;
        printf("Case #%d: %lld\n", c, result);
    }
}
