#define CCODE
#ifdef CCODE
#include "stdio.h"
#include "stdlib.h"
typedef long long llong;
#define MAX 20000000
//#define __DEBUG__
#define SUBMIT

bool isPalindrome(long number){
    long nm = 1;
    while (nm * 10 <= number) {
        nm *= 10;
    }
    
    while (nm >= 10) {
        if (number / nm != number % 10 || number % 10 > 2) return false;
        number %= nm;
        number /= 10;
        nm /= 100;
    }
    
    return true;
}

bool isLLongPalindrome(llong number){
    llong nm = 1;
    while (nm * 10 <= number) {
        nm *= 10;
    }
    
    while (nm >= 10) {
        if (number / nm != number % 10) return false;
        number %= nm;
        number /= 10;
        nm /= 100;
    }
    
    return true;
}

long pnumbers[1000];
int pcnt = 0;

long findSqrt(llong n){
    llong start = 1, end = 1, nn = n;
    while (nn > 0) {
        nn >>= 2;
        start <<= 1;
    }
    
    end = start << 1;
    start >>= 1;
    
    while (start < end) {
        llong middle = (start + end) >> 1;
        if (middle * middle == n)
            return (long)middle;
        else if (middle * middle > n) end = middle - 1;
        else if ((middle + 1)*(middle + 1) > n) return middle;
        else start = middle + 1;
    }
    
    return start;
}

void initPalindromes(){
//    pnumbers = (int *)calloc(1000, sizeof(int));
    for (long i = 1; i <= MAX; i++) {
        if (isPalindrome(i))
        {
            llong square = (llong)i * (llong)i;
            if (isLLongPalindrome(square))
            {
#ifdef __DEBUG__
                printf("%ld - %lld\n", i, square);
#endif
                pnumbers[pcnt] = i;
                pcnt++;
            }
        }
    }
    
#ifdef __DEBUG__
    printf("Total count: %d\n", pcnt);
#endif
}

long getResult(long num){
    long result = 0, ind = 0;
    while (ind < pcnt && pnumbers[ind] <= num) {
        result++;
        ind++;
    }
    
    return result;
}

int main(){
    initPalindromes();
    
#ifdef SUBMIT
    FILE *infile = stdin,
    *outfile = stdout;
#else
    FILE *infile = fopen("/CodeJam/C.in", "r"),
    *outfile = fopen("/CodeJam/C.txt", "w");
#endif
    
    int T;
    fscanf(infile, "%d", &T);
    
    for (int t = 1; t <= T; t++) {
        llong a, b;
        fscanf(infile, "%lld%lld", &a, &b);
        a--;
        long asq = findSqrt(a), bsq = findSqrt(b);
        long result = getResult(bsq) - getResult(asq);
        
        fprintf(outfile, "Case #%d: %ld\n", t, result);
    }
    
    fclose(infile);
    fclose(outfile);
}

#endif