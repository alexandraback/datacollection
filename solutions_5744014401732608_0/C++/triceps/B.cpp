#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

typedef long long ll;

using namespace std;

map<int, vector<vector<int>>> A[10];

int SolveR(int b, int c, int g[10][10], int r)
{
	if (r > b) {
		return -1;
	}

	if (c == b - 1) {
		return 1;
	}

	int ret = 0;
	for (int i = 0; i < b; i++) {
		if (g[c][i]) {
			auto ret0 = SolveR(b, i, g, r+1);
			if (ret0 < 0) return -1;
			ret += ret0;
		}
	}
	return ret;
}

void Solve(int b, int g[10][10])
{
	vector<vector<int>> v(b);
	for (int i = 0; i < b; i++){
		v[i].resize(b);
		for (int j = 0; j < b; j++) {
			v[i][j] = g[i][j];
		}
	}
	auto ans = SolveR(b, 0, g, 0);
	if (ans>0) {
		A[b][ans] = v;
	}
}

void MakeGraphR(int b, vector<pair<int, int>>& v, size_t e, int g[10][10])
{
	if (v.size() == e) {
		Solve(b, g);
		return;
	}

	MakeGraphR(b, v, e + 1, g);
	g[v[e].first][v[e].second] = 1;
	MakeGraphR(b, v, e + 1, g);
	g[v[e].first][v[e].second] = 0;
	if (v[e].first != 0 && v[e].second != b - 1) {
		g[v[e].second][v[e].first] = 1;
		MakeGraphR(b, v, e + 1, g);
		g[v[e].second][v[e].first] = 0;
	}
}

void MakeGraph(int b)
{
	int g[10][10] = { 0 };
	vector<pair<int, int>> v;
	for (int i = 0; i < b; i++){
		for (int j = i + 1; j < b; j++) {
			v.push_back(make_pair(i, j));
		}
	}
	MakeGraphR(b, v, 0, g);
}

int main()
{
	MakeGraph(2);
	MakeGraph(3);
	MakeGraph(4);
	MakeGraph(5);
	MakeGraph(6);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int B, M;
		cin >> B >> M;
		if (!A[B].count(M)){
			cout << "Case #" << t + 1 << ": IMPOSSIBLE" << endl;
			continue;
		}

		cout << "Case #" << t + 1 << ": POSSIBLE" << endl;
		for (auto a : A[B][M]) {
			for (auto b : a) {
				cout << b;
			}
			cout << endl;
		}
	}

	return 0;
}
