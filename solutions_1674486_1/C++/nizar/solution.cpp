#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std ;

FILE *in = fopen("hold.in", "r") ;
FILE *out = fopen("hold.out", "w") ;

int inher[1002][1002] ;
int vis[1002] ;
int N ;

bool solve(int j)
{
    if( vis[j] ) return true ;
    vis[j] = true ;
    int k ;
    for(k=1;k<=N;k++)
        if( inher[j][k] )
            if( solve(k) ) return true ;
    return false ;
}

int main()
{
	int i, j, k, l ;
    int T, g ;

    fscanf(in, "%d", &T) ;
    for(g=1;g<=T;g++)
    {
        fscanf(in, "%d", &N) ;
        for(i=1;i<=N;i++) for(j=1;j<=N;j++) inher[i][j] = 0 ;
        for(i=1;i<=N;i++)
        {
            fscanf(in, "%d", &k) ;
            for(j=0;j<k;j++)
            {
                fscanf(in, "%d", &l) ;
                inher[i][l] = 1 ;
            }
        }

        for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++) vis[j] = 0 ;
            for(j=1;j<=N;j++)
                if( inher[i][j] )
                    if( solve(j) ) break ;
            if( j <= N ) break ;
        }
        if( i <= N )
            fprintf(out, "Case #%d: Yes\n", g) ;
        else
            fprintf(out, "Case #%d: No\n", g) ;

    }

	return 0 ;
}
