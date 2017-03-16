#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

void init();
void runCase();

int main()
{
	int T;
	init();
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		printf("Case #%d: ", t);
		runCase();
	}
}

// algorithms

int path[1000001];

long long baseval[14];
long long basecnt[14];

int getDigitVal(int digit[6])
{
	int val = digit[0];
	for (int i = 1; i < 6; i++) {
		val = val * 10 + digit[i];
	}
	return val;
}

int getReverseVal(int digit[6])
{
	int stidx = 0;
	for (int i = 5; i >= 0; i--) {
		if (digit[i] > 0) {
			stidx = i;
			break;
		}
	}
	int lastidx = 0;
	for (int i = 0; i < 6; i++) {
		if (digit[i] > 0) {
			lastidx = i;
			break;
		}
	}

	int val = digit[stidx];
	for (int i = stidx - 1; i >= lastidx; i--) {
		val = val * 10 + digit[i];
	}
	return val;
}

void initPathCnt(int digit[6], int depth)
{
	if (depth == 6) {
		int val = getDigitVal(digit);
		if (val < 10) {
			return;
		}
		int ncnt = path[val] + 1;
		if (path[val + 1] == 0 || path[val + 1] > ncnt) {
			path[val + 1] = ncnt;
		}
		int reverse = getReverseVal(digit);
		if (path[reverse] == 0 || path[reverse] > ncnt) {
			path[reverse] = ncnt;
		}
		return;
	}

	for (int i = 0; i < 10; i++) {
		digit[depth] = i;
		initPathCnt(digit, depth + 1);
	}
}

void init() {
	memset(path, 0, 1000000*sizeof(int));
	for (int val = 0; val <= 10; val++) {
		path[val] = val;
	}
	int digit[6];
	initPathCnt(digit, 0);
}

void runCase()
{
	long long val;
	scanf("%lld", &val);
	if (val <= 1000000) {
		printf("%d\n", path[val]);
	}
}
