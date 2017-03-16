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
#define MAX_D 1000000

struct ATTACK{
    long I;
    long W,E;
    long S;
    ATTACK( long I,long W,long E,long S )
    {
        this->I = I;
        this->E = 2*E;
        this->W = 2*W;
        this->S = S;
    }
};

long N;
vector<ATTACK> Att[MAX_D+7];

int main( void )
{
    long i,j,p,Icase,k=0;
    long D,nA,W,E,S,Del_D,Del_P,Del_S;

    //freopen("text1.txt","r",stdin );
    freopen("C.in","r",stdin );
    freopen("C.out","w",stdout );

    cin>>Icase;
    while( Icase-- ){
        scanf("%ld",&N );
        for( i=1;i<=N;i++ ){
            scanf("%ld%ld%ld%ld%ld%ld%ld%ld",&D,&nA,&W,&E,&S,&Del_D,&Del_P,&Del_S );
            Att[D].pb( ATTACK( i,W,E,S ) );
            for( j=2;j<=nA;j++ ){
                D += Del_D;
                W += Del_P;
                E += Del_P;
                S += Del_S;
                Att[D].pb( ATTACK( i,W,E,S ) );
            }
        }
        map<long,long> H;
        long Ans = 0;
        for( i=0;i<=MAX_D;i++ ){
            for( j=0;j<Att[i].size();j++ ){//printf("%ld %ld %ld %ld\n",Att[i][j].I,Att[i][j].W,Att[i][j].E,Att[i][j].S );
                for( p=Att[i][j].W;p<=Att[i][j].E;p++ ){
                    H[p] += 0;
                    if( H[p] < Att[i][j].S ){
                        Ans++;
                        break;
                    }
                }
            }
            for( j=0;j<Att[i].size();j++ ){
                for( p=Att[i][j].W;p<=Att[i][j].E;p++ ){
                    H[p] += 0;
                    H[p] = max( H[p],Att[i][j].S );
                }
            }
            Att[i].clear();
        }
        printf("Case #%ld: %ld\n",++k,Ans );



    }

    return 0;
}
