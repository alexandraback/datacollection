#include <iostream>
#include <vector> 
using namespace std;
 
int n, t, tmp, hoge[1002];
vector<int> gf[1002];

void dfs(int nod, int fin){
    hoge[nod] = 1;
    for(int i=0; i<gf[nod].size(); i++){
	if (gf[nod][i] == fin) ++tmp;
        if (tmp >= 2) return;
        if (hoge[gf[nod][i]] == 0){
            dfs(gf[nod][i], fin);
        }
    }
}
 
int main(){ 
    cin >> t;
    for(int w = 1; w <= t; w++){
        cin >> n;
        cout << "Case #" << w << ": ";
        for(int i = 0; i <= n; i++) gf[i].clear();
        for(int i = 1; i <= n; i++){
            int m, k;
            cin >> m;
            for(int j = 1; j <= m; j++){
                cin >> k;
                gf[i].push_back(k);
            }
        }
        int ans = 1;
        for(int i = 1; i <= n && ans; i++){
            for(int j = 1; j <= n && ans; j++){
                for(int k = 0; k < 1002; k++) hoge[k] = 0;
                tmp = 0;
                dfs(i,j);
                if (tmp >= 2) cout << "Yes" << endl, ans = 0;
            }
        }
        if (ans == 1) cout << "No" << endl;
    }
    return 0;
}
