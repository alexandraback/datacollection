#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int T, N;
	char buf[512];
	bool seen[10];

	fgets(buf, 512, stdin);

	sscanf(buf, "%d", &T);

	int i, j, k;

	for (i = 0; i < T; ++i) {
		fgets(buf, 512, stdin);
		if (buf[0] == 0x00 || buf[0] == '\n')
			break;

		sscanf(buf, "%d", &N);

		long long X = 0;
		long long X2;
		memset(seen, 0x00, sizeof(seen));

		for (j = 0; j < 1000000; ++j) {
			X += N;
			X2 = X;

			while (X2 > 0) {
				seen[X2 % 10] = true;
				X2 /= 10;
			}

			for (k = 0; k < 10; ++k) {
				if (seen[k] == false)
					break;
			}

			if (k == 10)
				break;
		}

		if (j == 1000000)
			printf("Case #%d: INSOMNIA\n", i + 1);
		else
			printf("Case #%d: %lld\n", i + 1, X);
	}
}