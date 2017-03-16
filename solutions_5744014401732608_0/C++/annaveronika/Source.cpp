#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <complex>
#include <time.h>
#include <functional>

#define M_PI           3.14159265358979323846

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define PROBLEM_ID "1"

#pragma comment(linker, "/STACK:56777216")


typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

void Fill(vvi& ans) {
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = i + 1; j + 1 < ans.size(); ++j) {
			ans[i][j] = 1;
		}
	}
	ans[0].back() = 1;
}

void Fill1(vvi& ans, const vi& deg) {
	for (int d = 0; d < deg.size(); ++d) {
		if (deg[d] == 1) {
			ans[d + 1].back() = 1;
		}
	}
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}

vi GetD(ull m) {
	vi ans;
	while (m != 0) {
		if (m % 2 != 0) {
			ans.push_back(1);
		}
		else {
			ans.push_back(0);
		}
		m /= 2;
	}
	return ans;
}

int main() {
	freopen(PROBLEM_ID".in", "r", stdin);
	freopen(PROBLEM_ID".out", "w", stdout);
	ios_base::sync_with_stdio(0);
	// getline(cin, name);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int b;
		ull m;
		cin >> b >> m;
		
		bool poss = false;
		vvi ans(b, vi(b));

		if (m > ((ull)(1) << (b - 1))) {
			poss = false;
		}
		else {
			poss = true;
			m -= 1;
			vi deg = GetD(m);
			Fill(ans);
			Fill1(ans, deg);
		}


		cout << "Case #" << i + 1 << ": ";
		if (!poss) {
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			cout << "POSSIBLE" << endl;
			for (int i = 0; i < ans.size(); ++i) {
				for (int j = 0; j < ans.size(); ++j) {
					cout << ans[i][j] << " ";
				}
				cout << endl;
			}
		}
	}

	return 0;
}