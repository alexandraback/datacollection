#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <numeric>

using namespace std;

set<pair<pair<int, int>, pair<int, int> > > heap;
map<int, int> wallSize, afterAttacks;
set<int> successfullyAttacked;
int N;
int tribes[11][8];
#define INIT_DAY 0
#define ATTACKS 1
#define WEST 2
#define EAST 3
#define INIT_STRENGTH 4
#define DELAY 5
#define DELTA_POS 6
#define DELTA_STRENGTH 7

void read() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%d", &tribes[i][j]);
		}
	}
}

void process() {
	heap.clear();
	wallSize.clear();
	afterAttacks.clear();
	for (int i = 0; i < N; i++) {
		for (int j = tribes[i][WEST]; j <= tribes[i][EAST]; j++) {
			for (int k = 0; k < tribes[i][ATTACKS]; k++) {
				heap.insert(
					make_pair(
						make_pair(
							tribes[i][INIT_DAY] + k * tribes[i][DELAY],
							i
						),
						make_pair(
							tribes[i][INIT_STRENGTH] + k * tribes[i][DELTA_STRENGTH],
							k * tribes[i][DELTA_POS] + tribes[i][WEST] + j
						)
					)
				);
			}
		}
	}
	int day = -1;
	successfullyAttacked.clear();
	int attacks = 0;
	while (!heap.empty()) {
		pair<pair<int, int>, pair<int, int> > tmp = *(heap.begin());
		heap.erase(heap.begin());
		int actualDay = tmp.first.first;
		int tribe = tmp.first.second;
		int strength = tmp.second.first;
		int position = tmp.second.second;
		if (actualDay > day) {
			for (map<int, int>::iterator it = afterAttacks.begin(); it != afterAttacks.end(); it++) {
				wallSize[it->first] = it->second;
			}
			afterAttacks.clear();
			attacks += (int)successfullyAttacked.size();
			successfullyAttacked.clear();
			day = actualDay;
		}
		if (wallSize.count(position) == 0 or wallSize[position] < strength) {
			successfullyAttacked.insert(tribe);
			afterAttacks[position] = max(afterAttacks[position], strength);
		}
	}
	attacks += (int)successfullyAttacked.size();
	printf("%d\n", attacks);
}

int main() {
	int cases;
	scanf("%d", &cases);
	for (int i = 1; i <= cases; i++) {
		read();
		printf("Case #%d: ", i);
		process();
	}
	return 0;
}