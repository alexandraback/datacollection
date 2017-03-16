#include <iostream>
#include <utility>
#include <string>
#include <queue>
#include <map>

using namespace std;

string solve(int x, int y)
{
	queue <pair <string, pair <int, int> > > Q;
	Q.push(make_pair("", make_pair(0, 0)));
	map <pair <int, int>, bool> visited;
	while (!Q.empty()) {
		string s = Q.front().first;
		int x1 = Q.front().second.first;
		int y1 = Q.front().second.second;
		Q.pop();
		if (visited.count(make_pair(x1, y1))) {
			continue;
		}
		visited[make_pair(x1, y1)] = 1;
		if (x1 == x && y1 == y) {
			return s;
		}
		if (!visited.count(make_pair(x1, y1 + s.size() + 1))) {
			Q.push(make_pair(s + "N", make_pair(x1, y1 + s.size() + 1)));
		}
		if (!visited.count(make_pair(x1, y1 - s.size() - 1))) {
			Q.push(make_pair(s + "S", make_pair(x1, y1 - s.size() - 1)));
		}
		if (!visited.count(make_pair(x1 + s.size() + 1, y1))) {
			Q.push(make_pair(s + "E", make_pair(x1 + s.size() + 1, y1)));
		}
		if (!visited.count(make_pair(x1 - s.size() - 1, y1))) {
			Q.push(make_pair(s + "W", make_pair(x1 - s.size() - 1, y1)));
		}
	}
}

int main(int argc, char const* const* argv)
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int x, y;
		cin >> x >> y;
		cout << "Case #" << (i + 1) << ": " << solve(x, y) << endl;
	}
	return 0;
}
