#include <cstdlib>

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

#include <limits>
#include <exception>

#include <cmath>
#include <cstring>
#include <cassert>
#include <ctime>

#include <string>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <list>

#define ALL(container) (container).begin(), (container).end()
#define MP std::make_pair
#define SZ(x) int((x).size())

#define X first
#define Y second

typedef long long i64;
typedef unsigned long long u64;

typedef std::pair<int, int> pii;

template<typename t>
inline t sqr(const t x) {
	return x * x;
}

template<typename A, typename B>
A convert(const B &x) {
	A res;
	std::stringstream ss;
	ss << x;
	ss >> res;
	return res;
}

#define FILE_NAME "test"
std::ifstream fin(FILE_NAME ".in");
std::ofstream fout(FILE_NAME ".out");

int main() {
	assert(fin && fout);
	std::ios_base::sync_with_stdio(false);

	int testsCnt;
	fin >> testsCnt;
	for (int testIdx = 1; testIdx <= testsCnt; ++testIdx) {
		double c, f, x;
		fin >> c >> f >> x;

		double tmp = .0, prev_ans = x / 2;
		for (int i = 1;; ++i) {
			tmp += c / (2 + (i - 1) * f);
			double ans = tmp + x / (2 + i * f);
			if (ans >= prev_ans) {
				//std::cout << i << '\n';
				break;
			}

			prev_ans = ans;
		}

		fout << "Case #" << testIdx << ": " << std::fixed << std::setprecision(7);
		fout << prev_ans << "\n";
	}

	return 0;
}
