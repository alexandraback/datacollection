#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int N, M;
string zip[50], best;
bool out[50][50], ret[50][50];
int vis[50];


inline bool lesss( const string &a, const string &b ){
    if( b == "" ) return true;
    if( a.size() != b.size() ) return a.size()<b.size(); 
    for(int i=0, I=a.size(); i<I; ++i){
        if( a[i] != b[i] ){
            return a[i] < b[i];
        }
    }
    return true;
}

void dfs( int cur, string zsf, int added ){
    
    if( added == N ){
        //cout<<zsf<<endl;
        if( lesss(zsf,best) ) best = zsf;
        return;
    }

    for(int i=0; i<N; ++i){
        if( out[cur][i] && !vis[i] ){
            vis[i] = 1; ret[i][cur]=1;
            dfs( i, zsf + zip[i], added + 1 );
            vis[i] = 0; ret[i][cur]=0;
        }
        if( ret[cur][i] && vis[i]<10 ){
            ++vis[i];
            dfs( i, zsf, added );
            --vis[i];
        }
    }

    return;
}
        

int main(){

    int TC;
    cin>>TC;
    for(int tc=1; tc<=TC; ++tc){

        best = "";
        memset(out,0,sizeof(out));
        memset(ret,0,sizeof(ret));
        memset(vis,0,sizeof(vis));

        cin>>N>>M;

        for(int i=0; i<N; ++i){
            cin>>zip[i];
        }

        for(int i=0; i<M; ++i){
            int u, v;
            cin>>u>>v; --u, --v;
            out[u][v] = 1;
            out[v][u] = 1;
        }

        for(int i=0; i<N; ++i){
            vis[i] = 1;
            dfs(i, zip[i], 1);
            vis[i] = 0;
        }

        cout<<"Case #"<<tc<<": "<<best<<endl;

    }
    return 0;
}

