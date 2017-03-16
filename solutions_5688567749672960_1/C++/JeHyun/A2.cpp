#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int *d;

int val(long long n) {
	if (n < 100000)
		return d[n];

	//cout << n << endl;

	char buf[20];
	char buf2[20];
	char buf3[20];
	memset(buf, 0x00, sizeof(buf));
	memset(buf2, 0x00, sizeof(buf2));

	long long nn = n;
	int len = 0;

	while (nn != 0) {
		buf[len++] = (nn % 10) + '0';
		nn /= 10;
	}

	reverse(buf, buf + len);

	int ind = len / 2;

	memset(buf2, '0', len - ind);

	if (strncmp(buf + ind, buf2, len - ind) == 0) {
		if (buf[0] == '1' && (buf[ind - 1] == '1' || buf[ind - 1] == '0') && strncmp(buf + 1, buf2, ind - 2) == 0) {
			if (len % 2 == 0) {
				//cout << "case 1" << endl;
				memset(buf3, 0x00, sizeof(buf3));
				memset(buf3, '9', ind - 1);
				memset(buf3 + ind - 1, '0', len - ind);

				buf3[len - 2] = '1';

				long long nn2 = 0;

				int i;
				for (i = 0; i < len - 1; ++i) {
					nn2 *= 10;
					nn2 += buf3[i] - '0';
				}

				return val(nn2) + (n - nn2);
			} else {
				//cout << "case 2" << endl;
				memset(buf3, 0x00, sizeof(buf3));
				memset(buf3, '9', ind);
				memset(buf3 + ind, '0', len - ind - 1);

				buf3[len - 2] = '1';

				long long nn2 = 0;

				int i;
				for (i = 0; i < len - 1; ++i) {
					nn2 *= 10;
					nn2 += buf3[i] - '0';
				}

				return val(nn2) + (n - nn2);
			}
		} else {
			long long nn2 = 0;

			int i;
			for (i = 0; i < len; ++i) {
				nn2 *= 10;
				if (i == ind - 1)
					nn2 += buf[i] - '0' - 1;
				else
					nn2 += buf[i] - '0';
			}
			++nn2;

			return val(nn2) + (n - nn2);
		}
	} else if (strncmp(buf + ind, buf2, len - ind - 1) == 0 && buf[len - 1] == '1') {
		long long nn2 = 0;
		int i;

		for (i = len - 1; i >= 0; --i) {
			nn2 *= 10;
			nn2 += buf[i] - '0';
		}

		if (nn2 != n)
			return val(nn2) + 1;
		else
			return val(n - 1) + 1;
	} else {
		memcpy(buf + ind, buf2, len - ind);
		buf[len - 1] = '1';

		long long nn2 = 0;

		int i;
		for (i =0; i < len; ++i) {
			nn2 *= 10;
			nn2 += buf[i] - '0';
		}

		return val(nn2) + (n - nn2);
	}
}

int main() {
	d = new int[1000002];

	int i;

	int T;
	int N;

	for (i = 0; i < 1000001; ++i) {
		d[i] = i;
	}

	//printf("Step 1 finished\n");

	for (i = 1; i < 1000001; ++i) {
		char buf[100];
		memset(buf, 0x00, sizeof(buf));
		itoa(i, buf, 10);
		int len = strlen(buf);
		reverse(buf, buf + len);
		int newnum = atoi(buf);

		d[newnum] = min(d[newnum], d[i] + 1);
		d[i + 1] = min(d[i + 1], d[i] + 1);
	}

	//printf("Step 2 finished\n");

	char buf[30];

	memset(buf, 0x00, sizeof(buf));
	fgets(buf, 30, stdin);

	sscanf(buf, "%d", &T);

	for(i = 0; i < T; ++i) {
		long long N;

		memset(buf, 0x00, sizeof(buf));
		fgets(buf, 30, stdin);

		sscanf(buf, "%lld", &N);		

		printf("Case #%d: %d\n", i + 1, val(N));
	}

	return 0;
}