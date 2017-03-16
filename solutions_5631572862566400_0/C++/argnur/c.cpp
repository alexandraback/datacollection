#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector< vector<int> > vvi;

vector<bool> visited(1001, false);

bool pairCompare(const pair<int, int> firstElem, const pair<int, int> secondElem) {
  return (firstElem.second > secondElem.second);
}

int dfs(int u, int f, vvi g) {
	visited[u] = true;
	int longest = 0;
	for (auto fan : g[u])
		if (fan!=f && !visited[fan])
			longest = max(longest, dfs(fan, u, g));
	return longest + 1;
}

int main() {
	int t, test, i, n;
	cin >> t;
	for (test=1;test<=t;test++) {
		cin >> n;
		int f[n+1];
		vvi g(n+1);
		for (i=1;i<=n;i++) {
			cin >> f[i];
			g[f[i]].push_back(i);
		}
		vector<bool> paired(n+1, false);
		vector< pair<int, int> > loops;
		for (i=1;i<=n;i++) {
			if (!paired[i] && i == f[f[i]]) {
				loops.push_back(make_pair(i, f[i]));
				paired[i] = paired[f[i]] = true;
			}
		}
		int result;
		int loop_result = 0;
		int temp;
		vector< pair<int,int> > legs;

		for (i=0;i<loops.size();i++) {
			fill(visited.begin(), visited.end(), false);
			temp = dfs(loops[i].first, loops[i].second, g);
			legs.push_back(make_pair(loops[i].first, temp));
			temp = dfs(loops[i].second, loops[i].first, g);
			legs.push_back(make_pair(loops[i].second, temp));
		}

		sort(legs.begin(), legs.end(), pairCompare);

		if (loops.size()>0) {
			loop_result = legs[0].second + legs[1].second;
			if (loops.size()>1 && legs[0].first != legs[0].second)
				loop_result += (loops.size()-2)*2 + 2;
			else
				loop_result += (loops.size()-1)*2;
		}

		int non_loop_result = 0;

		for (i=1;i<=n;i++) {
			vector<bool> v(n+1, false);
			int count = 0, prev = 0;
			int cur = i;
			while (!v[cur]){
				v[cur] = true;
				prev = cur;
				cur = f[cur];
				count ++;
			}
			if (cur == i)
				non_loop_result = max(count, non_loop_result);
		}

		
		result = max(loop_result, non_loop_result);

		cout << "Case #" << test << ": " << result << endl;
	}
	return 0;
}