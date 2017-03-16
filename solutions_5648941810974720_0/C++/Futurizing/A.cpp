#include <cstdio>
#include <map>

using namespace std;

int counter[256] = {};
char numStr[10][6] = {
	"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};
map<char, int> numStrCount[10];
int counterSum;

int ans[2000];
bool isFinish;

void calc(int min, int pos) {
	int i, j;

	if (counterSum == 0) {
		for (i = 0; i < pos; i++) {
			printf("%d", ans[i]);
		}
		isFinish = true;
		return;
	}
	
	for (i = min; i <= 9; i++) {
		map<char, int>::iterator it;
		int maxUse = 1000000;
		for (it = numStrCount[i].begin(); it != numStrCount[i].end(); it++) {
			int use = counter[it->first] / it->second;
			if (use < maxUse) {
				maxUse = use;
			}
		}
		for (j = 0; j < maxUse; j++) {
			ans[pos + j] = i;
		}
		
		for (j = maxUse; j > 0; j--) {
			for (it = numStrCount[i].begin(); it != numStrCount[i].end(); it++) {
				counter[it->first] -= it->second * j;
				counterSum -= it->second * j;
			}

			calc(i + 1, pos + j);
			if (isFinish) return;

			for (it = numStrCount[i].begin(); it != numStrCount[i].end(); it++) {
				counter[it->first] += it->second * j;
				counterSum += it->second * j;
			}
		}
	}
}

void testcase() {
	char input[2001];
	int i;

	for (i = 0; i < 256; i++) {
		counter[i] = 0;
	}

	scanf("%s", input);
	for (i = 0; input[i]; i++) {
		counter[input[i]]++;
	}
	// for (i = 0; i < 10; i++) {
	// 	for (int j = 0; numStr[i][j]; j++) {
	// 		counter[numStr[i][j]]++;
	// 	}
	// }

	// for (i = 0; i < 256; i++) {
	// 	if (counter[i] != 0) {
	// 		printf("\n%c: %d", i, counter[i]);
	// 	}
	// }

	isFinish = false;
	counterSum = i;

	calc(0, 0);
	if (!isFinish) printf("ERROR");

	printf("\n");
}

void init() {
	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; numStr[i][j]; j++) {
			numStrCount[i][numStr[i][j]]++;
		}
	}
}

int main() {
	int t, tc;

	init();

	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		printf("Case #%d: ", t);
		testcase();
	}
	return 0;
}