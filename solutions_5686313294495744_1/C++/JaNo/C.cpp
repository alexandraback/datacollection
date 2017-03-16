//Fruit of Light
//FoL CC
//Apple Strawberry

#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<cstring>

using namespace std;

#define For(i, n) for(int i = 0; i<(n); ++i)
#define INF 1023456789
#define eps 1e-9

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<string,int> id;
int get_id(string S) {
    if (!id.count(S)) id[S] = id.size()+1;
    return id[S];
}

vi E[2047];
vi R[2047];
vi C[2047];
int vis[2047];
int n;

int find_path(int v) {
    if (v == 1) return 1;
    if (vis[v]) return 0;
    vis[v] = 1;
    For(i, E[v].size()) {
        int u = E[v][i];
        if (C[v][i] > 0 && find_path(u)) {
            C[u][R[v][i]]++;
            C[v][i]--;
            return 1;
        }
    }
    return 0;
}

int max_flow() {
    int f = 0;
    For(i, n) vis[i] = 0; 
    while (find_path(0)) {
        f++;   
        For(i, n) vis[i] = 0; 
    }
    return f;
}

int create_edge(int a, int b) {
    R[a].push_back(E[b].size());
    R[b].push_back(E[a].size());
    E[a].push_back(b);
    E[b].push_back(a);
    C[a].push_back(1);
    C[b].push_back(0);
}

int extra() {
    id.clear();
    For(i, 2047) E[i].clear();
    For(i, 2047) C[i].clear();
    For(i, 2047) R[i].clear();
    set<int> LP, RP;
    string A, B; 
    int m;

    cin >> m;
    For(i, m) {
        cin >> A >> B;
        int a = get_id("l"+A);
        int b = get_id("r"+B);
        create_edge(a,b);
        LP.insert(a);
        RP.insert(b);
    }
    n = id.size() + 2;
    for(auto a : LP) create_edge(0,a);
    for(auto b : RP) create_edge(b,1);
    cout << m - int(id.size()) + max_flow() << endl;
}

int main(){
    int T;
    scanf("%d",&T);
    For(i,T){
        printf("Case #%d: ",i+1);
        extra();
    }
}
