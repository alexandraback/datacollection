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

#define MAX 1000007

typedef long long Long;

long N,Len;
char Str[MAX+7];
long Sum[MAX+7];
long Chunk[MAX+7];

bool IsConsonant( char Ch )
{
    long i;
    char s[] = "aeiou";
    for( i=0;s[i];i++ ){
        if( Ch==s[i] ) return false;
    }
    return true;
}

int main( void )
{
    long i,j,Icase,k=0;

    //freopen("text1.txt","r",stdin );
    freopen("A.in","r",stdin );
    freopen("A.out","w",stdout );

    cin>>Icase;
    while( Icase-- ){
        scanf("%s%ld",&Str[1],&N );
        Len = strlen( &Str[1] );
        for( i=1;i<=Len;i++ ){
            Sum[i] = Sum[i-1] + IsConsonant( Str[i] );
        }
        for( i=N;i<=Len;i++ ){
            Chunk[i] = ( Sum[i] - Sum[i-N] )==N;
        }
        long Last = N-1;
        Long Ans = 0;
        for( i=N;i<=Len;i++ ){
            if( Chunk[i] ) Last = i;
            Ans += (Last-N) + 1;
        }
        cout<<"Case #"<<++k<<": "<<Ans<<endl;

    }

    return 0;
}
