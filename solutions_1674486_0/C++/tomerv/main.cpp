#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define NMAX 1000

vvi g;
int N;
bool visited[NMAX];

bool dfs(int curr)
{
	visited[curr]++;
	for (vi::iterator it = g[curr].begin(); it != g[curr].end(); ++it) {
		if (visited[*it]) return true;
		if (dfs(*it)) return true;
	}
	return false;
}

bool is_diamond1(int start)
{
	for (int i = 0; i < N; ++i) visited[i] = false;
	return dfs(start);
}



bool is_diamond()
{
	for (int i = 0; i < N; ++i) {
		if (is_diamond1(i)) return true;
	}
	return false;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> N;
		g.clear();
		for (int i = 0; i < N; ++i) {
			int M;
			cin >> M;
			vi parents(M, 0);
			for (int j = 0; j < M; ++j) {
				cin >> parents[j];
				parents[j]--;
			}
			g.push_back(parents);
		}
		cout << "Case #" << t+1 << ": " << ((is_diamond()) ? "Yes" : "No") << endl;
	}

	return 0;
}
