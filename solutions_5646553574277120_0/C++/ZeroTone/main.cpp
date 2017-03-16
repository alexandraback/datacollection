#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;

struct TestCase {
	int repeats, v;
	vector<int> coins;
};

std::vector<TestCase> load(const std::string& fname) {
	std::ifstream fp(fname);
	std::vector<TestCase> res;
	int cases;
	fp >> cases;
	for (int i = 0; i < cases; i++) {
		TestCase c;
		fp >> c.repeats;
		int n;
		fp >> n;
		fp >> c.v;
		for (int j = 0; j < n; j++) {
			int coin;
			fp >> coin;
			c.coins.push_back(coin);
		}
		res.push_back(c);
	}
	return res;
}

bool sums(const vector<int>& coins, int target) {
	for (int i = 0; i < coins.size(); i++) {
		int sum = 0;
		for (int j = i; j < coins.size(); j++) {
			sum += coins[j];
			if (sum == target)
				return true;
		}
	}
	return false;
}

int solve(TestCase& cs) {
	vector<int> coins = cs.coins;
	sort(coins.begin(), coins.end());
	int added = 0;
	for (int i = 1; i <= cs.v; i++) {
		if (!sums(coins, i)) {
			for (int j = 0; j < coins.size(); j++) {
				if (j + 1 != coins[j]) {
					coins.push_back(j + 1);
					++added;
					sort(coins.begin(), coins.end());
					break;
				}
			}
		}
	}
	return added;
}

int main(int argc, const char *argv[]) {
	auto cases = load("C-small-attempt0.in");
	std::ofstream fp("C-small-attempt0.out");
	int i = 1;
	for (auto it = cases.begin(); it != cases.end(); ++it, ++i) {
		int r = solve(*it);
		fp << "Case #" << i << ": " << r << std::endl;
	}

	return 0;
}

