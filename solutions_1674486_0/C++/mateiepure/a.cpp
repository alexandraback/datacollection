#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;

ifstream in("a.in");
ofstream out("a.out");

const int N = 1001;

int n;
bool viz[N];
bool st[N];

vector <int> v[N];
queue <int> q;

void readCase() {
	in >> n;

	for (int i = 1; i <= n; ++i) {
		v[i].erase(v[i].begin(), v[i].end());

		int nr;
		in >> nr;

		while (nr--) {
			int x;
			in >> x;
			st[x] = true;

			v[i].push_back(x);
		}
	}
}

bool Check(int node) {
	memset(viz, 0, sizeof(viz));
	while (!q.empty())
		q.pop();
	q.push(node);
	viz[node] = true;

	while (!q.empty()) {
		int curNode = q.front();
		q.pop();

		for (int i = 0; i < (int)v[curNode].size(); ++i) {
			int next = v[curNode][i];

			if (viz[next])
				return true;
			else {
				viz[next] = true;
				q.push(next);
			}
		}
	}

	return false;
}

void solveCase() {
	for (int i = 1; i <= n; ++i)
		if (Check(i)) {
			out << "Yes\n";
			return;
		}

	out << "No\n";
}

int main() {
	int t;
	in >> t;

	for (int i = 1; i <= t; ++i) {
		readCase();

		out << "Case #" << i << ": ";
		solveCase();
	}

	return 0;
}
