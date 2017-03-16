#include <stdio.h>
#include <map>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
namespace matching {
	typedef int val_t;
	const int SIZE = 1000;
	int v1, v2;
	vector<int> graph[SIZE];
	int mx[SIZE], my[SIZE];
	int total_matching;
	int dist[SIZE];
	int inf_dist;
	bool bfs() {
		int x, y;
		queue<int> q;
		for (x = 0; x < v1; x++) {
			if (mx[x] == -1) {
				dist[x] = 0;
				q.push(x);
			}
			else
				dist[x] = -1;
		}
		bool flg = false;
		while (!q.empty()) {
			x = q.front();
			q.pop();
			for (int i = 0; i < graph[x].size(); i++) {
				y = graph[x][i];
				if (my[y] == -1) {
					inf_dist = dist[x] + 1;
					flg = true;
				}
				else if (dist[my[y]] == -1) {
					dist[my[y]] = dist[x] + 1;
					q.push(my[y]);
				}
			}
		}
		return flg;
	}
	bool dfs(int x) {
		if (x == -1) return true;
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			int tmp = (my[y] == -1) ? inf_dist : dist[my[y]];
			if (tmp == dist[x] + 1 && dfs(my[y])) {
				mx[x] = y;
				my[y] = x;
				return true;
			}
		}
		dist[x] = -1;
		return false;
	}
	int hopcroft() {
		memset(mx, -1, sizeof(mx));
		memset(my, -1, sizeof(my));
		total_matching = 0;
		while (bfs()) {
			for (int x = 0; x < v1; x++)
				if (mx[x] == -1 && dfs(x))
					total_matching++;
		}
		return total_matching;
	}
} // namespace matching

pair<int, int> su[1001];
map<string, int> A, B;
int nA, nB;
int get_A(string S){
	auto it = A.find(S);
	if (it != A.end()){
		return it->second;
	}
	A[S] = nA++;
	return nA - 1;
}
int get_B(string S){
	auto it = B.find(S);
	if (it != B.end()){
		return it->second;
	}
	B[S] = nB++;
	return nB - 1;
}
int main(){
	int testt;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &testt);
	for (int test = 1; test <= testt; test++){
		int n;
		char mun_A[25] = { 0, }, mun_B[25] = { 0, };
		scanf("%d", &n);
		A.clear();
		B.clear();
		nA = 0; nB = 0;
		for (int i = 0; i < n; i++){
			scanf("%s %s", mun_A, mun_B);
			su[i].first = get_A(string(mun_A));
			su[i].second = get_B(string(mun_B));
		}

		matching::v1 = nA;
		matching::v2 = nB;

		for (int i = 0; i < 1000;i++)
			matching::graph[i].clear();
		for (int i = 0; i < n; i++){
			matching::graph[su[i].first].push_back(su[i].second);
		}

		int ans = n-(nA + nB - matching::hopcroft());
		printf("Case #%d: %d\n", test, ans);
	}
	return 0;
}
