#include <cstdio>
#include <cstring>
#include <set>
#include <utility>

using namespace std;

typedef pair<int,int> PII;

set<PII> strs;
char L[10000001];
int n;

bool isVowel(char c) {
	if (c <= 'Z') {
		c += 'a' - 'A';
	}
	switch(c) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return true;
		default:
			return false;
	}
}

void getStrs(int a, int b) {
	fprintf(stderr, "Found String at %d %d\n", a, b);
	for (int i = 0; i <= a; ++i) {
		for (int j = b-1; j < strlen(L); ++j) {
			strs.insert(PII(i,j));
		}
	}
}

int main(int argc, char const *argv[]) {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t) {
		strs.clear();
		scanf("%s %d", L, &n);

		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			cnt += !isVowel(L[i]);
		}
		if (cnt == n) {
			getStrs(0, n);
		}

		for (int i = n; i < strlen(L); ++i) {
			cnt += !isVowel(L[i]);
			cnt -= !isVowel(L[i-n]);

			if (cnt == n) {
				getStrs(i+1-n, i+1);
			}
		}

		printf("Case #%d: %lu\n", t+1, strs.size());

		/* code */
	}
	return 0;
}