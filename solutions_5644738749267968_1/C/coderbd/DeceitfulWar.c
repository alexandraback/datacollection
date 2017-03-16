#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[64];
int naomi_weight[1024], ken_weight[1024];

int cmp(const void* pa, const void* pb) {
	int a = *((int*) pa);
	int b = *((int*) pb);
	return (a > b) - (a < b);
}

int parse(char s[]) {
	int extra = 7 - (int) strlen(s);
	while (extra--)
		strcat(s, "0");
	return atoi(s);
}

int play_deceitful_war(int n) {
	int i, j, cnt = 0;
	for (i = j = 0; i < n && j < n; i++, j++) {
		while (i < n && naomi_weight[i] < ken_weight[j])
			i++;
		if (i < n)
			cnt++;
	}
	return cnt;
}

int play_war(int n) {
	int i, j, cnt = n;
	for (i = j = 0; i < n && j < n; i++, j++) {
		while (j < n && naomi_weight[i] > ken_weight[j])
			j++;
		if (j < n)
			cnt--;
	}
	return cnt;
}

void solve(int x) {
	int i, n, y, z;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%*d.%s", buf);
		naomi_weight[i] = parse(buf);
	}
	for (i = 0; i < n; i++) {
		scanf("%*d.%s", buf);
		ken_weight[i] = parse(buf);
	}

	qsort(naomi_weight, n, sizeof(int), cmp);
	qsort(ken_weight, n, sizeof(int), cmp);

	y = play_deceitful_war(n);
	z = play_war(n);

	printf("Case #%d: %d %d\n", x, y, z);
}

int main(int argc, char* argv[]) {
	int case_no, t;

	scanf("%d", &t);
	for (case_no = 1; case_no <= t; case_no++)
		solve(case_no);

	return 0;
}