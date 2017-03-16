#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXNN = 10010;

int v[MAXNN];
pair<int, int> a[MAXNN];
long long E, R;
int N;

const int MAXN=10050,MAXM=41000;
struct mcflow{
       int N,M,S,T;
       int g[ MAXN ],next[ MAXM ],node[ MAXM ], c[ MAXM ],size;
       long long dis[ MAXN];
       int pre[ MAXN ];
       long long oo;
       long long d[ MAXN ];
       bool inqueue[ MAXN ];
       mcflow(){
            oo=1000000000LL * 1000000000LL + 5;
       }
       #define CL(x) memset( x, 0 , sizeof( x ) );
       void init(){
            CL( g );  CL( next );  CL( node ); CL( dis );
            size=1;
            T=S=N=M=0;
       }
       
       void make_edge( int a ,int b, int cc ,long long d ){
            next[ ++size ]=g[ a ];
            g[ a ]=size;
            node[ size ]=b;
            c[ size ]=cc;
            dis[ size ]=d;
       }
       void insert( int a, int b, int cc, long long d ){
            make_edge( a , b , cc , d );
            make_edge( b , a , 0 , -d );
       } 
       bool spfa(){
            CL( inqueue );
            for( int i=1 ; i<=T;  i++)
              d[ i ]=-oo;
            queue<int> Q;
            Q.push( S );
            inqueue[ S ]=1;
            d[ S ]=0;
            
            while( !Q.empty() ){
                   int m=Q.front();
                   inqueue[ m ]=0;
                //   cout << m <<" " <<d[ m ] << endl;
                   Q.pop();
                   int p=g[ m ];
                   while( p ){
                          if( c[ p ]>0 && d[ node[ p ] ]<d[ m ]+dis[ p ] ){
                              d[ node[ p ] ]=d[ m ]+dis[ p ];
                              pre[ node[ p ] ]=p;
                              if( !inqueue[ node[ p ] ] ){
                                  inqueue[ node[ p ] ]=1;
                                  Q.push( node[ p ] );
                              }
                          }
                          p=next[ p ];
                   }
            }
            return d[ T ]>-oo;
       }      
       void min_cost_flow( int &Flow , long long &fee ){
            Flow=fee=0;
            while( spfa() ){
                   int u=T , tmp=1000000000;
                   while( u!=S ){
                          tmp=min( c[ pre[ u ] ] , tmp );
                          u=node[ pre[ u ]^1 ];
                   }
                   fee+=d[ T ] * tmp;
                   u=T;
                   while( u!=S ){
                          c[ pre[ u ]^1 ]+=tmp;
                          c[ pre[ u ] ]-=tmp;
                          u=node[ pre[ u ]^1 ];
                   }
                   Flow+=tmp;
            }
       }
       long long mincost(){
           long long ret=0;
	   int tmp;
           min_cost_flow( tmp , ret );
           return ret;
       }
}G;

int main()
{
	int cases;
	cin >> cases;
	for (int tcase = 1; tcase <= cases; ++tcase) {
		cin >> E >> R;
		cin >> N;
		R = min(R, E);
		for (int i = 0; i < N; ++i) {
			cin >> v[i];
			a[i] = make_pair(v[i], i);
		}

		cout << "Case #" << tcase << ": ";
		G.init();
		G.S = 1; G.T = N + 2;
		for (int i = 0; i < N; ++i) {
			if (i == 0) G.insert(G.S, i + 2, E, 0);
			else G.insert(G.S, i + 2, R, 0);
			if (i + 1 < N) G.insert(i + 2, i + 3, E - R, 0);
			G.insert(i + 2, G.T, E, v[i]);
		}
		cout << G.mincost() << endl;
	}
	return 0;
}
