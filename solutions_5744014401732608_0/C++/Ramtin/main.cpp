#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
typedef map<ll,ll>::iterator mapit;
typedef set<int>::iterator setit;

const int maxn = 100 + 4;
const int maxlog = 20;
const int mod = 1e9 + 7;
const int sq = 720;
bool a[maxn][maxn];
vector<int> adj[maxn] , radj[maxn];
int dp[maxn];
int func(int n){
    dp[1] = 1;
    for(int v = 2 ; v <= n ; v ++ ){
        for(auto u : radj[v])
            dp[v] += dp[u];
    }
    return dp[n];
}
int main()
{
    ifstream fin ("B-small-attempt0 (1).in");
    ofstream fout ("myoutput.txt");
    int t;
    fin >> t;
    int an = 0;
    while(t -- ){
        int n , x;
        fin >> n >> x;
        an ++ ;
        int m = n * (n - 1) / 2;
        bool solved = false;
        fout << "Case #" << an << ": " ;
        for(int mask = 0 ; mask < (1 << m) ; mask ++ ){
            int cur = 0;
            for(int i = 1 ; i <= n ; i ++ )
                adj[i].clear() , radj[i].clear() , dp[i] = 0;
            for(int i = 1 ; i <= n ; i ++ ){
                for(int j = 1 ; j <= n ; j ++ ){
                    a[i][j] = false;
                    if(i < j){
                        if(mask & (1 << cur)){
                            a[i][j] = true;
                            adj[i].pb(j);
                            radj[j].pb(i);
                        }
                        cur ++ ;
                    }
                }
            }
            if(func(n) == x){
                solved = true;
                fout << "POSSIBLE" << endl;
                for(int i = 1 ; i <= n ; i ++ ){
                    for(int j = 1 ; j <= n ; j ++)
                        fout << a[i][j];
                    fout << endl;
                }
                break;
            }
        }
        if(!solved)
            fout << "IMPOSSIBLE" << endl;
    }

    return 0;
}






