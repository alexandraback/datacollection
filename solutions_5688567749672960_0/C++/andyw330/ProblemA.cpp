#include <cstdio>
#include <string>
using namespace std;

int rec[1000001];

int reverse(int num) {
	/*char str[20], ch;
	sprintf(str, "%d", num);
	int l = strlen(str);
	for (int i = 0; i < l; ++i){
		ch =
	}*/
	int x = 0;
	while (num) {
		x *= 10;
		x += num % 10;
		num /= 10;
	}
	return x;
}

int main() {
	int re, n, t, tc = 0;
	for (int i = 1; i <= 1000000; ++i) {
		if (!rec[i])
			rec[i] = rec[i - 1] + 1;
		else if (rec[i - 1] + 1 < rec[i]) {
			rec[i] = rec[i - 1] + 1;
		}
		re = reverse(i);
		if (rec[re]) {
			if (rec[i] + 1 < rec[re])
				rec[re] = rec[i] + 1;
		} else
			rec[re] = rec[i] + 1;
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("Case #%d: %d\n", ++tc, rec[n]);
	}
	return 0;
}