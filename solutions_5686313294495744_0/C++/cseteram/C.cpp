#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>

using namespace std;
typedef pair<string,string> pss;

char buf[22], buf2[22];

int ans=0;

bool possible(vector<pss> &v, vector<int> &pos) {
	// 0 : fake, 1 : real

	int n = v.size();
	vector<int> sheet(pos.begin(), pos.end());

	set<string> s1, s2;

	for(int i=0 ; i<n ; i++) {
		if(pos[i]) {
			s1.insert(v[i].first);
			s2.insert(v[i].second);
		}
	}

	int repeat = 16;
	while(repeat--) {
		for(int i=0 ; i<n ; i++) {
			if (sheet[i]) continue;

			bool can = s1.count(v[i].first) && s2.count(v[i].second);
			if (can) {
				sheet[i] = 1;
			}
		}
	}

	for(int i=0 ; i<n ; i++)
		if (!sheet[i]) return false;
	return true;
}

void back(vector<pss> &v, vector<int> &pos) {
	if (pos.size() == v.size()) {
		// check it is possible
		if (possible(v, pos)) {
			int cnt = 0;
			for(int i=0 ; i<pos.size() ; i++)
				if (!pos[i]) cnt++;
			ans = max(ans, cnt);
		}

		return;
	}

	pos.push_back(0);
	back(v, pos);
	pos.back() = 1;
	back(v, pos);
	pos.pop_back();
}

void solve_small(vector<pss> &v) {
	ans = 0;
	int n = v.size();

	vector<int> pos;
	back(v, pos);

	printf("%d\n", ans);
	return;
}

int main() {

	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);

	int T;
	scanf("%d", &T);

	for(int tc=1 ; tc<=T ; tc++) {
		int n;
		scanf("%d", &n);

		vector<pss> v;
		for(int i=0 ; i<n ; i++) {
			scanf("%s %s", buf, buf2);
			v.push_back(pss(string(buf), string(buf2)));
		}

		printf("Case #%d: ", tc);
		solve_small(v);
	}

	return 0;
}