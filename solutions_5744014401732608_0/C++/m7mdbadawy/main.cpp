#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int graph[10][10];
int b,m;
int solve2()
{
    vector<int> dp(b);
    dp[0] = 1;
    int u;
    for(int i=0;i<b;i++){
        u = i;
        for(int v = 0; v<b;v++){
            if (graph[u][v]) dp[v] += dp[u];
        }
    }
    return dp[b-1];
}

bool solve(int i,int j){
    if (i==b-1){
        if (solve2()==m) return true;
        else return false;
    }
    int i1=i,j1=j+1;
    if (j1 == b){
        j1 = 0;
        i1++;
    }
    if (i >= j){
        return solve(i1,j1);
    }
    else{
        graph[i][j] = 0;
        if (solve(i1,j1)) return true;
        else{
            graph[i][j] = 1;
            if (solve(i1,j1)) return true;
            return false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int t,n;
    cin >> t;
    for(int cn=1;cn<=t;cn++){
        cin >> b >> m;
        cout << "Case #" << cn << ": ";
        bool can = solve(0,0);
        if (!can) cout << "IMPOSSIBLE\n";
        else{
            cout << "POSSIBLE\n";
            for(int i=0;i<b;i++){
                for(int j=0;j<b;j++){
                    cout << graph[i][j];
                }
                cout << '\n';
            }
        }
    }
    return 0;
}
