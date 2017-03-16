#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

#define REP(i,n) for(int i = 0; i < (n); i++)
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)

void solve() {
	string s;
	cin >> s;
	deque<char> q;
	q.push_back(s[0]);
	FOR(i, 1, s.size() - 1) {
		char c = s[i];
		if (c >= q.front()) {
			q.push_front(c);
		} else {
			q.push_back(c);
		}
	}
	for (char c : q) {
		cout << c;
	}
}

int main() {
	int t;
	cin >> t;
	REP(i, t) {
		cout << "Case #" << (i+1) << ": ";
		solve();
		cout << endl;
	}
}