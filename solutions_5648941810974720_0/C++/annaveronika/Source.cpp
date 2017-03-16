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

void Remove(map<char, int>& m, const string& s) {
	for (auto c : s) {
		m[c]--;
	}
}

int main() {
	freopen(PROBLEM_ID".in", "r", stdin);
	freopen(PROBLEM_ID".out", "w", stdout);
	ios_base::sync_with_stdio(0);

	map<int, string> m;
	m[0] = "ZERO";
	m[1] = "ONE";
	m[2] = "TWO";
	m[3] = "THREE";
	m[4] = "FOUR";
	m[5] = "FIVE";
	m[6] = "SIX";
	m[7] = "SEVEN";
	m[8] = "EIGHT";
	m[9] = "NINE";


	int t;
	cin >> t;
	string name;
	getline(cin, name);

	for (int i = 0; i < t; ++i) {
		getline(cin, name);
		map<char, int> num;
		for (auto c : name) {
			num[c]++;
		}

		vector<int> number;
		while (num['Z'] > 0) {
			number.push_back(0);
			Remove(num, m[0]);
		}
		while (num['W'] > 0) {
			number.push_back(2);
			Remove(num, m[2]);
		}
		while (num['U'] > 0) {
			number.push_back(4);
			Remove(num, m[4]);
		}
		while (num['X'] > 0) {
			number.push_back(6);
			Remove(num, m[6]);
		}
		while (num['O'] > 0) {
			number.push_back(1);
			Remove(num, m[1]);
		}
		while (num['S'] > 0) {
			number.push_back(7);
			Remove(num, m[7]);
		}
		while (num['N'] > 0) {
			number.push_back(9);
			Remove(num, m[9]);
		}
		while (num['V'] > 0) {
			number.push_back(5);
			Remove(num, m[5]);
		}
		while (num['R'] > 0) {
			number.push_back(3);
			Remove(num, m[3]);
		}
		while (num['E'] > 0) {
			number.push_back(8);
			Remove(num, m[8]);
		}
		for (auto x : num) {
			assert(x.second == 0);
		}

		sort(number.begin(), number.end());

		cout << "Case #" << i + 1 << ": ";
		for (int x : number) {
			cout << x;
		}
		cout << endl;
	}

	return 0;
}