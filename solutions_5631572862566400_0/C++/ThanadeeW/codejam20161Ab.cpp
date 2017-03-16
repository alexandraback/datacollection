#include "main.h"
#include "DynamicProgramming.h"

using namespace std;

void Core::init() {}

int rfriendCount(map<int, set<int>> const& rf, int c, int e) {
	int max = 0;
	ifMapContain(i, rf, c) {
		fore(i, i->second) {
			if (*i != e) {
				max = std::max(max, rfriendCount(rf, *i, e) + 1);
			}
		}
	}
	return max;
}

void Core::solve() {
	int N;
	CGET(N);
	vector<int> f(N);
	fori(i, N) {
		CGET(f[i]);
		--f[i];
	}
	map<int, set<int>> rf;
	set<int> h;
	fori(i, N) {
		if (f[f[i]] == i) {
			h.insert(i);
		}
		rf[f[i]].insert(i);
	}
	int m = 0;
	fori(current, N) {
		int c = current;
		set<int> s;
		vector<int> v;
		while (s.insert(c).second) {
			v.push_back(c);
			c = f[c];
		}
		if (f[*v.rbegin()] == current) {
			m = std::max(m, (int)s.size());
		} else if (f[*v.rbegin()] == *(v.rbegin() + 1)) {
			auto e = *v.rbegin();
			auto le = *(v.rbegin() + 1);
			m = std::max(m, (int)s.size() + rfriendCount(rf, e, le));
		}
	}
	cout << m;
}