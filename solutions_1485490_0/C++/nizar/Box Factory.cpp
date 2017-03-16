#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std ;

FILE *in = fopen("hold.in", "r") ;
FILE *out = fopen("hold.out", "w") ;

int A[101], An ;
long long a[101] ;
int B[101], Bn ;
long long b[101] ;
long long best[101][101] ;

long long minn(long long a, long long b)
{
    return a < b ? a : b ;
}

long long maxx(long long a,long long b)
{
    return a > b ? a : b ;
}

long long solve(int i, int j)
{
    if( i >= An || j >= Bn ) return 0 ;
    //if( best[i][j] != -1 ) return best[i][j] ;
    long long ret ;
    long long x=0, u, v, w ;
    if( A[i] == B[j] )
    {
        x = minn(a[i], b[j]) ;// + solve(i+1, j+1) ;
        a[i] -= x ;
        b[j] -= x ;
    }

    u = solve(i+1, j) ;
    v = solve(i, j+1) ;
    w = solve(i+1, j+1) ;
    ret = maxx(maxx(u, v), w) + x ;
    a[i] += x ;
    b[j] += x ;

    best[i][j] = ret ;
    return ret ;
}

int main()
{
	int i, j, k ;
	int T, g ;
	long long l ;

	fscanf(in, "%d", &T) ;
	for(g=1;g<=T;g++)
	{
	    fscanf(in, "%d%d", &An, &Bn) ;
	    for(j=0;j<An;j++) fscanf(in, "%lld%d", &a[j], &A[j]) ;
	    for(j=0;j<Bn;j++) fscanf(in, "%lld%d", &b[j], &B[j]) ;
	    for(i=0;i<An;i++)
            for(j=0;j<Bn;j++)
                best[i][j] = -1 ;
        l = solve(0, 0) ;
        fprintf(out, "Case #%d: %lld\n", g, l) ;
	}


	return 0 ;
}
