#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

vector<int> G[100];
int ZIP[100];
bool used[100], vis[100];
int N, M;

int sta[100];
int stix = 0;

void dfs(int v) {
    vis[v] = true;
    for (int i=0; i<int(G[v].size()); i++)
        if (!vis[G[v][i]])
            dfs(G[v][i]);
}

void take(int v) {
    cout<<ZIP[v];
    used[v] = true;
}


bool canWeOmit(int cnt) {
    copy(used, used+N, vis);
//     for (int i=stix-1; i>=stix-cnt; i--)
//         vis[i] = true;
    for (int i=stix-cnt-1; i>=0; i--)
//         if (vis[sta[i]])
            dfs(sta[i]);
//     dfs(sta[stix-cnt-1]);
    return find(vis, vis+N, false) == vis+N;
}

void findStart() {
    int x = min_element(ZIP, ZIP+N) - ZIP;
    take(x);
    sta[0] = x;
    stix = 1;
}


void run() {
    findStart();
    
    for (int nn=1; nn<N; nn++) {
        int bestChoiceVal = 999999;
        int bestChoice = -1;
        int bestStix = -1;
        
        for (int d=0; d<stix; d++) {
            if (!canWeOmit(d)) {
//                 cout<<"we cant "<<d<<endl;
                break; // for d==0 this must return true as graph is connected
            }
                
            // traverse neigbours of sta[stix-d-1]
            int v = sta[stix-d-1];
            for (int i=0; i<int(G[v].size()); i++) {
                int u = G[v][i];
                if (used[u])
                    continue;
                if (ZIP[u] > bestChoiceVal)
                    continue;
                bestChoice = u;
                bestChoiceVal = ZIP[u];
                bestStix = stix-d;
            }
        }
        
//         if (bestStix==-1) cout<<"\nDUPA\n";
        
        take(bestChoice);
        stix = bestStix;
        sta[stix++] = bestChoice;
    }
}


int main() {
       
    int T; cin>>T;
    for (int t=1; t<=T; t++) {
        cout<<"Case #"<<t<<": ";
        
        cin>>N>>M;
        fill(G, G+N, vector<int>());
        fill(used, used+N, false);
        
        for (int i=0; i<N; i++)
            cin>>ZIP[i];
        
        for (int i=0; i<M; i++) {
            int a, b; cin>>a>>b; a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        run();
        
        cout<<endl;
    }

    return 0;
}
