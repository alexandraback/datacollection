#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool possible(int N, const vector<vector<bool> >& mat, vector<bool> visited, vector<int> stack) {
	while (!stack.empty()) {
		int a = stack.back();
		stack.pop_back();
		for (int i = 0; i < N; ++i) {
			if (mat[a][i] && !visited[i]) {
				visited[i] = true;
				stack.push_back(i);
			}
		}
	}
	for (bool b : visited) {
		if (!b) return false;
	}
	return true;
}

void solve() {
	int N, M;
	cin >> N >> M;
	vector<int> num(N);
	for (int& v : num)
		cin >> v;
	vector<vector<bool> > mat(N, vector<bool>(N, false));
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		mat[a][b] = mat[b][a] = true;
	}

	vector<int> ord(N);
	{
		vector<pair<int, int> > v(N);
		for (int i = 0; i < N; ++i)
			v[i] = make_pair(num[i], i);
		sort(v.begin(), v.end());
		for (int i = 0; i < N; ++i)
			ord[i] = v[i].second;
	}

	vector<bool> visited(N, false);
	vector<int> stack;

	int startInd = min_element(num.begin(), num.end()) - num.begin();
	cout << num[startInd] << flush;
	visited[startInd] = true;
	stack.push_back(startInd);

	int nleft = N-1;
	while (nleft > 0) {
		for (int i = 0; i < N; ++i) {
			int a = ord[i];
			if (visited[a]) continue;
			int b = stack.size();
			while (b --> 0) {
				int s = stack[b];
				if (mat[s][a]) break;
			}
			if (b == -1) continue;
			vector<int> stack2(stack.begin(), stack.begin() + b + 1);
			vector<bool> visited2 = visited;
			stack2.push_back(a);
			visited2[a] = true;
			if (possible(N, mat, visited2, stack2)) {
				--nleft;
				cout << num[a] << flush;
				stack.swap(stack2);
				visited.swap(visited2);
				break;
			}
		}
	}
	cout << endl;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
}
