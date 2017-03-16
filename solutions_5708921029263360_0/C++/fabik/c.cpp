#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

typedef long long ll;

using namespace std;

struct Outfit {
	int a, b, c;
};

int A, B, C, K;
vector<Outfit> outfits;
int O, ans, ans_mask;

int ab[4][4];
int ac[4][4];
int bc[4][4];

void dfs(int mask, int count, int last)
{
	if (count > ans) {
		ans = count;
		ans_mask = mask;
	}

	for (int i = last+1; i < O; i++) {
		if (mask & (1<<i)) {
			continue;
		}

		Outfit o = outfits[i];
		int a = o.a, b = o.b, c = o.c;

		if (ab[a][b] == K || ac[a][c] == K || bc[b][c] == K) {
			continue;
		}

		ab[a][b]++;
		ac[a][c]++;
		bc[b][c]++;
		dfs(mask | (1<<i), count+1, i);
		ab[a][b]--;
		ac[a][c]--;
		bc[b][c]--;
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d%d%d", &A, &B, &C, &K);

		outfits.clear();
		for (int a = 0; a < A; a++) {
			for (int b = 0; b < B; b++) {
				for (int c = 0; c < C; c++) {
					outfits.push_back((Outfit) { a, b, c });
				}
			}
		}
		O = outfits.size();

		ans = 0;
		ans_mask = 0;
		memset(ab, 0, sizeof(ab));
		memset(ac, 0, sizeof(ac));
		memset(bc, 0, sizeof(bc));

		ab[0][0] = 1;
		ac[0][0] = 1;
		bc[0][0] = 1;
		dfs(1, 1, 0);

		printf("Case #%d: %d\n", t, ans);

		for (int i = 0; i < O; i++) {
			if (!(ans_mask & (1<<i))) {
				continue;
			}

			Outfit o = outfits[i];
			printf("%d %d %d\n", o.a+1, o.b+1, o.c+1);
		}
	}
	return 0;
}
