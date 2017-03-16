#include <stdio.h>
#include <string.h>

#define INF 1000000000000000000LL

char a[25], b[25];
int n;
long long dy[25][4];
int path[25][4][3];

long long l_abs(long long x)
{
	if (x < 0) return -x;
	return x;
}

void update_path(int i,int j, int t1, int t2, int t3)
{
	path[i][j][0] = t1;
	path[i][j][1] = t2;
	path[i][j][2] = t3;
}

void get_ans(long long &x, long long &y, int t)
{
	x = 0;
	y = 0;

	for (int i = 1; i <= n; i++) {
		x = x * 10 + path[i][t][0];
		y = y * 10 + path[i][t][1];
		t = path[i][t][2];
	}
}

void print_ans(long long x, long long y)
{
	char tmp[20];
	sprintf(tmp, "%%0%dlld %%0%dlld\n",n,n);
	printf(tmp, x, y);
}

void process()
{
	scanf(" %s %s", &a[1], &b[1]);
	n = strlen(&a[1]);
	long long t = 1;


	for (int i = 1; i <= n; i++) {
		dy[i][0] = INF;
		dy[i][1] = -INF;
		dy[i][2] = INF;
		dy[i][3] = -INF;
	}

	dy[n + 1][0] = dy[n + 1][1] = dy[n + 1][2] = dy[n + 1][3] = 0;

	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < 10; j++) {
			if (a[i] != '?' && a[i] - '0' != j) continue;
			for (int k = 0; k < 10; k++) {
				if (b[i] != '?' && b[i] - '0' != k) continue;

				long long tmp = (j - k)*t;

				if (dy[i][0] > tmp + dy[i + 1][0]) {
					dy[i][0] = tmp + dy[i + 1][0];
					update_path(i, 0, j, k, 0);
				}

				if (tmp == 0) { 
					if (dy[i][1] < dy[i + 1][1]) {
						dy[i][1] = dy[i + 1][1];
						update_path(i, 1, j, k, 1);
					}
				}
				else if (tmp < 0) {
					if (dy[i][1] < tmp + dy[i + 1][3]) {
						dy[i][1] = tmp + dy[i + 1][3];
						update_path(i, 1, j, k, 3);
					}
				}

				if (tmp == 0) {
					if (dy[i][2] > dy[i + 1][2]) {
						dy[i][2] = dy[i + 1][2];
						update_path(i, 2, j, k, 2);
					}
				}
				else if (tmp > 0) {
					if (dy[i][2] > tmp + dy[i + 1][0]) {
						dy[i][2] = tmp + dy[i + 1][0];
						update_path(i, 2, j, k, 0);
					}
				}

				if (dy[i][3] < tmp + dy[i + 1][3]) {
					dy[i][3] = tmp + dy[i + 1][3];
					update_path(i, 3, j, k, 3);
				}
			}
		}
		t *= 10;
	}


	long long a1, b1, a2, b2;
	get_ans(a1, b1, 1);
	get_ans(a2, b2, 2);

	if (l_abs(dy[1][1]) < l_abs(dy[1][2])) print_ans(a1, b1);

	else if (l_abs(dy[1][1]) > l_abs(dy[1][2])) print_ans(a2, b2);

	else {
		if (a1 < a2 || a1 == a2 && b1 < b2) print_ans(a1, b1);
		else print_ans(a2, b2);
	}
}

int main()
{
	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		process();
	}
}