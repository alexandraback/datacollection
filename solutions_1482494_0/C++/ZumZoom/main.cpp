#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>

using namespace std;

int n;

const int INF = 2147483647;

struct sost {
	bool A[1000][2];
	int stars, steps;
	
	bool got_it() {
		for(int i = 0; i < n; ++i)
			if(!A[i][1])
				return false;
		return true;
	}

	void set_up() {
		for(int i = 0; i < n; ++i) {
			A[i][0] = false;
			A[i][1] = false;
		}
		stars = 0;
		steps = 0;
	}
};

bool cmp(pair <int, int> const& a, pair <int, int> const& b) {
	if(a.second > b.second)
		return true;
	if(a.second == b.second && a.first > b.first)
		return true;
	return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cin >> n;
		vector < pair <int, int> > A(n);
		for(int i = 0; i < n; ++i)
			cin >> A[i].first >> A[i].second;
		
		sort(A.begin(), A.end(), cmp);

		sost cur;
		cur.set_up();
		
		bool done = true;
		while(done && !cur.got_it()) {
			done = false;
			for(int i = 0; i < n; ++i)
				if(!cur.A[i][1] && A[i].second <= cur.stars) {
					cur.A[i][1] = true;
					++cur.steps;
					cur.stars += cur.A[i][0] ? 1 : 2;
					done = true;
					cur.A[i][0] = true;
					break;
				}
			if(done)
				continue;
			for(int i = 0; i < n; ++i)
				if(!cur.A[i][0] && A[i].first <= cur.stars) {
					cur.A[i][0] = true;
					++cur.steps;
					cur.stars++;
					done = true;
					break;
				}
		}
		cout << "Case #" << t << ": ";
		if(cur.got_it())
			cout << cur.steps << endl;
		else
			cout << "Too Bad" << endl;
	}

	return 0;
}