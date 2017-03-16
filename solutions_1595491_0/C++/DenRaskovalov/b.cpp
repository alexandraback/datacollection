#include <cstdio>

#include <vector>
#include <numeric>

using namespace std;

typedef vector<int> TIntVector;
typedef vector<bool> TBoolVector;

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);

	// freopen("B-large.in", "r", stdin);
	// freopen("B-large.out", "w", stdout);
	
	int t;
	scanf("%d", &t);
	
	for (int iTest = 0; iTest < t; ++iTest) {
		int n, s, p;
		scanf("%d%d%d", &n, &s, &p);

		TIntVector points(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &points[i]);

		const int limit1 = p + max(p - 1, 0) + max(p - 1, 0);
		const int limit2 = p + max(p - 2, 0) + max(p - 2, 0);

		int res = 0;
		TBoolVector used(n);
		for (int i = 0; i < n; ++i)
			if (points[i] >= limit1) {
				++res;
				used[i] = true;
			}

		for (int i = 0; i < n && s > 0; ++i) {
			if (!used[i] && points[i] >= limit2) {
				++res;				
				--s;
			}
		}

		printf("Case #%d: %d\n", iTest + 1, res);
	}

	return 0;
}