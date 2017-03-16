#include <stdio.h>

char arr[51][51];

int dx[8] = {1, 0, -1, -1, -1, 0, 1, 1};
int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

int r, c, m;

bool cleared(int j, int k) {
	for (int i = 0; i < 8; i++) {
		int nx = k + dx[i];
		int ny = j + dy[i];
		if (nx >= 0 && nx < c && ny >= 0 && ny < r) {
			if (arr[ny][nx] == '.') {
				return true;
			}
		}
	}
	return false;
}

void checkCover(int j, int k) {
	for (int i = 0; i < 8; i++) {
		int nx = k + dx[i];
		int ny = j + dy[i];
		if (nx >= 0 && nx < c && ny >= 0 && ny < r) {
			if (arr[ny][nx] == '*') {
				arr[j][k] = '#';
				return;
			}
		}
	}
}

int main() {
	int t;
	scanf("%d\n", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d %d %d", &r, &c, &m);
		printf("Case #%d:\n", i);
		int cells = r * c;
		bool flip = false;
		if (r > c) {
			flip = true;
			int temp = r;
			r = c;
			c = temp;
		}
		int good = cells - m;
		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				arr[j][k] = '*';
			}
		}
		bool alrighty = true;
		if (r == 1) {
			for (int j = 0; j < good; j++) {
				arr[0][j] = '.';
			}
			goto fail;
		}
		for (int j = r; j > 1; j--) {
			if (good % j == 0 && good / j > 1) {
				for (int k = 0; k < j; k++) {
					for (int l = 0; l < (good / j); l++) {
						arr[k][l] = '.';
					}
				}
				goto fail;
			}
		}
		for (int j = r; j > 2; j--) {
			int length = good / j;
			int leftover = good % j;
			if (leftover > 0 && length == 1)
				continue;
			if (leftover != 1 && length + (leftover ? 1 : 0) <= c) {
				for (int k = 0; k < j; k++) {
					for (int l = 0; l < length + ((leftover > 0) ? 1 : 0); l++) {
						arr[k][l] = '.';
					}
					leftover--;
				}
				goto fail;
			}
		}

		alrighty = false;
		goto end;
fail:
		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				if (arr[j][k] == '.') {
					checkCover(j, k);
				}
			}
		}

		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				if (arr[j][k] == '#') {
					if (!cleared(j, k)) {
						alrighty = false;
						goto end;
					}
				}
			}
		}

		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				if (arr[j][k] == '#') {
					arr[j][k] = '.';
				}
			}
		}
end:
		if (!alrighty) {
			if (cells - m != 1) {
				printf("Impossible\n");
				continue;
			}
		}
		//printf("%d\n", m);
		if (flip) {
			int temp = r;
			r = c;
			c = temp;
		}

		arr[0][0] = 'c';
		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				if (flip)
					printf("%c", arr[k][j]);
				else
					printf("%c", arr[j][k]);
			}
			printf("\n");
		}
	}
}