#define OSMOS
#ifdef OSMOS
#include <stdio.h>
//#define _DEBUG_

void quickSortR(long *a, const long N) {
    long i = 0, j = N;
    long p = a[ N>>1 ], temp;
    do {
        while ( a[i] < p ) i++;
        while ( a[j] > p ) j--;
        if (i <= j) {
            temp = a[i]; a[i] = a[j]; a[j] = temp;
            i++; j--;
        }
    } while ( i<=j );
    if ( j > 0 ) quickSortR(a, j);
    if ( N > i ) quickSortR(a+i, N-i);
}

int main()
{
#ifdef _DEBUG_
    FILE *infile = stdin,
         *outfile = stdout;
#else
    FILE *infile = fopen("/CodeJam/A-small.in", "r"),
         *outfile = fopen("/CodeJam/A-small.txt", "w");
#endif
    int T;
    fscanf(infile, "%d", &T);
    
    for (int t = 1; t <= T; t++) {
        long a = 0, n = 0;
        fscanf(infile, "%ld %ld", &a, &n);
        long motes[1000] = {0};
        for (long i = 0; i < n; i++) {
            fscanf(infile, "%ld", motes + i);
        }
        
        quickSortR(motes, n - 1);
        
        long result = n, cnt = n;
        if (a > 1) {
            for (int i = 0; i < n; i++) {
                while (a <= motes[i]) {
                    a += a - 1;
                    cnt++;
                }
                
                a += motes[i];
                cnt--;
                if (cnt < result) {
                    result = cnt;
                }
            }
        }
        
        fprintf(outfile, "Case #%d: %ld\n", t, result);
    }
    
    fclose(infile);
    fclose(outfile);
}

#endif