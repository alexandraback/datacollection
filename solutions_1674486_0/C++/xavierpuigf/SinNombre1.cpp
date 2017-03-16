#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
vector <vector <int> > v;
vector <bool> vis;
bool dfs (int i){
     if (vis[i]) return true;
     vis[i] = true;
     bool trob = false;
     for (int j = 0; j < v[i].size() and not trob; j++){
         trob = dfs(v[i][j]);
     }
     return trob;
}
int main (){
    ifstream fin ("A-small.in");
    ofstream fout ("A-small.out");
    int T;
    fin >>T;
    for (int i = 1; i <= T; i++){
        int n;
        fin >>n;
        v.clear();
        vis.clear();
        v = vector <vector <int> > (n);
        vis = vector <bool> (n, false);
        for (int k = 0; k< n; k++){
            int M;
            fin >>M;
            while (M--){
            int b;
            fin >>b;
            b--;
            v[k].push_back(b);
            }
        }
    
    bool in = false;
    for (int it = 0; it < n and not in; it++){
         vis = vector <bool> (n, false);
         in = dfs(it);
    }
    fout <<"Case #"<<i<<": ";
    if (in) fout <<"Yes"<<endl;
    else fout <<"No"<<endl;
    }
}
