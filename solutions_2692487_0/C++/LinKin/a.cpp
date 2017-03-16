#pragma comment(linker, "/STACK:16777216")

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<algorithm>
#include<list>
using namespace std;

#define pb push_back
#define MS( a ) memset( a,0,sizeof(a))
#define MSV( a,v ) memset( a,v,sizeof(a))

typedef long long Long;

#define MAX 1007

long A,N;
long V[MAX+7];

int main( void )
{
    long i,j,Icase,k = 0;;

    //freopen("text1.txt","r",stdin );
    freopen("A.in","r",stdin );
    freopen("A.out","w",stdout );

    scanf("%ld",&Icase );
    while( Icase-- ){
        scanf("%ld%ld",&A,&N );
        for( i=1;i<=N;i++ ){
            scanf("%ld",&V[i] );
        }
        sort( V+1,V+N+1 );
        long Ans = N,Tot = 0;
        for( i=1;i<=N;i++ ){
            Ans = min( Ans,Tot+N-i+1 );
            if( V[i] < A ) A += V[i];
            else if( A>1 ){
                do{
                    Tot++;
                    A += A-1;
                }
                while( V[i] >= A );
                A += V[i];
            }
            else{
                Ans = min( Ans,Tot+N-i+1 );
                break;
            }
        }
        if( i>N ) Ans = min( Ans,Tot );
        printf("Case #%ld: %ld\n",++k,Ans );
    }


    return 0;
}
