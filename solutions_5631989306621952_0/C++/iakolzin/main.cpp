#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
	freopen("inputs.txt", "r", stdin);
	freopen("outputs.txt", "w", stdout);
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		string s;
		cin >> s;
		deque <char> q;
		for (char c: s) {
			if (q.empty()) {
				q.push_back(c);
				continue;
			}
			if (q.front() <= c)
				q.push_front(c);
			else
				q.push_back(c);
		}
		cout << "Case #" << t << ": ";
		while (!q.empty()) {
			cout << q.front();
			q.pop_front();
		}
		cout << endl;
	}
	return 0;
}