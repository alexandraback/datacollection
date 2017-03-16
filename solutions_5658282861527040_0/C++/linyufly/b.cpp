#include <cstdio>

#include <vector>
#include <algorithm>

typedef long long Int64;

int A, B, K;

Int64 GetHighest(Int64 a) {
	if (!a) return 0;
	Int64 res = 1;
	for (; res * 2 <= a; res *= 2);
	return res;
}

Int64 CountBits(Int64 a) {
	if (!a) return 0;
	return CountBits(a / 2) + (a % 2);
}

Int64 CountSatisfaction(Int64 base, Int64 pattern) {
	//printf("%I64d %I64d\n", base, pattern);

	if (base < pattern) return 0;
	if (base == pattern) return 1;
	Int64 baseHigh = GetHighest(base);
	Int64 patternHigh = GetHighest(pattern);
	if (baseHigh == patternHigh) return CountSatisfaction(base - baseHigh, pattern - patternHigh);
	// baseHigh > patternHigh
	Int64 freeStyle = 1LL << (CountBits(baseHigh - 1) - CountBits(pattern));
	return freeStyle + CountSatisfaction(base - baseHigh, pattern);
}

std::vector<Int64> candidates;

void GenerateCandidates(Int64 prefix, Int64 residual) {
	if (!residual) {
		candidates.push_back(prefix);
		return;
	}
	Int64 high = GetHighest(residual);
	prefix += high;
	residual -= high;
	for (high /= 2; high > residual; high /= 2)
		candidates.push_back(prefix + high);
	GenerateCandidates(prefix, residual);
}

void Solve() {
	scanf("%d %d %d", &A, &B, &K);
	Int64 highestBit = std::max(GetHighest(A), GetHighest(B));
	Int64 res = 0;
	candidates.clear();

	//printf("here1\n");

	for (Int64 bit = highestBit; bit >= K; bit /= 2) {
		//printf("%I64d\n", bit);
		candidates.push_back(bit);
	}

	//printf("here\n");

	GenerateCandidates(0, K);
	for (int i = 1; i < (1 << candidates.size()); i++) {
		Int64 pattern = 0;
		int cnt = -1;
		for (int j = 0; j < candidates.size(); j++)
			if ((1 << j) & i) {
				pattern |= candidates[j];
				cnt = -cnt;
			}
		res += cnt * CountSatisfaction(A - 1, pattern) * CountSatisfaction(B - 1, pattern);
	}
	printf("%I64d\n", A * B - res);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		Solve();
	}
	return 0;
}