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

#define MAX 107

long N,Len;
char Str[MAX+7];
char Tmp[MAX+7];

int main( void )
{
    long i,j,Icase,k=0,Kase = 0;

    //freopen("text1.txt","r",stdin );
    freopen("A.in","r",stdin );
    freopen("A.out","w",stdout );

    cin>>Icase;
    while( Icase-- ){
        scanf("%s%ld",Str,&N );
        Len = strlen( Str );
        long Ans = 0;
        for( i=0;i<Len;i++ ){
            for( j=i;j<Len;j++ ){
                MS( Tmp );
                strncpy( Tmp,&Str[i],j-i+1 );
                char *p = strtok( Tmp,"aeiou" );
                while( p ){
                    if( strlen( p ) >= N ){
                        Ans++;
                        break;
                    }
                    p = strtok( NULL,"aeiou" );
                }
            }
        }
        printf("Case #%ld: %ld\n",++Kase,Ans );

    }

    return 0;
}
