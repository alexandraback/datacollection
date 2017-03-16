#include <iostream>
#include <cstdio>
using namespace std;

int T, n;

bool flag[10];

bool signal(int m, bool flag[10]) {
	while (m) {
		flag[m%10] = true;
		m/=10;
	}
	for (int i = 0; i < 10; i++) {
		if (!flag[i]) return false;
	}
	return true;
}

int main() {
	scanf("%d", &T);
	for (int TT = 1; TT <= T; TT++) {
		printf("Case #%d: ", TT);
		scanf("%d", &n);
		if (n == 0) {
			printf("INSOMNIA\n");
			continue;
		}
		memset(flag, 0, sizeof(flag));
		for (int m = n;;m += n) {
			if (signal(m, flag)) {
				printf("%d\n", m);
				break;
			}	
		}
	}

	return 0;
}