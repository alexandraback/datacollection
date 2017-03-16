#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int m, n;
int map[60][60];
char cities[60][6];
int order[60];
int visited[60];
char ans[500];
char best[500];

int cmp(const void *a, const void *b) {
	return strcmp((char *)a, (char *)b);
}

int DFS(int current, int num_visited, int num_cities) {
	if (num_visited > 0 && strcmp(best, "A") != 0 && strncmp(ans, best, num_visited * 5) >= 0)
		return 0;
//	printf("%d %d %s\n", current, num_visited, ans);
	if (num_visited >= num_cities) {
		if (strncmp(ans, best, num_cities * 5) < 0) {
			strncpy(best, ans, num_cities * 5);
		}
		return 1;
	}
	for (int i = 1; i <= n; ++i) {
		if (map[current][i] == 1 && visited[i] == 0) {
			visited[i] = 1;
			strncpy(ans + num_visited * 5, cities[i], 5);
			ans[(num_visited + 1) * 5] = 0;
			DFS(i, num_visited + 1, num_cities);
			ans[num_visited * 5] = 0;
			visited[i] = 0;
		}
		else if (map[i][current] == 1 && visited[i] == 1) {
			visited[i] = 2;
			DFS(i, num_visited, num_cities);
			visited[i] = 1;
		}
	}
}

void run() {
	memset(visited, 0, sizeof(visited));
	memset(map, 0, sizeof(map));
	strcpy(best, "A");
	scanf("%d%d", &n, &m);
	char tmp[60][6];
	int v1, v2;
	
	for (int i = 1; i <= n; ++i) {
		scanf("%s", cities[i]);
		strcpy(tmp[i], cities[i]);
		map[0][i] = 1;
	}
	for (int j = 0; j < m; ++j) {
		scanf("%d%d", &v1, &v2);
		map[v1][v2] = 1;
		map[v2][v1] = 1;
	}
	qsort(tmp + 1, n, sizeof(tmp[0]), cmp);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (strcmp(tmp[i], cities[j]) == 0)
				order[i] = j;
		}
	}
	DFS(0, 0, n);
	best[n * 5] = 0;
	puts(best);
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);
    for (int t = 1; t <= num_cases; ++t) {
        printf("Case #%d: ", t);
        run();
    }
    return 0;
}

