#include <cstdio>
#include <cstring>
#include <cstdlib>

char buffer1[19];
char buffer2[19];
char counter1[19];
char counter2[19];
int map[256];
int count[10];

void increment(char* pattern, char* counter) {
	int len = strlen(counter);
	for (int i = len - 1; i >= 0; i--) {
		if (pattern[i] != '?') continue;
		if (counter[i] == '9') {
			counter[i] = '0'; // Carry forward
		} else {
			counter[i]++;
			break;
		}
	}
}

void decrement(char* pattern, char* counter) {
	int len = strlen(counter);
	for (int i = len - 1; i >= 0; i--) {
		if (pattern[i] != '?') continue;
		if (counter[i] == '0') {
			counter[i] = '9'; // Carry forward
		} else {
			counter[i]--;
			break;
		}
	}
}

int diff(char* c1, char* c2) {
	int diff = 0;
	while (*c1) {
		diff *= 10;
		diff += *c1 - *c2;
		c1++; c2++;
	}
	return diff;
}

int main(void) {
	int cases;
	scanf("%d", &cases);
	for (int c = 1; c <= cases; c++) {
		scanf("%s", buffer1);
		scanf("%s", buffer2);

		int len = strlen(buffer1);
		for (int i = 0; i < len; i++) {
			counter1[i] = buffer1[i] == '?' ? '0' : buffer1[i];
			counter2[i] = buffer2[i] == '?' ? '0' : buffer2[i];
		}
		counter1[len] = counter2[len] = 0;

		int d = diff(counter1, counter2);
		while (true) {
			if (d < 0) {
				increment(buffer1, counter1);
			} else {
				increment(buffer2, counter2);
			}
			int nd = diff(counter1, counter2);
			if (abs(nd) < abs(d)) {
				d = nd;
			} else {
				if (d < 0) {
					decrement(buffer1, counter1);
				} else {
					decrement(buffer2, counter2);
				}
				break;
			}
		}

		printf("Case #%d: %s %s\n", c, counter1, counter2);
	}
	return 0;
}