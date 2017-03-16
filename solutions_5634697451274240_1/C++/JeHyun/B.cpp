#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int T;
	char buf[256];
	int data[101][2];

	fgets(buf, 256, stdin);

	sscanf(buf, "%d", &T);

	int i,j;

	for (i = 0; i < T; ++i) {
		memset(buf, 0x00, sizeof(buf));
		fgets(buf, 256, stdin);

		memset(data, 0x00, sizeof(data));

		if (buf[0] == '-') {
			data[0][0] = 1;
			data[0][1] = 0;
		} else {
			data[0][0] = 0;
			data[0][1] = 1;
		}

		for (j = 1; j < 101; ++j) {
			if (buf[j] == 0x00 || buf[j] == '\n')
				break;

			if (buf[j] == '-') {
				data[j][0] = min(data[j - 1][1] + 1, data[j - 1][0] + 2);
				data[j][1] = min(data[j - 1][1], data[j - 1][0] + 1);
			} else {
				data[j][0] = min(data[j - 1][0], data[j - 1][1] + 1);
				data[j][1] = min(data[j - 1][0] + 1, data[j - 1][1] + 2);
			}
		}

		printf("Case #%d: %d\n", i + 1, data[j - 1][0]);
	}
	return 0;
}