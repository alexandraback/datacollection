#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cstring>
using namespace std;

#define MK(a,b,c) (1 << ((a) + 3 * (b) + 9 * (c)))

int JP[16][16], JS[16][16], PS[16][16];

void solve()
{
	static int casenr = 1;
	printf("Case #%d: ", casenr++);

	int J, P, S, K; scanf("%d%d%d%d", &J, &P, &S, &K);

	int best = 0, bestx;
	
	int nope = 0;
	for (int j = J; j < 3; ++j) {
		for (int p = 0; p < 3; ++p) {
			for (int s = 0; s < 3; ++s) {
				nope |= MK(j, p, s);
			}
		}
	}
	for (int p = P; p < 3; ++p) {
		for (int j = 0; j < 3; ++j) {
			for (int s = 0; s < 3; ++s) {
				nope |= MK(j, p, s);
			}
		}
	}
	for (int s = S; s < 3; ++s) {
		for (int j = 0; j < 3; ++j) {
			for (int p = 0; p < 3; ++p) {
				nope |= MK(j, p, s);
			}
		}
	}
	
	//const int C1 = MK(0, 0, 0); // always 1
	const int C2 = MK(1, 1, 1);
	const int C3 = MK(2, 2, 2);
	const int MAX = (1<<27);
	for (int x = 1; x < MAX; x += 2) {
		if ((x & nope) != 0) { continue; }
		if (J > 1 && (x & C2) == 0) { continue; }
		if (J > 2 && (x & C3) == 0) { continue; }
		bool ok = true;
		memset(JP, 0, sizeof(JP));
		memset(JS, 0, sizeof(JS));
		memset(PS, 0, sizeof(PS));
		int cur = 0;
		for (int j = 0; ok && j < J; ++j) {
			for (int p = 0; ok && p < P; ++p) {
				if (JP[j][p] >= K) { continue; }
				for (int s = 0; ok && s < S; ++s) {
					int pt = MK(j, p, s);
					if ((x & pt) == 0) { continue; }
					if (JS[j][s] >= K) { ok = false; break; }
					if (PS[p][s] >= K) { ok = false; break; }
					cur += 1;
					JS[j][s] += 1;
					PS[p][s] += 1;
					if (++JP[j][p] >= K) { break; }
				}
			}
		}
		if (cur > best) {
			best = cur;
			bestx = x;
		}
	}
	printf("%d\n", best);
	for (int j = 0; j < J; ++j) {
		for (int p = 0; p < P; ++p) {
			for (int s = 0; s < S; ++s) {
				int pt = MK(j, p, s);
				if ((bestx & pt) == 0) { continue; }
				printf("%d %d %d\n", j + 1, p + 1, s + 1);
			}
		}
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T-- > 0) {
		solve();
	}
	return 0;
}
