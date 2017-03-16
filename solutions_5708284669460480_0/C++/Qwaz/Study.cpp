#include <cstdio>
#include <algorithm>

using namespace std;

int maxCount, allCount, allCase;

int numKey, patternLength, resultLength;
char keyboard[99], pattern[99], result[99];

void makePattern(int level) {
	if (level == resultLength) {
		int i, j, count = 0;
		for(i = 0; i <= resultLength - patternLength; i++) {
			for(j = 0; j < patternLength; j++) {
				if(result[i+j] != pattern[j]) break;
			}

			if(j == patternLength)
				count++;
		}

		maxCount = max(maxCount, count);
		allCount += count;
		allCase++;
	} else {
		int i;
		for(i = 0; i < numKey; i++) {
			result[level] = keyboard[i];
			makePattern(level+1);
		}
	}
}

int main() {
	freopen("B.out", "w", stdout);

	int numCase, nowCase;
	scanf("%d", &numCase);

	for(nowCase = 1; nowCase <= numCase; nowCase++) {
		maxCount = allCount = allCase = 0;

		scanf("%d%d%d", &numKey, &patternLength, &resultLength);
		scanf("%s%s", &keyboard, &pattern);

		makePattern(0);

		printf("Case #%d: %.10lf\n", nowCase, maxCount - (double)allCount/allCase);
	}

	return 0;
}