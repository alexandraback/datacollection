#include <string>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<vector<int> > G;
int f[1024];
int in[1024];
bool dfs(int x, int from){
    if(in[x] == from)return true;
    in[x] = from;
    for(int i = 0; i < G[x].size(); i++)
    {
        if(dfs( G[x][i], from) )return true;
    }
    return false;
}
int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int T, N, n, iii=0, x, j;
    cin >> T;
    int A, B;
    bool ans;
    while( T-- )
    {
        cin >> N;
        G.clear();
        G.assign(N, vector<int>());
        for(int jjj=0;jjj<N;jjj++)
        {
            in[jjj]=-1;
            cin >> n;
            f[ jjj ]=n;
//            cout << n << ' ' << jjj << endl;
            for(int i=0;i<n;i++)
            {
                cin >> x;
                G[jjj].push_back(x - 1);
            }
        }
        ans = false;
        for(int i=0; i<N; i++)
        {
            if(f[i] > 1)
            {
                ans = dfs( i, i );
                if (ans==true) break;
            }
        }
        if(ans) cout << "Case #" << ++iii << ": "  << "Yes" << endl;
        else cout << "Case #" << ++iii << ": "  << "No" << endl;
    }
    return 0;
}
