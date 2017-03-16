#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
#include <ctime>
#include <stack>
#include <list>
#include <cassert>
#include <iomanip>
#include <deque>
#include <sstream>
#include <fstream>
typedef pair<int,int> pii;
#define rep(i,j,n) for(i=j;i<n;i++)
#define pb push_back
#define ff first
#define ss second 
#define lli long long int
#define get getchar

inline int scan() {
    int n=0,s=1;
    char p=get();
    if(p=='-')  s=-1;
    while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
    if(p=='-') s=-1,p=get();
    while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
    return n*s;
}

const int maxn = 100009;
int n,m,p;
int match[maxn],dist[maxn];
vector<int> adj[maxn];

bool bfs(){
    
    queue<int> qq;
    int i;
    
    rep(i,1,n+1){
        if(!match[i]){
            qq.push(i);
            dist[i] = 1;
        }
        else
            dist[i] = maxn;
    }
    dist[0] = maxn;
    
    while(!qq.empty()){
        
        int cur = qq.front();
        qq.pop();
        
        rep(i,0,adj[cur].size()){
            
            int nex = match[adj[cur][i]];
            if(dist[nex]==maxn){
                dist[nex] = dist[cur]+1;
                qq.push(nex);
            }
        }
        
    }
    
    return dist[0]!=maxn;
    
}

bool dfs(int node){
    
    if(node!=0){
        
        for(int i=0; i<adj[node].size(); i++){
            
            int v = adj[node][i];
            if(dist[match[v]] - dist[node] != 1 )   continue;
            if(dfs(match[v])){
                match[node] = v;
                match[v] = node;
                return true;
            }
            
        }
        
        dist[node] = maxn;
        
        return false;
    }
    
    return true;
}

int hopcraft_karp(){
    
    int i,matching=0;

    while(bfs()){
        rep(i,1,n+1){
            if(!match[i])
            if(dfs(i))
                matching++;
        }
    }
    
    return matching;
}


int main() {
        
    ios::sync_with_stdio(false);
    
    freopen ("inp.txt","r",stdin);
    freopen ("out.txt","w",stdout);
    int t;
    cin >> t;
    int ca = 0;
    while (t--) {
        ca++;
        cout << "Case #" << ca << ": ";
        map<string,int> gg1,gg2;
        cin >> n;
        memset(match,0,sizeof(match));
        memset(dist,0,sizeof(dist));
        for (int i = 0; i < maxn; i++) adj[i].clear();

        string a,b;
        int c1,c2;
        c1 = c2 = 1;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            if (gg1[a] == 0) {
                gg1[a] = c1;
                c1++;
            }
            if (gg2[b] == 0) {
                gg2[b] = c2;
                c2++;
            }
            adj[i+1].pb(gg1[a]);
            adj[i+1].pb(gg2[b]);
        }
        m = c1 + c2;
        p = 2*n;
        cout << n - hopcraft_karp() << endl;
    }
    
    
    return 0;
        
}