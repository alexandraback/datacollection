#include <cstdio>
#include <cstring>

char s1[20], s2[20];
char a1[20], a2[20];
char d1[20], d2[20];
long long ans1, ans2, ansdiff;
int n;

void getans() {
	d1[n] = d2[n] = '\0';
	for (int i = n - 1; i >= 0; i--) {
		d1[i] = ans1 % 10 + '0';
		d2[i] = ans2 % 10 + '0';
		ans1 /= 10;
		ans2 /= 10;
	}
}
long long abs(long long x) {
	if (x >= 0) return x;
	return -x;
}
void update() {
	long long b1 = 0, b2 = 0;
	for (int i = 0; i < n; i++) {
		b1 = b1 * 10 + a1[i] - '0';
		b2 = b2 * 10 + a2[i] - '0';
	}
	long long diff = abs(b1 - b2);
	if (diff < ansdiff ||
			(diff == ansdiff && b1 < ans1) ||
			(diff == ansdiff && b1 == ans1 && b2 < ans2)) {
		ans1 = b1;
		ans2 = b2;
		ansdiff = diff;
	}
}
void fill(int m, char x1, char x2) {
	a1[m] = x1; a2[m] = x2;
	for (int i = m + 1; i < n; i++) {
		if (s1[i] != '?') a1[i] = s1[i];
		else a1[i] = x1 < x2? '9' : '0';
		if (s2[i] != '?') a2[i] = s2[i];
		else a2[i] = x2 < x1? '9' : '0';
	}
	update();
}
void cal(int m) {
	for (int i = 0; i < m; i++) {
		if (s1[i] == '?' && s2[i] == '?') a1[i] = a2[i] = '0';
		else if (s1[i] == '?') a1[i] = a2[i] = s2[i];
		else if (s2[i] == '?') a1[i] = a2[i] = s1[i];
		else if (s1[i] != s2[i]) return;
		else a1[i] = a2[i] = s1[i];
	}
	if (m == n) update();
	else {
		if (s1[m] == '?' && s2[m] == '?') {
			fill(m, '0', '1');
			fill(m, '1', '0');
		} else if (s1[m] == '?') {
			if (s2[m] != '0') fill(m, s2[m] - 1, s2[m]);
			if (s2[m] != '9') fill(m, s2[m] + 1, s2[m]);
		} else if (s2[m] == '?') {
			if (s1[m] != '0') fill(m, s1[m], s1[m] - 1);
			if (s1[m] != '9') fill(m, s1[m], s1[m] + 1);
		} else if (s1[m] != s2[m]) fill(m, s1[m], s2[m]);
		else return;
	}
}

int main() {
	int t, tt;
	scanf("%d", &t);
	for (tt = 1; tt <= t; tt++) {
		scanf("%s%s", s1, s2);
		n = strlen(s1);
		ansdiff = ~0ull >> 1;
		for (int i = 0; i <= n; i++) cal(i);
		getans();
		printf("Case #%d: %s %s\n", tt, d1, d2);
	}
	return 0;
}
