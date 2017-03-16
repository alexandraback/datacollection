#include <cstdio>
#include <cstring>

char nam[1000010];
int ext[1000010];
int nxt[1000010];

bool isCons(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return false;
	} else {
		return true;
	}
}

long long calc(int n) {
	int len = strlen(nam);
	ext[len] = 0;
	for (int i = len - 1; i >= 0; i--) {
		if (isCons(nam[i])) {
			ext[i] = ext[i + 1] + 1;
		} else {
			ext[i] = 0;
		}
	}
	nxt[len] = -1;
	for (int i = len - 1; i >= 0; i--) {
		if (ext[i] >= n) {
			nxt[i] = i;
		} else {
			nxt[i] = nxt[i + 1];
		}
	}
	long long ret = 0;
	for (int i = 0; i < len; i++) {
		if (nxt[i] >= 0) {
			int st = nxt[i] + n - 1;
			ret = ret + len - st;
		}
	}
	return ret;
}

int main() {
	int test;
	scanf("%d", &test);
	for (int i = 0; i < test; i++) {
		int n;
		scanf("%s%d", nam, &n);
		printf("Case #%d: %lld\n", i + 1, calc(n));
	}
}