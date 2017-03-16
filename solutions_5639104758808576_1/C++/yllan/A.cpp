#include <cstdio>

using namespace std;

#define MAX 10000

int solve(int s_max, char *buf)
{
	int ovationed = buf[0];
	int require = 0;

	for (int i = 1; i <= s_max; i++) {

		if (buf[i] > 0 && ovationed < i) {
			int needed = (i - ovationed);
			require += needed;
			ovationed += needed;
		}
		ovationed += buf[i];
	}

	return require;
}

int main()
{
	int t_max;
	scanf("%d", &t_max);
	for (int t = 1; t <= t_max; t++) {
		int s_max;
		char buf[MAX];
		scanf("%d %s", &s_max, buf);
		for (int i = 0; i <= s_max; i++) buf[i] -= '0';
		printf("Case #%d: %d\n", t, solve(s_max, buf));
	}
}