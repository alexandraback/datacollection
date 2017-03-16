#include <stdio.h>
#include <vector>
#include <algorithm>

//#define PROBLEM "a"
//#define DEFAULT_INPUT (PROBLEM ".in")
//#define DEFAULT_OUTPUT (PROBLEM ".out")

//#define debugf fprintf
#define debugf __noop

FILE *Fin, *Fout;

void Test(int testNo)
{
    long long r = 0, t = 0;

    // input
    fscanf( Fin, "%I64u %I64u", &r, &t );

    int count = -1;
    while( t >= 0 )
    {
        count++;
        t -= r;
        t -= r;
        t -= 1;
        r += 2;
        debugf( stderr, "count: %d, t: %I64d, r: %I64d\n", count, t, r );
    }

    // output
    fprintf( Fout, "Case #%d: %d\n", testNo+1, count );
}

void Run()
{
    int T = 0;

    fscanf( Fin, "%d\n", &T );
    for( int t=0; t<T; t++ )
    {
        Test(t);
    }
}

int main(int argc, char* argv[])
{
    /*Fin  = fopen(argc >= 2 ? argv[1] : DEFAULT_INPUT , "rt" ); if( Fin  == NULL )*/ Fin  = stdin;
    /*Fout = fopen(argc >= 3 ? argv[2] : DEFAULT_OUTPUT, "w+t"); if( Fout == NULL )*/ Fout = stdout;

    Run();

    fflush(Fout);
    fclose(Fout);
    fclose(Fin);
    return 0;
}