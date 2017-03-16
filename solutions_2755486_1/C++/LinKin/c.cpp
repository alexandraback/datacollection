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

#define MAX 6000007
#define MAX_D 1000007
#define INF 100000000000007LL

typedef long long Long;

struct ATTACK{
    Long I;
    Long W,E;
    Long S;
    ATTACK( Long I,Long W,Long E,Long S )
    {
        this->I = I;
        this->E = 2*E;
        this->W = 2*W;
        this->S = S;
    }
};

Long N;
vector<ATTACK> Att[MAX_D+7];
Long nI;
map<Long,Long> Ind;
Long ST[4*MAX+7];
Long LZ[4*MAX+7];

void Init( Long n,Long l,Long r )
{
    ST[n] = LZ[n] = 0;
    if( l==r ) return;
    Long m = ( l+r )/2;
    Init( 2*n,l,m );
    Init( 2*n+1,m+1,r );
}


void CheckLZ( Long n,Long l,Long r )
{
    ST[n] = max( ST[n],LZ[n] );
    if( l!=r ){
        LZ[2*n] = max( LZ[2*n],LZ[n] );
        LZ[2*n+1] = max( LZ[2*n+1],LZ[n] );
    }
    LZ[n] = 0;
}

Long Find( Long n,Long l,Long r,Long p,Long q )
{
    CheckLZ( n,l,r );//printf("%ld %ld %ld %ld %ld\n",n,l,r,p,q );
    if( q<l || p>r ) return INF;
    if( p<=l && q>=r ) return ST[n];
    Long m = (l+r)/2;
    return min( Find( 2*n,l,m,p,q ),Find( 2*n+1,m+1,r,p,q ) );
}

Long Update( Long n,Long l,Long r,Long p,Long q,Long v )
{
    CheckLZ( n,l,r );
    if( q<l || p>r ) return ST[n];
    if( p<=l && q>=r ){
        LZ[n] = max( LZ[n],v );
        CheckLZ( n,l,r );
        return ST[n];
    }
    Long m = (l+r)/2;
    return ST[n] = min( Update( 2*n,l,m,p,q,v ),Update( 2*n+1,m+1,r,p,q,v ) );
}

void Insert( Long v )
{
    Ind[v] = Ind[v-1] = Ind[v+1] = 0;
}

int main( void )
{
    Long i,j,p,Icase,k=0;
    Long D,nA,W,E,S,Del_D,Del_P,Del_S;

    //freopen("text1.txt","r",stdin );
    freopen("C.in","r",stdin );
    freopen("C.out","w",stdout );

    cin>>Icase;
    while( Icase-- ){
        cin>>N;
        Ind.clear();
        for( i=1;i<=N;i++ ){
            cin>>D>>nA>>W>>E>>S>>Del_D>>Del_P>>Del_S;
            Att[D].pb( ATTACK( i,W,E,S ) );
            Insert( 2*W ),Insert( 2*E );
            for( j=2;j<=nA;j++ ){
                D += Del_D;
                W += Del_P;
                E += Del_P;
                S += Del_S;
                Att[D].pb( ATTACK( i,W,E,S ) );
                Insert( 2*W ),Insert( 2*E );
            }
        }
        map<Long,Long>::iterator It = Ind.begin();
        nI = 0;
        while( It != Ind.end()){
            It->second = ++nI;
            //printf("%ld %ld\n",It->first,It->second );
            It++;
        }
        Init( 1,1,nI );
        Long Ans = 0;
        for( i=0;i<=MAX_D;i++ ){
            for( j=0;j<Att[i].size();j++ ){
                Long m = Find( 1,1,nI,Ind[Att[i][j].W],Ind[Att[i][j].E] );
                //printf("%ld %ld %ld %ld %ld\n",Att[i][j].I,Att[i][j].W,Att[i][j].E,Att[i][j].S,m );//return 0;
                if( m < Att[i][j].S ){
                    Ans++;
                }
            }
            for( j=0;j<Att[i].size();j++ ){//printf("%ld %ld %ld %ld\n",Att[i][j].I,Att[i][j].W,Att[i][j].E,Att[i][j].S );
                Update( 1,1,nI,Ind[Att[i][j].W],Ind[Att[i][j].E],Att[i][j].S );
            }
            Att[i].clear();
        }
        printf("Case #%lld: %lld\n",++k,Ans );
        cerr<<Icase<<endl;
    }

    return 0;
}
