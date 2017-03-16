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

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}

int getMax(int len) {
	int m = 10;
	for (int l = 1; l < len; ++l) {
		m *= 10;
	}
	return m - 1;
}

bool CanBe(int i, const string& l) {
	int maxI = getMax(l.size());
	if (i > maxI)
		return false;

	for (int p = l.size() - 1; p >= 0; --p) {
		if (l[p] != '?') {
			int num = l[p] - '0';
			int numI = i % 10;
			if (num != numI)
				return false;
		}
		i = i / 10;
	}
	return true;
}

bool CanBe(int i, int j, const string& l, const string& r) {
	return CanBe(i, l) && CanBe(j, r);
}

void BuildV(int i, vi& l) {
	for (int p = l.size() - 1; p >= 0; --p) {
		int numI = i % 10;
		i = i / 10;
		l[p] = numI;
	}
}


void BuildBest(const vector<string>& parts, vi& l, vi& r) {
	vector<int> leftCorrect(parts[0].size(), 0);
	vi rightCorrect(parts[1].size(), 0);

	for (int i = 0; i < parts[0].size(); ++i) {
		if (parts[0][i] != '?') {
			leftCorrect[i] = parts[0][i] - '0';
		}

		if (parts[1][i] != '?') {
			rightCorrect[i] = parts[1][i] - '0';
		}
	}

	l = leftCorrect;
	r = rightCorrect;

	int minDiff = 100000;

	for (int i = 0; i < 1000; ++i) {
		for (int j = 0; j < 1000; ++j) {
			if (CanBe(i, j, parts[0], parts[1])) {
				int d = abs(i - j);
				if (d < minDiff) {
					minDiff = d;
					BuildV(i, l);
					BuildV(j, r);
				}
			}
		}
	}
}


int main() {
	freopen(PROBLEM_ID".in", "r", stdin);
	freopen(PROBLEM_ID".out", "w", stdout);
	ios_base::sync_with_stdio(0);
	// getline(cin, name);
	int t;
	cin >> t;
	string s;
	getline(cin, s);

	for (int tNum = 0; tNum < t; ++tNum) {
		getline(cin, s);
		auto parts = split(s, ' ');

		vi l, r;
		BuildBest(parts, l, r);
				
		cout << "Case #" << tNum + 1 << ": ";
		for (int x : l)
			cout << x;
		cout << " ";
		for (int x : r)
			cout << x;

		cout << endl;
	}

	return 0;
}