#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>

const int MAXN = 60;

using namespace std;

struct point{
       int x,id;
};

int N,M;
int thesi[MAXN], vis[MAXN];
point zip[MAXN];
vector<int>res;
vector<set<int> >graph(MAXN);

bool cmp(point i1,point i2){
     return i1.x < i2.x;
}

void dfs(int start){
     
     vis[start] = 1;
     res.push_back( zip[start].x );
     
     set<int>::iterator it;
     for( it=graph[start].begin();it!=graph[start].end();++it)
          if( !vis[*it] )
              dfs( *it );

}

int main(){
    freopen( "salesman.in", "r", stdin );
    freopen( "salesman.out", "w", stdout );
    
    int T; cin>>T;
    for(int t=1;t<=T;t++){
            graph.clear();
            graph.resize( MAXN );
            memset( vis, 0, sizeof vis );
            res.clear();
            
            cin>>N>>M;
            for(int i=1;i<=N;i++){
                    cin>>zip[i].x;
                    zip[i].id = i;
                    }
            
            sort( zip + 1, zip + N + 1, cmp );
            for(int i=1;i<=N;i++)
                    thesi[ zip[i].id ] = i;
            
            for(int i=0;i<M;i++){
                    int x,y; cin>>x>>y;
                    graph[ thesi[x] ].insert( thesi[y] );
                    graph[ thesi[y] ].insert( thesi[x] );
                    }
            
            dfs( 1 );
            
            cout<<"Case #"<<t<<": ";
            for(int i=0;i<res.size();i++)
                    cout<<res[i];cout<<'\n';
            
            }
    
    return 0;
}
