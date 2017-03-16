#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

int main() {
	char buf[512];
	fgets(buf, 512, stdin);

	int T, N, J;

	sscanf(buf, "%d", &T);

	fgets(buf, 512, stdin);

	sscanf(buf, "%d %d", &N, &J);

	int i, j, k;

	string oneval = "1";
	string zeroval = "0";

	long long maxv = 1;
	long long times[11];
	long long number[11];
	long long div[11];

	for (i = 0; i < N - 2; ++i) {
		maxv *= 2;
	}

	int res_num = 0;

	printf("Case #1:\n");

	for (i = 0; i < maxv; ++i) {
		string val = "";

		memset(times, 0x00, sizeof(times));
		memset(number, 0x00, sizeof(number));
		memset(div, 0x00, sizeof(div));

		for (j = 2; j <= 10; ++j) {
			number[j] = 1;
			times[j] = j;
			val = "1";
		}

		long long v = i;

		for (j = 1; j < N - 1; ++j) {
			if (v % 2 == 1) {
				val = oneval + val;
			} else {
				val = zeroval + val;
			}

			for (k = 2; k <= 10; ++k) {
				if (v % 2 == 1) {
					number[k] += times[k];
				}
				times[k] *= k;
			}

			v /= 2;
		}

		for (j = 2; j <= 10; ++j) {
			number[j] += times[j];
		}
		val = oneval + val;

		for (j = 2; j <= 10; ++j) {
			long long s = (long long)(sqrt((double)number[j]) + 1);

			for (k = 2; k <= s; ++k) {
				if (number[j] % k == 0) {
					div[j] = k;
					break;
				}
			}

			if (k > s)
				break;
		}

		if (j > 10) {
			printf("%s", val.c_str());
			for (k = 2; k <= 10; ++k)
				printf(" %d", div[k]);
			printf("\n");

			++res_num;

			if (res_num >= J)
				break;
		} else {
			//printf("%s no\n", val.c_str());
		}
	}
}