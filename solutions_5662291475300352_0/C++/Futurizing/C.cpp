#include <cstdio>

void calc() {
	long long hiker[2][2]; // Pos, Period
	int ans = 0;
	int i, j;
	int groupCount;
	long long pos, time;
	int num;
	int hikerCount = 0;

	scanf("%d", &groupCount);
	while (groupCount--) {
		scanf("%lld %d %lld", &pos, &num, &time);
		for (i = 0; i < num; i++) {
			hiker[hikerCount][0] = pos;
			hiker[hikerCount][1] = time + i;
			hikerCount++;
		}
	}

	if (hikerCount == 1) {
		ans = 0;
	} else { // hikerCount == 2
		long long timeStart1 = (360 - hiker[0][0]) * hiker[0][1];
		long long timeEnd1 = timeStart1 + hiker[0][1] * 360;

		long long timeStart2 = (360 - hiker[1][0]) * hiker[1][1];
		long long timeEnd2 = timeStart2 + hiker[1][1] * 360;
		// printf(" (%lld, %lld) (%lld, %lld) \n", timeStart1, timeEnd1, timeStart2, timeEnd2);

		if (
			(timeStart1 > timeStart2 && timeStart1 < timeEnd2) ||
			(timeEnd1 > timeStart2 && timeEnd1 < timeEnd2) ||
			(timeStart1 <= timeStart2 && timeEnd1 >= timeEnd2)
			) {
			ans = 0;
		} else {
			ans = 1;
		}
	}


	printf("%d\n", ans);
}

int main() {
	int t, testcase;

	scanf("%d", &testcase);
	for (t = 1; t <= testcase; t++) {
		printf("Case #%d: ", t);
		calc();
	}

	return 0;
}