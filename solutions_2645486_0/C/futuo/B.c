#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_N 10
#define MAX_E 5

int memoise[MAX_N][MAX_E];
char memoise_set[MAX_N][MAX_E];

int values[MAX_N];

int recurse( int job, int avail );

int T,E,R,N;

int main(){

    scanf( "%d", &T );

    int testcase;
    for(testcase = 1; testcase<=T; testcase++){

        memset( memoise, 0, sizeof(int) * MAX_N * MAX_E * MAX_E );
        memset( memoise_set, 0, sizeof(int) * MAX_N * MAX_E );

        scanf( "%d %d %d", &E, &R, &N );

        int i;
        for(i=0; i<N; i++){
            scanf("%d", &values[i]);
        }

        int maxgain = recurse(0,E);

        printf("Case #%d: %d\n", testcase, maxgain);

    }
    return 0;
}


int recurse( int job, int avail ){

    if (memoise_set[job][avail])
        return memoise[job][avail];

    if (job == N-1)
        return avail * values[job];

    int i, max = 0, next, tmp;
    for( i = 0; i <= avail; i++ ){
        
        next = avail-i+R;
        if( next > E )
            next = E;

        tmp = recurse( job+1, next ) + values[job]*i;

        if ( tmp > max )
            max = tmp;

    }

    memoise[job][avail] = max;
    memoise_set[job][avail] = 1;

    return max;
}


