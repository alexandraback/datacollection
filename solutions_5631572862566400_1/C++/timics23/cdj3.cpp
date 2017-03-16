#include<stdio.h>
#include<iostream>
#include<map>
#include<vector>
#define pb push_back
using namespace std;
string S,s;
int N,T;
int viz[1010],viz2[2020];
vector<int> g[1010];
int nr = 0;
int best;
int root;
int h[1010];
int circ[4000];
int bst[5050];
void dfs(int x) {
    viz[x] = 1;
    ++nr;
    if(viz[h[x]] == 1 && h[x] == root) {
        best = max(best,nr);
    } else if(viz[h[x]] == 0) dfs(h[x]);
    --nr;
}

void dfs(int x,int y) {
    //cout << x << "!";
    viz2[x] = 1;
    bst[x]=1;
    for(auto nx : g[x]) {
        if(y != nx && viz2[nx] == 0) {
            dfs(nx,x);
            bst[x] = max(bst[x],1 + bst[nx]);
        }
    }
}

int main() {
    freopen("input.in","r",stdin);
    freopen("output2.out","w",stdout);
    cin>>T;
    for(int t=1;t<=T;++t) {
        cin >> N;
        for(int i=1;i<=N;++i){
            g[i].clear();
            viz[i]=viz2[i]=0;
            bst[i]=0;
        }
        best = 0;
        for(int i=1;i<=N;++i) {
            int x;
            cin>>x;
            h[i] = x;
            g[x].pb(i);
        }
        vector<int> v;
    best = 0;
    int val = 0;
    for(int i=1;i<=N;++i) {
       root=i;
       nr=0;
       dfs(i);
       for(int j=0;j<=N;++j) viz[j]=0;
    }
    
    //cout << best << endl;
    for(int i=1;i<=N;++i){
        if(i == h[h[i]] && i > h[i]) {
            dfs(i,h[i]);
            dfs(h[i],i);
            
            val += bst[i] + bst[h[i]];
       //     cout << bst[i] << " " << bst[h[i]] << endl;
        }
    }
    best = max(val, best);
        
        
        cout<<"Case #"<<t<<": ";
        cout<<best;
        cout << endl;
        
    }
}
