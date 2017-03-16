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

#define MAX 107
#define MAX_N 4000000
#define INF 1000007

struct NODE{
    bool IsS;
    long Child[27];
};

long nN;
NODE Node[MAX_N+7];

long N;
char Str[MAX+7];
long Sol[MAX+7];


void Insert( string &s )
{
    long i,I = 0;
    for( i=0;i<s.size();i++ ){
        char Ch = s[i]-'a';
        if( !Node[I].Child[Ch] ){
            Node[I].Child[Ch] = ++nN;
        }
        I = Node[I].Child[Ch];
    }
    Node[I].IsS = true;
}

void Traverse( string &t,long I,long u,long c,long Last,long NwL )
{
    if( Node[u].IsS == true ){
        Sol[NwL] = min( Sol[NwL],c+Sol[NwL-I] );
    }
    if( I==t.size()) return;
    long i;
    for( i=0;i<26;i++ ){
        if( !Node[u].Child[i] ) continue;
        if( i==(t[I]-'a') ){
            Traverse( t,I+1,Node[u].Child[i],c,Last,NwL );
        }
        else if( I-Last>=5 ){
            Traverse( t,I+1,Node[u].Child[i],c+1,I,NwL );
        }
    }
}


int main( void )
{
    long i,j,Icase,k = 0;;
    string s;

    //freopen("text1.txt","r",stdin );
    freopen("C.in","r",stdin );
    freopen("C.out","w",stdout );

    //FILE *fp = fopen("a.txt","r" );
    FILE *fp = fopen("garbled_email_dictionary.txt","r" );
    while( fscanf( fp,"%s",Str )==1 ){
        s = Str;
        reverse( s.begin(),s.end());
        Insert( s );
    }


    cin>>Icase;
    while( Icase-- ){
        scanf("%s",&Str );
        s = Str;
        for( i=0;i<s.size();i++ ){
            string t = s.substr( 0,i+1 );
            reverse( t.begin(),t.end());
            Sol[i+1] = INF;
            Traverse( t,0,0,0,-INF,i+1 );
        }
        long Ans = Sol[s.size()];
        printf("Case #%ld: %ld\n",++k,Ans );
    }

    return 0;
}
