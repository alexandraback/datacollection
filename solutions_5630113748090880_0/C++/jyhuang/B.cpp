// Problem B. Rank and File
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int T;
	scanf("%d", &T);
	for (int ti = 1; ti <= T; ti++) {
		int n, t;
		vector<int> a(2501);
		scanf("%d", &n);
		for (int i = 0; i < n * 2 - 1; i++)
			for (int j = 0; j < n; j++) {
				scanf("%d", &t);
				a[t]++;
			}

		printf("Case #%d:", ti);
		for (int i = 1; i < a.size(); i++)
			if (a[i] != 0 && a[i] % 2 == 1) printf(" %d", i);
		printf("\n");
	}

	return 0;
}
