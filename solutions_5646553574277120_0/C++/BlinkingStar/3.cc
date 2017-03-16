#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int c, d, v;
int memo[100][30];
int Solve(int index, int value, vector<int>& coins) {
	if (value < 0) return 0;
	if (coins[index] == value) return 1;
	int &ret = memo[index][value];
	if (ret != -1) return ret;

	for (int next = index+1; next < coins.size(); ++next) {
		ret = max (ret, Solve(next, value - coins[index], coins));
		if (ret == 1) return 1;
	}
	return ret = 0;
}

int main() {
	int testNum;
	cin >> testNum;
	int caseNum = 0;
	while (++caseNum <= testNum) {
		cin >> c >> d >> v;
		memset(memo, -1, sizeof(memo));
		vector<int> coins;
		for (int i=0; i<d; ++i) {
			int temp;
			cin >> temp;
			coins.push_back(temp);
		}

		for (int value=1; value<=v; value *= 2) {
			int x = 0;
			for (int i=0; i<coins.size(); ++i)
				x = max(x, Solve(i, value, coins));
			if (x == 0)
				coins.push_back(value);

		}
		printf("Case #%d: %d\n",caseNum, coins.size() - d);
	}
	return 0;
}






