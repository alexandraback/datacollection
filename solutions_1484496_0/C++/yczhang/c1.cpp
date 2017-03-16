#include <cstdio>
#include <map>
using namespace std;

map<int, int> hash;

int a[50];
int N;

int calc(int x) {
	int S = 0;
	for (int i = 0; i < N; i++)
		if (x & (1 << i)) {
			S += a[i];
		}

	return S;
}

void print(int x) {
	bool fst = true;
	for (int i = 0; i < N; i++)
		if (x & (1 << i)) {
			if (!fst) printf(" ");
			fst = false;
			printf("%d", a[i]);
		}

	printf("\n");
}

void solve() {
	hash.clear();
	for (int i = 0; i < (1 << N); i++) {
		int S = calc(i);
		if (hash.find(S) == hash.end()) {
			hash[S] = i;
		} else {
			print(hash[S]);
			print(i);
			return;
		}
	}

	printf("Impossible\n");
}

int main() {
	int T; scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		printf("Case #%d:\n", i+1);
		
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%d", &a[i]);
		solve();
	}

	return 0;
}
