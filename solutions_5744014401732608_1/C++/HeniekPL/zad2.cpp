#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const int B_MAX = 50;
const long long int M_MAX = 1000000000000000000; 

vector<long long int> potega;
int G[B_MAX][B_MAX];
int B;
long long int M;

int znajdz_pot() {
	int id = upper_bound(potega.begin(), potega.end(), M) - potega.begin();
	return id - 1;
}

void build_graph(int x) {
	for (int i = 0; i < B; ++i) {
		for (int j = 0; j < B; ++j)
			G[i][j] = 0;
	}
	int n = x + 2;
	for (int i = B - 1; i >= B-n; --i) {
		for (int j = i + 1; j < B; ++j) {
			G[i][j] = 1;
		}
	}
	if (potega[x] <= M) {
		G[0][B - n] = 1;
		int j = 0;
		long long int p = potega[x];
		long long int r = M - p;
		long long int p2 = 1;
		while (r > 0) {
			if (r & p2) {
				G[0][B - 2 - j] = 1;
				r -= p2;
			}
			p2 *= 2;
			j++;
		}
	}
	G[0][0] = 0;

}

int main() {
	int T;
	scanf("%d", &T);
	potega.push_back(1);
	int ile = 0;
	while (potega[ile] < M_MAX) {
		potega.push_back(2*potega[ile]);
		ile++;
	}
	for (int t = 1; t <= T; ++t) {
		scanf("%d %lld", &B, &M);
		printf("Case #%d: ", t);
		if (potega[B - 2] < M) {
			printf("IMPOSSIBLE\n");// %lld %lld < %lld\n", B, potega[B-2], M);
			continue;
		}
		build_graph(znajdz_pot());
		printf("POSSIBLE\n");// %lld %lld\n", B, M);
		for (int i = 0; i < B; ++i) {
			for (int j = 0; j < B; ++j) {
				printf("%d", G[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}