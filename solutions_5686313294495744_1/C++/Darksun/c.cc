#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 2000;

struct Hungary {
    bool vis[MAXN];
    vector<int> G[MAXN];
    int L, R, mate[MAXN];
    void init(int L, int R) {
        this->L = L; this->R = R;
        for (int i = 0; i < L; ++ i) G[i].clear();
    }
    void addedge(int a, int b) { // left: a, right: b
        G[a].push_back(b); //G[b].push_back(a);
    }
    bool aug(int u) {
        //vis[u] = true;
        for (int i = 0, v; i < (int)G[u].size(); ++ i) {
            if (vis[v = G[u][i]]) continue; vis[v] = true;
            if (mate[v] < 0 || aug(mate[v])) {
                mate[v] = u; //mate[u] = v;
                return true;
            }
        }
        return false;
    }
    int max_mateing() {
        int ret = 0;
        memset(mate, -1, sizeof(mate));
        for (int i = 0; i < L; ++ i) {
            //if (mate[i] != -1) continue;
            memset(vis, 0, sizeof(vis));
            if (aug(i)) ++ ret;
        }
        return ret;
    }
	/*
    vector<int> solve(int arr[]) {
        max_mateing();
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < L; ++ i) {
            if (mate[i] == -1) dfs(i);
        }
        vector<int> ret;
        // Minimum vertex cover
        ret.clear();
        for (int i = 0; i < L; ++ i) 
            if (!vis[i]) ret.push_back(i);
        for (int i = L; i < L + R; ++ i)
            if (vis[i]) ret.push_back(i);
        return ret;
        // Maximum independent set
        ret.clear();
        for (int i = 0; i < L; ++ i) 
            if (vis[i]) ret.push_back(i);
        for (int i = L; i < L + R; ++ i)
            if (!vis[i]) ret.push_back(i);
        return ret;
    }
	*/
};
 
int main(){
	int tt; cin >> tt;
	for (int cas = 1; cas <= tt; cas++){
		cout << "Case #" << cas << ":" << ' ';
		int n; cin >> n;
		map <string, int> mp1, mp2;
		string a[2000], b[2000];
		for (int i = 0; i < n; i++){
			cin >> a[i] >> b[i];
			mp1[a[i]] = 0;
			mp2[b[i]] = 0;
		}
		int cnt = 0;
		for (auto &x : mp1) x.second = cnt ++;
		for (auto &x : mp2) x.second = cnt ++;
		Hungary hg;
		hg.init(mp1.size(), mp2.size());
		for (int i = 0; i < n; i++){
			hg.addedge(mp1[a[i]], mp2[b[i]]);
		}
		int ret = hg.max_mateing();
		//cout << ret << endl;
		cout << n - (mp1.size() + mp2.size() - ret) << endl;
	}
	return 0;
}