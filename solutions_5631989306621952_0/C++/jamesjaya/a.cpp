#include <iostream>
#include <deque>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++) {
		deque<char> d;
		string s;
		cin >> s;
		d.push_back(s[0]);
		for (int j = 1; j < s.size(); j++) {
			if (s[j] >= d.front()) {
				d.push_front(s[j]);
			} else {
				d.push_back(s[j]);
			}
		}
		cout << "Case #" << t << ": ";
		while (!d.empty()) {
			cout << d.front();
			d.pop_front();
		}
		cout << '\n';
	}
}