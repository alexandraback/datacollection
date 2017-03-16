#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <utility>
#include <complex>

using namespace std;
typedef long long ll;
typedef double ld;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<ll> pt;

vector<int> adj_list[1<<12];
int bff[1<<12];
bool visited[1<<12];
int temp_cnt[1<<12];

int dfs_small(int v, int root1, int root2){
	visited[v] = true;
	int best = 0;
	for (int i = 0; i < adj_list[v].size(); i++){
		int u = adj_list[v][i];
		if (u == root1 || u == root2) continue;
		//cout << "dfs_small from v = " << v << " to u = " << u << endl;
		best = max(best,dfs_small(u,root1,root2)+1);
	}
	return best;
}

void dfs_large(int v, int root){
	visited[v] = true;
	for (int i = 0; i < adj_list[v].size(); i++){
		int u = adj_list[v][i];
		if (u == root) continue;
		//cout << "dfs_large from v = " << v << " to u = " << u << endl;
		dfs_large(u,root);
	}
}

int main(){
	int tt; cin >> tt;
	for (int zz = 1; zz <= tt; zz++){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){
			adj_list[i].clear();
		}
		memset(visited,false,sizeof(visited));
		for (int i = 1; i <= n; i++){
			cin >> bff[i];
			adj_list[bff[i]].push_back(i);
		}
		int path_cnt = 0, ring_cnt = 0;
		
		int comp_cnt = 0;
		
		for (int i = 1; i <= n; i++){
			if (visited[i]) continue;
			int cnt = 0;
			int curr = i;
			while (!visited[curr]){
				visited[curr] = true;
				temp_cnt[curr] = cnt;
				curr = bff[curr];
				cnt++;
			}
			cnt -= temp_cnt[curr];
			//cout << "i = " << i << ", curr = " << curr << ", cnt = " << cnt << endl;
			//cout << "bff[curr] = " << bff[curr] << endl;
			ring_cnt = max(ring_cnt,cnt);
			if (cnt == 2){
				int t1 = dfs_small(curr,curr,bff[curr]);
				int t2 = dfs_small(bff[curr],bff[curr],curr);
				//cout << "t1 = " << t1 << ", t2 = " << t2 << endl;
				//int best = dfs_small(curr,curr,bff[curr]) + dfs_small(bff[curr],bff[curr],curr) + 2;
				int best = t1+t2+2;
				path_cnt += best;
			}
			else{
				dfs_large(curr,curr);
			}
		}
		cout << "Case #" << zz << ": " << max(path_cnt,ring_cnt) << endl;
	}
	
	return 0;
}
