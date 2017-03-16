#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

vector< pair<int, pair<int, int> > > result;
map< pair<int, int>, int> m1, m2, m3;


int tryr(int j, int p, int s, int K) {
	pair<int, int> p1 = make_pair(j, p);
	pair<int, int> p2 = make_pair(j, s);
	pair<int, int> p3 = make_pair(p, s);

	if (m1.find(p1) == m1.end()) {
		m1.insert(make_pair(p1, 0));
	}
	if (m2.find(p2) == m2.end()) {
		m2.insert(make_pair(p2, 0));
	}
	if (m3.find(p3) == m3.end()) {
		m3.insert(make_pair(p3, 0));
	}
	if (m1[p1] < K && m2[p2] < K && m3[p3] < K) {
		m1[p1]++;
		m2[p2]++;
		m3[p3]++;
		result.push_back(make_pair(j, make_pair(p, s)));
		return 1;
	} else {
		return 0;
	}
}

int main (){
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		int J, P, S, K;
		scanf("%d %d %d %d", &J, &P, &S, &K);
		printf("Case #%d: ", t);
		int r = 0;
		for (int j = 1; j <= J; ++j) {
			for (int p = 1; p <= P; ++p) {
				for (int s = 1; s <= S; ++s) {
					r += tryr(j, p, s, K);
				}
			}
		}
		printf("%d\n", r);
		for (int i = 0; i < r; ++i) {
			printf("%d %d %d\n", result[i].first, result[i].second.first, result[i].second.second);
		}
		result.clear();
		m1.clear();
		m2.clear();
		m3.clear();
	}
	return 0;
}