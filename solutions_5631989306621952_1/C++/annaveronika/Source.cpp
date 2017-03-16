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

int main() {
	freopen(PROBLEM_ID".in", "r", stdin);
	freopen(PROBLEM_ID".out", "w", stdout);

	/*
	cout << 100 << endl;
	for (int i = 0; i < 100; ++i) {
		for (int i = 0; i < 1000; ++i) {
			cout << 'A';
		}
		cout << endl;
	}
	return 0;
	*/
	
	
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	for (int i = 0; i < t; ++i) {
		getline(cin, s);
		deque<char> d;
		for (char c : s) {
			if (d.empty()) {
				d.push_back(c);
				continue;
			}
			bool found = false;
			for (int i = 0; i < d.size(); ++i) {
				if (d[i] > c) {
					d.push_back(c);
					found = true;
					break;
				}
				else if (d[i] < c) {
					d.push_front(c);
					found = true;
					break;
				}
			}
			if (!found) {
				d.push_back(c);
			}
		}
		cout << "Case #" << i + 1 << ": ";
		for (char c : d) {
			cout << c;
		}
		cout << endl;
	}

	return 0;
}