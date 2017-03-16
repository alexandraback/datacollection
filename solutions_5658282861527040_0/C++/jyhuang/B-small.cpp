#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int T;

	scanf("%d", &T);
	for (int ti = 1; ti <= T; ti++) {
		int a, b, k, ans = 0;
		scanf("%d %d %d\n", &a, &b, &k);
		for (int i = 0; i < a; i++)
			for (int j = 0; j < b; j++)
				if ((i & j) < k) ans++;
		printf("Case #%d: %d\n", ti, ans);
	}

	return 0;
}
