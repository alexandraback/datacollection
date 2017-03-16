#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <vector>
#include <set>

using namespace std;

void init();
void runCase();

int main()
{
	init();

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		printf("Case #%d: ", t);
		runCase();
	}
}

// algorithms
int C, D, V;
vector<int> coins;
bool covers[31];

int cand[31];
int candSize;

int issuedSet[31];

void init() {
}

bool isAllCovered(bool tests[])
{
	for (int i = 1; i <= V; i++) {
		if (!tests[i]) {
			return false;
		}
	}
	return true;
}

void checkAll(int val, int depth)
{
	if (val > V) {
		return;
	}
	if (depth == D) {
		covers[val] = true;
		return;
	}
	checkAll(val, depth + 1);
	checkAll(val + coins[depth], depth + 1);
}

bool mergeIssued(int issuedSize)
{
	bool tests[31];
	for (int i = 0; i <= V; i++) {
		tests[i] = covers[i];
	}
	for (int i = 0; i < issuedSize; i++) {
		int coin = issuedSet[i];
		for (int j = V - coin; j >= 0; j--) {
			tests[j + coin] |= tests[j];
		}
	}
	return isAllCovered(tests);
}

bool issueCoins(int issuedSize, int candSize, int remainK, int index)
{
	if (remainK == 0) {
		return mergeIssued(issuedSize);
	}
	else if (remainK > candSize - index) {
		return false;
	}
	else {
		issuedSet[issuedSize] = cand[index];
		if (issueCoins(issuedSize + 1, candSize, remainK - 1, index + 1)) {
			return true;
		}
		return issueCoins(issuedSize, candSize, remainK, index + 1);
	}
}

bool possible(int need)
{
	if (need == 0) {
		return isAllCovered(covers);
	}
	return issueCoins(0, candSize, need, 0);
}

void runCase()
{
	int precalc = 0;
	scanf("%d %d %d", &C, &D, &V);
	coins.clear();
	coins.reserve(D);
	for (int i = 0; i < D; i++) {
		int val;
		scanf("%d", &val);
		coins.push_back(val);
	}
	if (coins[0] != 1) {
		coins.push_back(1);
		D++;
		precalc++;
	}
	if (V > 1 && (coins[0] != 2 && (D > 1 && coins[1] != 2))) {
		coins.push_back(2);
		D++;
		precalc++;
	}
	sort(coins.begin(), coins.end());
	covers[0] = true;
	for (int i = 1; i <= V; i++) {
		covers[i] = false;
	}

	checkAll(0, 0);

	int idx = 0;
	int last = 1;
	for (int i = 0; i < coins.size(); i++) {
		int coin = coins[i];
		while (last < coin) {
			cand[idx] = last;
			idx++;
			last++;
		}
		last = coin + 1;
	}
	while (last <= V) {
		cand[idx] = last;
		idx++;
		last++;
	}
	candSize = idx;

	for (int i = 0; i <= candSize; i++) {
		if (possible(i)) {
			printf("%d\n", i + precalc);
			return;
		}
	}
}
