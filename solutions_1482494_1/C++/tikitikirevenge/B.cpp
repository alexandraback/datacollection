#ifdef DEBUG
	#define D(x...) fprintf(stderr,x);
#else
	#define D(x...) 0
#endif
#include <cstdio>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main() {
	int nTests;
	scanf("%d ",&nTests);
	for (int test=1;test<=nTests;test++) {
		if (1) fprintf(stderr,"Case %d/%d\n",test,nTests);

		int nLevels; scanf("%d",&nLevels);
		vector<pair<int, int> > levels;
		vector<int> progress;
		for (int i = 0; i < nLevels; i++) {
			int a, b; scanf("%d%d",&a,&b);
			levels.push_back(make_pair(a,b));
			progress.push_back(0);
		}

		bool failure = false;
		int nStars = 0, nComplete = 0, nSteps = 0;
		while (nComplete != nLevels) {
			bool flag = false;
			for (int i = 0; i < nLevels; i++) {
				if (progress[i] >= 2) continue;
				if (levels[i].second <= nStars) {
					flag = true;
					nComplete++;
					nSteps++;
					nStars += 2-progress[i];
					progress[i] = 2;
					break;
				}
			}
			if (flag) continue;
			int bestId=-1, bestVal=-1;
			for (int i = 0; i < nLevels; i++) {
				if (progress[i] >= 1) continue;
				if (levels[i].first <= nStars) {
					flag = true;
					if (bestVal < levels[i].second) {
						bestVal = levels[i].second;
						bestId = i;
					}
				}
			}
			if (flag) {
				int i = bestId;
				nSteps++;
				nStars += 1-progress[i];
				progress[i] = 1;
				continue;
			}
			failure = true;
			break;
		}
		
		
		if (failure) {
			printf("Case #%d: Too Bad\n",test,nSteps);
		} else {
			printf("Case #%d: %d\n",test,nSteps);
		}
	}
}
