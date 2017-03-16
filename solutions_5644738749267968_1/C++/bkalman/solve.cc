#include <cstdio>
#include <vector>
#include <algorithm>

using std::scanf;
using std::printf;
using std::vector;

static int war(int N, const vector<int>& naomi, const vector<int>& ken) {
	int k = N - 1;
	for(int n = N - 1; n >= 0; --n)
		if(naomi[n] < ken[k])
			--k;
	return k + 1;
}

static int deceitful_war(int N, const vector<int>& naomi, const vector<int>& ken) {
	int k = 0;
	for(int n = 0; n < N; ++n)
		if(ken[k] < naomi[n])
			++k;
	return k;
}

static vector<int> load_blocks(int N) {
	vector<int> blocks(N);
	for(int i = 0; i < N; ++i) {
		double b;
		scanf("%lf", &b);
		blocks[i] = b * 100000;
	}
	return blocks;
}

static void testcase(int t) {
	int N;
	scanf("%i", &N);
	vector<int> naomi = load_blocks(N);
	vector<int> ken = load_blocks(N);
	sort(naomi.begin(), naomi.end());
	sort(ken.begin(), ken.end());
	printf("Case #%d: %d %d\n", t, deceitful_war(N, naomi, ken), war(N, naomi, ken));
}

int main() {
	int T;
	scanf("%i", &T);
	for(int t = 1; t <= T; ++t)
		testcase(t);
}
