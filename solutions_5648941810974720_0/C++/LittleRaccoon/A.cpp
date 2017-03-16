#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int f[26];
char s[2010];

char repre[10][10] = {
	"ZERO", "ONE", "TWO", "THREE", 
	"FOUR", "FIVE", "SIX", "SEVEN", 
	"EIGHT", "NINE"
};

char special[11] = "GUWXZFHOSI";
int digit[11] = {8, 4, 2, 6, 0, 5, 3, 1, 7, 9};

int res[2010], n;

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%s", s);
		memset(f, 0, sizeof(f));
		for (int i = 0; s[i]; i++) {
			f[s[i] - 'A'] += 1;
		}

		n = 0;
		for (int i = 0; i < 10; i++) {
			if (f[special[i] - 'A'] == 0) continue;

			int k = f[special[i] - 'A'];
			int d = digit[i];
			for (int j = 0; j < k; j++) {
				res[n++] = d;
			}
			for (int j = 0; repre[d][j]; j++) {
				f[repre[d][j] - 'A'] -= k;
			}
		}

		sort(res, res + n);
		printf("Case #%d: ", t);
		for (int i = 0; i < n; i++) {
			printf("%d", res[i]);
		}
		printf("\n");
	}

	return 0;
}

