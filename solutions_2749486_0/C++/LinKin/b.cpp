#pragma comment(linker, "/STACK:16777216")

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
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

long X,Y;

int main( void )
{
    long i,j,Icase,k=0;

    //freopen("text1.txt","r",stdin );
    freopen("B.in","r",stdin );
    freopen("B.out","w",stdout );

    cin>>Icase;
    while( Icase-- ){
        scanf("%ld%ld",&X,&Y );
        printf("Case #%ld: ",++k );
        char sx[] = "WE";
        if( X<0 ){
            swap( sx[0],sx[1] );
            X = -X;
        }
        for( i=1;i<=X;i++ ){
            printf("%s",sx );
        }
        char sy[] = "SN";
        if( Y<0 ){
            swap( sy[0],sy[1] );
            Y = -Y;
        }
        for( i=1;i<=Y;i++ ){
            printf("%s",sy );
        }
        printf("\n");
    }


    return 0;
}
