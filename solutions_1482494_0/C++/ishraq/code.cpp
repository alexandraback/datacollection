#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX_N 1005

using namespace std;

struct level {
	int one, two;
};

level stars_needed[MAX_N];
bool achieved[MAX_N][2];
int n;
int num_stars;

bool win() {
	return num_stars == 2 * n;
}

int get_next() {
	for (int i = 0; i < n; i++) {
		if (achieved[i][1]) continue;
		if (stars_needed[i].two <= num_stars) {
			if (achieved[i][0]) num_stars++;
			else num_stars += 2;
			achieved[i][0] = achieved[i][1] = true;
			return 1;
		}
	}

	for (int i = 0; i < n; i++) {
		if (achieved[i][0]) continue;
		if (stars_needed[i].one <= num_stars) {
			num_stars++;
			achieved[i][0] = true;
			return 1;
		}
	}

	return 0;
}

bool lvl_srt(level a, level b) {
	return a.two - a.one > b.two - b.one;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int rayge = 1; rayge <= t; rayge++) {
		for (int i = 0; i < MAX_N; i++) achieved[i][0] = achieved[i][1] = false;
		num_stars = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &stars_needed[i].one, &stars_needed[i].two);
		}
		sort(stars_needed, stars_needed + n, lvl_srt);
		for (int i = 1;; i++) {
			int tmp = get_next();
			if (win()) {
				printf("Case #%d: %d\n", rayge, i);
				break;
			}
			if (tmp == 0) {
				printf("Case #%d: Too Bad\n", rayge);
				break;
			}
		}
	}
}
