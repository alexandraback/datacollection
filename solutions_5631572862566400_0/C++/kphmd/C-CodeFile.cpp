#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <set>
#include <utility>
#include <stack>

#define rep(i,n) for(int i = 0; i < (n); i++)

using namespace std;

void solve();
void runCase();

#define vc vector
#define vi vc<int>
#define vvi vc<vi>

vvi G,K;
vi vis;

int go(int u,int flag = 1) {
    // if(vis[u]==1) return 0;
    // cout << u << endl;
    int n = G.size();
    int ans = 0;
    if(flag&2) {
        for(int v:K[u]) {
            if(vis[v]!=0) {
                ans = max(ans,1);
                continue;
            }
            vis[v] = 1;
            int tmp;
            if(G[u][0]==v) {
                tmp = go(v,3);
            } else {
                tmp = go(v,2);
            }
            if(tmp==0) continue;
            ans = max(ans,tmp+1);
            vis[v] = 0;
        }
    }
    if(flag&1) {
        for(int v:G[u]) {
            if(vis[v]==2) {
                ans = max(ans,1);
                continue;
            }
            if(vis[v]!=0) continue;
            vis[v] = 1;
            int tmp;
            if(K[u][0]==v) {
                tmp = go(v,3);
            } else {
                tmp = go(v,1);
            }
            if(tmp==0) continue;
            ans = max(ans,tmp+1);
            vis[v] = 0;
        }
        // cout << endl;
    }
    if(ans==0) return ans;
    return ans;
}

void runCase()
{
    int n;
    cin >> n;
    G.assign(n,vi{0});
    K.assign(n,vi{0});
    rep(i,n) {
        int u;
        cin >> u; u--;
        G[i][0] = u;
        K[u][0] = i;
        // G[u].push_back(i);
    }
    
    int res = 0;
    rep(i,n) {
        vis.assign(n,0);
        vis[i] = 2;
        int ans = go(i);
        // cout << "ans = " << ans << endl;
        res = max(res,ans);
    }
    cout << res << endl;
}

void solve()
{
	int n;
    cin >> n;
	// scanf("%d",&n);
	// getchar();

	for(int i = 0; i < n; i++) {
        cout << "Case #" << i+1 << ": ";
		// printf("Case #%d: ",i+1);
		runCase();
		//runSample();
	}
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	solve();
	return 0;
}
