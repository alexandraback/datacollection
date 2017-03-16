// Problem B. Close Match
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
	int T;
	scanf("%d", &T);
	for (int ti = 1; ti <= T; ti++) {
		char s1[32], s2[32], ans1[32], ans2[32], t1[32], t2[32];
		scanf("%s %s", s1, s2);
		int len = strlen(s1);
		int m = 1, ans = 999999;
		for (int i = 0; i < len; i++) m *= 10;

		for (int i = 0; i < m; i++) {
			sprintf(t1, "%0*d", len, i);
			bool ok = true;
			for (int k = 0; k < len; k++)
				if (s1[k] != '?' && s1[k] != t1[k]) ok = false;
			if (!ok) continue;
			for (int j = 0; j < m; j++) {
				int v = abs(i - j);
				if (abs(i - j) > ans) continue;
				sprintf(t2, "%0*d", len, j);
				bool ok = true;
				for (int k = 0; k < len; k++)
					if (s2[k] != '?' && s2[k] != t2[k]) ok = false;
				if (!ok) continue;
				if (v < ans) {
					ans = v;
					strcpy(ans1, t1);
					strcpy(ans2, t2);
				}
			}
		}



		printf("Case #%d: %s %s\n", ti, ans1, ans2);
	}

	return 0;
}
