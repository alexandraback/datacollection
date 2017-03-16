#include <cstdio>
#include <map>
#include <vector>
using namespace std;

void wy(int mask, const vector<int>& b) {
	int f = 1;
	for (int i = 0; i < 20; i++) {
		if (f & mask) {
			printf("%d ", b[i]);
		}
		f*=2;
	}
	puts("");
}

void test() {
	map<int, vector<int> > m;
	int limit = 1<< 20;
	int max;
	vector<int> d;
	scanf("%d", &max);
	for (int i = 0; i < max; i++) {
		int a;
		scanf("%d", &a);
		d.push_back(a);
	}
	map<int, vector<int> >::iterator it; //limit = 20;
	for (int i = 1; i < limit; i++) {
		int mask= 1;
		int sum = 0;
		for (int j = 0; j < max; j++) {
			if (mask & i) {
				sum += d[j];
			}
			mask *= 2;
		}
		it = m.find(sum);
		if (it != m.end()) {
			for (int j = 0; j < it->second.size(); j++) {
				if ((i & (it->second[j])) == 0) {
					// tutaj znalazlem
					puts("");
					wy(it->second[j], d);
					wy(i, d);
					return;
				}
			}
		}
		m[sum].push_back(i);
	}
	printf("Impossible\n");
}

main() {
	int t;
	scanf("%d", &t);
	int cid=1;
	while (t--) {
		printf("Case #%d: ", cid++);
		test();
	}
}
