#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int ntests;
int m, n;
int line[110], column[110];
int h[110][110];

int main() {
	scanf("%d", &ntests);
	for (int test = 1; test <= ntests; test++) {
		scanf("%d %d", &n, &m);
		
		memset(line, 0, sizeof(line));
		memset(column, 0, sizeof(column));
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &h[i][j]);
				line[i] = max(line[i], h[i][j]);
				column[j] = max(column[j], h[i][j]);
			}
		}
		
		bool correct = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (h[i][j] != min(line[i], column[j])) {
					correct = false;
				}
			}
		}
		
		printf("Case #%d: ", test);
		if (correct) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}
