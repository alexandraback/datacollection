#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>
using namespace std;
typedef long long ll;

const int N = 6;

bool fl; int fx, fy;
char a[N][N];
char p[N][N];
int n,m;
bool u[N*N], w[N][N];

int cnt(int x, int y){
    int res = 0;
    for(int dx=-1; dx<2; ++dx)
    for(int dy=-1; dy<2; ++dy) if(dx||dy){
        int i=x+dx, j=y+dy;
        if(i>=0 && j>=0 && i<n && j<m && p[i][j]=='*') ++res; 
    }
    return res;
}

void dfs(int x, int y){
    if(x<0 || y<0 || x>=n || y>=m) return ;
    if(w[x][y]) return  ;
    w[x][y] = 1;
    int c = cnt(x,y);
    if(!c){            
        for(int dx=-1; dx<2; ++dx)
        for(int dy=-1; dy<2; ++dy) if(dx||dy) dfs(x+dx, y+dy);
    }
}

bool win(int x, int y){
    memset(w,0,sizeof w);
    dfs(x,y);
    for(int i=0;i<n;++i)
    for(int j=0;j<m;++j) if(p[i][j]=='.' && !w[i][j]) return false;
    return true;
}

void go(int i, int k, int s){
    if(i+k>s) return ;
    if(i==s){
        for(int x=0,j=0; x<n;++x)
        for(int y=0; y<m;++y,++j){
            p[x][y] = ".*"[u[j]];
        }
        
        for(int x=0;x<n;++x)
        for(int y=0;y<m;++y) if(p[x][y]=='.' && win(x,y)){
            fl = true;
            fx = x; fy = y;
            memcpy(a, p, sizeof a);
            return ;
        }
        
        return ;
    }
    
    go(i+1, k, s);
    if(fl) return ;
    if(k){
        u[i] = 1;
        go(i+1, k-1, s);
        u[i] = 0;
        if(fl) return ;
    }
}

void solve(int test){
    
    int K;
    cin>>n>>m>>K;
    
    fl=false;
    memset(p,0,sizeof p);
    go(0, K, n*m);
    
    
    cout<<"Case #"<<test<<":";
    
    if(!fl) cout<<endl<<"Impossible"; else{
        a[fx][fy] = 'c';
        for(int i=0;i<n;++i) cout<<endl<<a[i];
    }
    
    cout<<endl;
    
}

int main(){
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    
    int tn;
    cin>>tn;
    for(int ti=1;ti<=tn;++ti){
        cerr<<ti<<"..."<<endl;
        solve(ti);
        cerr<<ti<<" ok."<<endl;
    }
    
    
    return 0;
}

