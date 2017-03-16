#include <iostream>
#include <cstdio>
#include <set>
#include <cassert>
#include <queue>

using namespace std;

long long reverse(long long c) {
	long long x = 0;
	while (c) {
		x = x * 10 + (c % 10);
		c /= 10;
	}
	return x;
}

set <long long> was;
queue <pair <long long, int> > q;

int solve(long long N) {
	was.clear();
	q.push(make_pair(1, 1));
	was.insert(1);
	pair <long long, int> p;
	long long nxt;
	while (!q.empty()) {
		p = q.front();
		q.pop();
		//cerr << "Processing " << p.first << " with " << p.second << "\n";
		if (p.first == N) {
			return p.second;
		}
		if (was.find(p.first + 1) == was.end()) {
			was.insert(p.first + 1);
			q.push(make_pair(p.first + 1, p.second + 1));
		}
		nxt = reverse(p.first);
		if (was.find(nxt) == was.end()) {
			was.insert(nxt);
			q.push(make_pair(nxt, p.second + 1));
		}
	}
	assert(false);
	return -1;
	// long long nc, c = 1;
	// int result = 1;
	// while (c != N) {
	// 	nc = reverse(c);
	// 	if (nc > N || nc <= c) {
	// 		nc = c + 1;
	// 	}
	// 	result++;
	// 	c = nc;
	// }
	// return result;
}

int main() {
	int T, tn = 0;
	long long N;
	cin >> T;
	while (T --> 0) {
		tn++;
		cin >> N;
		cerr << "Computing #" << tn << "\n";
		cout << "Case #" << tn << ": " << solve(N) << "\n";
	}
	return 0;
}