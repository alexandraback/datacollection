#include <cstdio>
#include <cstring>

bool digits[10];

void reset() {
	memset(digits, 0, sizeof(digits));
}

void set(int num) {
	if (num == 0) {
		digits[0] = true;
		return;
	}
	while (num) {
		digits[num % 10] = true;
		num /= 10;
	}
}

bool canSleep() {
	for (int i = 0; i < 10; i++) {
		if (!digits[i]) {
			return false;
		}
	}
	return true;
}

int main(void) {
	int count;
	scanf("%d\n", &count);
	for (int i = 1; i <= count; i++) {
		int num = 0;
		char prev, c = '0';
		while (true) {
			prev = c;
			if (scanf("%c", &c) != 1)
				break; // EOF
			if (c == '+') {
				// No-op
			} else if (c == '-' ) {
				if (prev == '0') {
					num++;
				} else if (prev == '+') {
					num += 2;
				}
			} else {
				break;
			}
		}

		printf("Case #%d: %d\n", i, num);
	}
}