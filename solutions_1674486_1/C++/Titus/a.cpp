#include <algorithm>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <iomanip>

using namespace std;

typedef unsigned char byte;
typedef unsigned int uint;

struct node{
    int vis;
    int c;
    vector<int> s;
};

int N;
vector<node> g;

int st[1003000];
int stp=0;


bool dfs(int v){
    stp=0;
    st[stp++] = v;
    while(stp>0){
        stp--;
        int u = st[stp];
        for(uint i=0; i<g[u].s.size(); i++){
            int n = g[u].s[i];
            if(g[n].vis == true) return true;
            else{
                g[n].vis = true;
                st[stp++] = n;
            }
        }
    }
    return false;
}

void solve(){
    cin >> N;
    g.resize(N);
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        g[i].s.resize(a);
        for(int j=0; j<a; j++){
            cin >> g[i].s[j];
            g[i].s[j]--;
        }
    }
    /*
    for(int i=0; i<N; i++){
        cout << i << "; ";
        for(int j=0; j<g[i].s.size(); j++){
            cout << g[i].s[j] << ", ";
        }
        cout << '\n';
    }
    */
    for(int i=0; i<N; i++) g[i].vis = false;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            g[j].vis = false;
        }
        if(dfs(i)){
            cout << "Yes";
            return ;
        }
    }
    cout << "No";
}

int main(){
    // cout << fixed << setprecision(6);
    int T;
    cin >> T;
    for(int t=1; t<=T; t++){
        cout << "Case #" << t << ": ";
        solve();
        cout << '\n';
    }
    return 0;
}
