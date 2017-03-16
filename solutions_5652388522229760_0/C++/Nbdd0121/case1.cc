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
	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		int input;
		scanf("%d", &input);

		if (input == 0) {
			printf("Case #%d: INSOMNIA\n", i + 1);
			continue;
		}

		reset();
		int sum = 0;
		while (!canSleep()) {
			sum += input;
			set(sum);
		}

		printf("Case #%d: %d\n", i + 1, sum);
	}
}