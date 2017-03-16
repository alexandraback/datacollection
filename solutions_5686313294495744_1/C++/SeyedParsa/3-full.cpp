//be naame khodaa

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cassert>
#include <iomanip>
typedef long long ll;
#define X first
#define Y second
const int maxn = 1005;

using namespace std;
typedef pair <int, int> pii;
bool mark[maxn];
int match[maxn];
vector <int> v[maxn];

bool dfs(int cur){
	if (mark[cur]) return false;
	mark[cur] = true;
	for (int u : v[cur])
		if (match[u] == -1 || dfs(match[u]))
			return (match[u] = cur), true;
	return false;
}

int min_edge(int n, int m){
	int ans = 0;
	fill(match, match + m, -1);
	for (int i = 0; i < n; i++){
		fill(mark, mark + n, false);
		if (dfs(i)) ans++;
	}
	fill(mark, mark + n, false);
	for (int i = 0; i < m; i++){
		if (match[i] == -1) ans++;
		else mark[match[i]] = true;
	}
	for (int i = 0; i < n; i++)
		if (!mark[i])
			ans++;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int it = 1; it <= t; it++){
		int N;
		cin >> N;
		map <string, int> mp[2];
		string s0, s1;
		int n = 0, m = 0;
		for (int i = 0; i < N; i++) v[i].clear();
		for (int i = 0; i < N; i++){
			cin >> s0 >> s1;
			if (mp[0].find(s0) == mp[0].end()) mp[0][s0] = n++;
			if (mp[1].find(s1) == mp[1].end()) mp[1][s1] = m++;
			v[mp[0][s0]].push_back(mp[1][s1]);
		}
		cout << "Case #" << it << ": " << N-min_edge(n, m) << '\n';
	}
	return 0;
}
