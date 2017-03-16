#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
	int testNum;
	cin >> testNum;
	int caseNum = 0;
	while (++caseNum <= testNum) {
		int r, c, w;
		cin >> r >> c >> w;
		int result = (r - 1) * (c / w) + (c / w) + w;
		if (c % w == 0)
			result -= 1;

		printf("Case #%d: %d\n", caseNum, result);
	}
	return 0;
}

