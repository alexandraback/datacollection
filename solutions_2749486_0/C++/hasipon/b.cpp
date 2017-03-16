#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <cstdlib>
using namespace std;
map<pair<int,int>, string> memo;
int main() {
	queue<pair<pair<int,int>, string> > Q;
	Q.push(make_pair(make_pair(0, 0), ""));
	for (;;) {
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		string s = Q.front().second;
		int d = s.length() + 1;
		if (d > 20) break;
		if (!(-200 <= x && x <= 200 && -200 <= y && y <= 200)) continue;
		Q.pop();
		if (!memo.count(make_pair(x+d,y))) Q.push(make_pair(make_pair(x+d,y), memo[make_pair(x+d,y)] = s + "E"));
		if (!memo.count(make_pair(x-d,y))) Q.push(make_pair(make_pair(x-d,y), memo[make_pair(x-d,y)] = s + "W"));
		if (!memo.count(make_pair(x,y+d))) Q.push(make_pair(make_pair(x,y+d), memo[make_pair(x,y+d)] = s + "N"));
		if (!memo.count(make_pair(x,y-d))) Q.push(make_pair(make_pair(x,y-d), memo[make_pair(x,y-d)] = s + "S"));
	}
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++ tt) {
		int x, y;
		cin >> x >> y;
		cout << "Case #" << tt << ": " << memo[make_pair(x, y)] << endl;
	}
}
