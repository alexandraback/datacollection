#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>

using namespace std;

typedef struct {
	int x;
	int y;
	int step;
	string ans;
} Item;

bool operator < (const Item &a, const Item &b) {
	if (a.x < b.x)
		return true;
	else if (a.x > b.x)
		return false;
	else
		return a.y < b.y;
}

int ways[4][2] = {
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, -1}};
char waysname[4] = {'E', 'N', 'W', 'S'};

void solve(int testcase) {
	cout << "Case #" << testcase << ": ";
	int x, y;

	cin >> x >> y;

	Item item;
	item.x = 0;
	item.y = 0;
	item.step = 0;
	item.ans = "";
	queue<Item> que;
	set<Item> visited;

	que.push(item);

	while (!que.empty()) {
		Item now = que.front();
		que.pop();

		if (now.step>500)
			continue;
		if (now.x==x && now.y==y) {
			cout << now.ans;
			break;
		}

		for (int i=0; i<4; i++) {
			Item next;
			next.step = now.step+1;
			next.x = now.x + ways[i][0] * next.step;
			next.y = now.y + ways[i][1] * next.step;
			
			if (visited.find(next) != visited.end())
				continue;
			visited.insert(next);

			next.ans = now.ans + waysname[i];
			que.push(next);
		}

	}

	cout << endl;
}

int main () {
	int testcases;

	cin >> testcases; 

	for (int testcase=1; testcase<=testcases; testcase++) {
		solve(testcase);
	}
	return 0;
}
