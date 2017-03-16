#include <cstdio>
#include <cstring>
#define MAX 1000005
#define max(x, y) (x > y) ? x : y
char str[MAX];
bool isVowel[MAX];
const char *vowel = "aeiou";
void deal(int T) {
	int L;
	int len;
	int cons;
	int last;
	long long sum;
	memset(isVowel, 0, sizeof(isVowel));
	scanf("%s%d", str, &L);
	len = strlen(str);
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 5; j++) {
			if (str[i] == vowel[j]) {
				isVowel[i] = true;
				break;
			}
		}
	}
	cons = 0;
	for (int i = 0; i < len; i++) {
		if (isVowel[i]) {
			cons = 0;
		} else {
			cons++;
		}
		if (cons >= L) {
			isVowel[i] = true;
		} else {
			isVowel[i] = false;
		}
	}
	last = -1;
	sum = 0;
	for (int i = 0; i < len; i++) {
		if (isVowel[i]) {
			last = i;
		}
		sum += max(last + 2 - L, 0);
	}
	printf("Case #%d: %lld\n", T + 1, sum);
}
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		deal(i);
	}
	return 0;
}
