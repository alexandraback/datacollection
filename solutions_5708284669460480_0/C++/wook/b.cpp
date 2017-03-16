#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++ i)
#define FOR(i, b, e) for(auto i = b; i < e; ++ i)
#define all(x) (x).begin(), (x).end()

int K, L, S;
string alphabet;
string target;

string current;

template<typename T>
void generate(int now, T func) {
	if(now >= S) {
//		cout << current << endl;
		func();
		return;
	}

	for(char a : alphabet) {
		current[now] = a;
		generate(now + 1, func);
	}
}

double go() {
	current = string(S, '?');
	int sumv = 0;
	int cntv = 0;
	int maxv = 0;
	generate(0, [&]() {
		// current, target
		int occur = 0;
		for(int i = 0; i < S - (int)target.size() + 1; ++ i) {
			bool hit = true;
			for(int k = 0; hit && k < (int)target.size(); ++ k) {
				if(current[i+k] != target[k])
					hit = false;
			}
			if(hit) occur ++;
		}
		sumv += occur;
		maxv = max(maxv, occur);
		cntv ++;
	});
	return (double)(maxv * cntv - sumv) / cntv;
}


int main() {
	int T;
	cin >> T;

	for(int t=1; t<=T; ++t) {
		cin >> K >> L >> S;
		cin >> alphabet >> target;
		printf("Case #%d: %.9f\n", t, go());
	}
	return 0;
}

