#include <cstdio>
#include <cmath>

const int MAX = 10020;

int table[5][5] = {
	0, 0, 0, 0, 0,
	0, 1, 2, 3, 4,
	0, 2, -1, 4, -3,
	0, 3, -4, -1, 2,
	0, 4, 3, -2, -1
};

int len, dup;
char data[MAX];

int cross(int f, int s) {
	bool minus = (f < 0) ^ (s < 0);

	f = abs(f);
	s = abs(s);

	return minus ? -table[f][s] : table[f][s];
}

int ijkToNum(char t) {
	if (t == 'i') return 2;
	if (t == 'j') return 3;
	if (t == 'k') return 4;
	return 0;
}

int calc() {
	int ans = 1, i;
	for (i = 0; i < len; i++) {
		ans = cross(ans, ijkToNum(data[i]));
	}

	return ans;
}

int findRight(int left, int result) {
	int i;
	for (i = 1; i <= 4; i++) {
		if (cross(left, i) == result) return i;
	}

	for (i = -1; i >= -4; i--) {
		if (cross(left, i) == result) return i;
	}

	return 0;
}

int findLeft(int right, int result) {
	int i;
	for (i = 1; i <= 4; i++) {
		if (cross(i, right) == result) return i;
	}

	for (i = -1; i >= -4; i--) {
		if (cross(i, right) == result) return i;
	}

	return 0;
}

int findPrefix(int target) {
	if (target == 1) return 1;

	int i, current = 1;
	for (i = 0; i < len; i++) {
		current = cross(current, ijkToNum(data[i]));

		if (current == target) return i;
	}
	
	return -1;
}

int findSuffix(int target) {
	if (target == 1) return 1;

	int i, current = 1;
	for (i = len-1; i >= 0; i--) {
		current = cross(ijkToNum(data[i]), current);

		if (current == target) return i;
	}

	return -1;
}

int main() {
	freopen("C-small.out", "w", stdout);

	int numCase, nowCase;
	scanf("%d", &numCase);

	for (nowCase = 1; nowCase <= numCase; nowCase++) {
		scanf("%d%d%s", &len, &dup, data);

		int all[4];
		all[0] = 1;
		all[1] = calc();
		all[2] = cross(all[1], all[1]);
		all[3] = cross(all[1], all[2]);

		bool ans = 0;
		if (all[dup%4] != -1)
			goto skip;

		int i, j, k;
		for (i = 0; i < 4; i++) {
			for (k = 0; k < 4; k++) {
				int prefix, suffix;
				prefix = findRight(all[i], 2);
				suffix = findLeft(all[k], 4);

				int pIndex = findPrefix(prefix);
				int sIndex = findSuffix(suffix);

				if (pIndex != -1 && sIndex != -1) {
					if (pIndex < sIndex ? i+k+1 <= dup : i+k+2 <= dup) {
						ans = 1;
						goto skip;
					}
				}
			}
		}

	skip:
		printf("Case #%d: %s\n", nowCase, ans ? "YES" : "NO");
	}

	return 0;
}