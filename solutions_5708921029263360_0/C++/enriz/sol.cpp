#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <tuple>
#include <functional>
#include <cassert>
using namespace std;

typedef long long tl; //type long
int _tc;

#define LEN(x) (sizeof(x) / sizeof(*x))
#define ABS(x) ((x > 0) ? (x) : -(x))
#define FORIN(i, n) for (int i = 0; i < n; ++i)
#define SIZE 100

int j, p, s, k;
vector<tuple<int, int, int> > v;

bool valid(int j, int p, int s) {
	int cjp, cjk, cpk;
	cjp = cjk = cpk = 0;
	if (j < 0 || p < 0 || s < 0)
		return false;
	for (auto it = v.begin(); it != v.end(); ++it) {
		if (get<0>(*it) == j && get<1>(*it) == p)
			cjp++;
		if (get<2>(*it) == s && get<1>(*it) == p)
			cpk++;
		if (get<0>(*it) == j && get<2>(*it) == s)
			cjk++;
		if (get<0>(*it) == j && get<2>(*it) == s && get<1>(*it) == p)
			return false;
		if (cjp >= k || cpk >= k || cjk >= k)
			return false;
	}
	return true;
}

bool testCase() {
	v.clear();
	cin >> j >> p >> s >> k;
	int output = 0;

	FORIN(si, s){				
		FORIN(pi, p) {
			FORIN(ji, j) {
				if (valid(ji, pi, si)) {
					v.push_back(make_tuple(ji, pi, si));
				}
				if (valid(j - ji - 1, p - pi - 1, s - si - 1)) {
					v.push_back(make_tuple(j - ji - 1, p - pi - 1, s - si - 1));
				}
			}
		}
	}
	int outputc = min(j * p * s, min(j * p * k, min(j * s * k, p * s * k)));
	//cerr <<  v.size() << endl;
	cout << v.size() << endl;
	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << get<0>(*it) + 1
			<< " " << get<1>(*it) + 1
			<< " " << get<2>(*it) + 1<< endl;
	}
	//assert(outputc == v.size());
	return true;
}

int main(){
	int ntc;

	cin >> ntc;
	//cerr << "tests " << n << endl;
	for (int _tc = 0; _tc < ntc; ++_tc) {
		cout << "Case #" << (_tc + 1) << ": ";
		if (!testCase()) {
			cout << " IMPOSSIBLE";
		}
		//cout << endl;
	}
	return 0;
}