#include <stdio.h>

int main() {
	int ecase, ecount;
	int eb[101][101];
	int er, ec;

	scanf("%d", &ecase);
	for (ecount = 1; ecount <= ecase; ecount++) {
		scanf("%d%d", &er, &ec);
		for (int i = 0; i < er; i++)
			for (int j = 0; j < ec; j++)
				scanf("%d", &eb[i][j]);

		bool ans = true;
		for (int i = 0; i < er && ans; i++)
			for (int j = 0; j < ec && ans; j++) {
				bool success = false;
				int k;
				for (k = 0; k < er; k++)
					if (eb[k][j] > eb[i][j])
						break;
				if (k == er)
					success = true;

				for (k = 0; k < ec; k++)
					if (eb[i][k] > eb[i][j])
						break;
				if (k == ec)
					success = true;

				if (!success)
					ans = false;
			}

		printf("Case #%d: %s\n", ecount, (ans ? "YES" : "NO"));
	}

	return 0;
}
