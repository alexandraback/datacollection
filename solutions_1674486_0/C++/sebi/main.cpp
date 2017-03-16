#include <iostream>
#include <cstring>
#include <fstream>
#include <list>

using namespace std;

list<int> G[1024];
int viz[1024];

bool dfs(int x){
    if(viz[x])
        return true;
    viz[x] = 1;
    for(list<int>::iterator it = G[x].begin(); it != G[x].end(); it++){
        bool b = dfs(*it);
        if(b)
            return b;
    }
    return false;
}

int main()
{
    ifstream f("a.in");
    ofstream g("a.out");
    int T, n, m;
    f >> T;
    for(int t = 1; t <= T; ++t){

        f >> n;
        for(int i = 1; i <= n; ++i){
            f >> m;
            G[i].clear();
            for(int j = 0; j < m; ++j){
                int x;
                f >> x;
                G[i].push_back(x);
            }
        }
        g << "Case #" << t << ": ";
        int i;
        for(i = 1; i <= n; ++i){
            memset(viz, 0, 1024 * sizeof(int));
            if(dfs(i)){
                g << "Yes\n";
                break;
            }
        }
        if(i > n)
            g << "No\n";
    }
    f.close();
    g.close();
    return 0;
}
