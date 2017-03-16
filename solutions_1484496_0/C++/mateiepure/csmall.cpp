#include <fstream>
#include <queue>
#include <cstdlib>
#include <cstring>

using namespace std;

ifstream in("csmall.in");
ofstream out("csmall.out");

const int N = 22;
const int A = 2000002;

int n;
int v[N];
int app[A];

queue < pair<int,int> > q;

void readCase() {
	in >> n;

	for (int i = 1; i <= n; ++i)
		in >> v[i];

	while (!q.empty())
		q.pop();

	q.push(make_pair(0, 0));
}

inline int bitter(int x) {
	return (1<<(x-1));
}

void solveCase() {
	memset(app, 0, sizeof(app));

	while (!q.empty()) {
		int curSum = q.front().first;
		int curConf = q.front().second;
		q.pop();

		for (int i = 1; i <= n; ++i)
			if ((curConf & bitter(i)) == 0) {
				if (app[curSum + v[i]] == 0) {
					app[curSum + v[i]] = curConf + bitter(i);
					q.push(make_pair(curSum + v[i], curConf + bitter(i)));
				}
				else if (app[curSum + v[i]] != curConf + bitter(i)) {
					curConf += bitter(i);

					for (int f = 1; f <= n; ++f)
						if ((curConf & bitter(f)) != 0)
							out << v[f] << " ";
					out << "\n";
					curConf = app[curSum + v[i]];

					for (int f = 1; f <= n; ++f)
						if ((curConf & bitter(f)) != 0)
							out << v[f] << " ";
					out << "\n";
					return;
				}
			}
	}

	out << "Impossible\n";
}

int main() {
	int t;
	in >> t;

	for (int i = 1; i <= t; ++i) {
		readCase();

		out << "Case #" << i << ": " << "\n";
		solveCase();
	}

	return 0;
}
