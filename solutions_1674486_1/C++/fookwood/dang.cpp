#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

int N,T,M;
int from,to;
class Node{
public:
    int to;
    Node *next;
    Node( int to = 0, Node *p = NULL ):
        to(to),next(p){}
    void add( int tt, Node *&b ){
        to = tt; next = b; b = this;
    }
};

template< int Vsize, int Esize >
class Graph{
public:
    Node *biao[ Vsize ];
    Node A[ Esize ];
    int cnt[ Vsize ];
    int in[ Vsize ];
    int countt;
    void init( void ){
        countt = 0;
        for( int i = 0; i < Vsize; i++ ){
            biao[i] = NULL;
            in[i] = 0;
        }
    }
    void add( int from, int to ){
        A[ countt++ ].add( to, biao[from] );
        in[ to ]++;
    }
    
    void clr( void) { memset( cnt, 0, sizeof(cnt) ); }
    
    bool dfs( int from ){
        cnt[ from ]++;
        if( cnt[ from ] > 1 ) return true;
        for( Node *p = biao[from]; p != NULL; p = p->next )
            if( dfs(p->to) ) return true;
        return false;
    }
    
    void print(void){// for debug
        for( int i = 1; i <= N; i++ ){
            cout << i << " : " ;
            for( Node *p = biao[i]; p != NULL; p =p->next )
                cout << p->to << ' ';
            cout << endl;
        }
    }
};


Graph<2001, 2000001> g;
int main(void){
	
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	
	scanf("%d",&T);
    for( int cc = 1; cc <= T; cc++ ){
        g.init();
        scanf("%d",&N);
        for( from = 1; from <= N; from++ ){
            scanf("%d",&M);
            while( M-- ){
                scanf("%d",&to);
                g.add( from, to );
            }
        }
        int yes = false;
        for( from = 1; from <= N; from ++ ){
            if( g.in[from] ) continue;
            g.clr();
            if( g.dfs(from) ){
                yes = true; 
                break;
            }
        }
            
        
        printf("Case #%d: %s\n",cc,yes?"Yes":"No"); 
    }
	
	return 0;
}
