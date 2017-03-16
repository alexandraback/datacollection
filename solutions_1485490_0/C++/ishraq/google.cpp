#include <cstdio>

#define MAX_N 5
#define MAX_M 105

using namespace std;

typedef unsigned long long ull;

int n, m;

ull toys[MAX_N][2];
ull boxes[MAX_M][2];

ull max(ull a, ull b) {
	if (a < b) return b;
	else return a;
}

ull min(ull a, ull b) {
	if (a > b) return b;
	else return a;
}

ull most_boxes(int toy, int box, ull num_left) {
	if (toy == n || box == m) return 0;
	if (num_left < 0)
		printf("%llu\n", num_left);
	if (toys[toy][0] == boxes[box][0]) {
		ull can_use = min(min(num_left, toys[toy][1]), boxes[box][1]);
		return max(most_boxes(toy+1, box, toys[toy+1][1]), most_boxes(toy, box+1, num_left-can_use)) + can_use;
	} else {
		return max(most_boxes(toy+1, box, toys[toy+1][1]), most_boxes(toy, box+1, num_left));
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int rayge = 1; rayge <= T; rayge++) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%llu %llu", &toys[i][1], &toys[i][0]);
		}
		for (int i = 0; i < m; i++) {
			scanf("%llu %llu", &boxes[i][1], &boxes[i][0]);
		}
		printf("Case #%d: %llu\n", rayge, most_boxes(0, 0, toys[0][1]));
	}
}
