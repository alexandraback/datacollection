#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> TIntVector;

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	// freopen("C-small-attempt0.in", "r", stdin);
	// freopen("C-small-attempt0.out", "w", stdout);

	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int iTest = 0; iTest < n; ++iTest) {
		fprintf(stderr, "%d\n", iTest);
		int a, b;
		scanf("%d%d", &a, &b);
		__int64 res = 0;
		for (int n = a; n <= b; ++n) {
			char line[1000];
			sprintf(line, "%d", n);
			size_t len = strlen(line);
			TIntVector used;
			for (size_t i = 1; i < len; ++i) {
				int m = 0;
				for (size_t j = 0; j < len; ++j)
					m = 10*m + (line[ (i + j) % len ] - '0');
				if (m > n && m <= b && find(used.begin(), used.end(), m) == used.end()) {
					used.push_back(m);
					++res;
				}
			}
		}
		printf("Case #%d: %lld\n", iTest + 1, res);
	}
	
	return 0;
}