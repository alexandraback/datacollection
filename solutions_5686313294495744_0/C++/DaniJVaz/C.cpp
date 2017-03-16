#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_set>

typedef long long ll;

using namespace std;

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int N;
		scanf("%d", &N);

		vector<string> topics1, topics2;
		for (int i=0; i<N; i++) {
			char t1[25], t2[25];
			scanf("%s %s", t1, t2);
			topics1.push_back(t1);
			topics2.push_back(t2);
		}

		int maxF = 0;
		unordered_set<string> real_topics1, real_topics2;
		for (int k=0; k<(1LL << 16); k++) {
			real_topics1.clear();
			real_topics2.clear();
			int fakes = 0;

			for (int i=0; i<N; i++) {
				if (k&(1LL << i)) {
					real_topics1.insert(topics1[i]);
					real_topics2.insert(topics2[i]);
				}
			}

			for (int i=0; i<N; i++) {
				if (k&(1LL << i))
					continue;
				if (real_topics1.count(topics1[i]) > 0 and real_topics2.count(topics2[i]) > 0)
					fakes ++;
			}
			maxF = max(maxF, fakes);
		}
		printf("Case #%d: %d\n", iC, maxF);
	}
	return 0;
}