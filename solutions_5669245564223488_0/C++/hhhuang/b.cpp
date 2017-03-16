#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char sets[120][120];
int visited[120];
char ans[12000];
int size;

int check(char *str, int len) {
	if (len == 0)
		return 1;
	static char shown[26];
	memset(shown, 0, sizeof(shown));
	for (int i = 0; i < len; ++i) {
		if (i > 0 && str[i] != str[i - 1]) {
			if (shown[str[i] - 'a'])
				return 0;
		}
		shown[str[i] - 'a'] = 1;
	}
	return 1;
}

long long int dfs(int dep, int len) {
	if (dep >= size) {
		return 1;
	}
	long long int sum = 0;
	for (int i = 0; i < size; ++i) {
		if (visited[i])
			continue;
		strcpy(ans + len, sets[i]);
		if (!check(ans, len + strlen(sets[i])))
			continue;
		visited[i] = 1;
		sum += dfs(dep + 1, len + strlen(sets[i]));
		visited[i] = 0;
	}
	return sum;
} 

void run() {
	scanf("%d", &size);
	for (int i = 0; i < size; ++i) {
		scanf("%s", sets[i]);
		visited[i] = 0;
	}
	printf("%lld\n", dfs(0, 0));

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

