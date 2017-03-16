#include<iostream>
#include <cmath>
#include<string>
#include <functional>
#include<cstdlib>
#include <algorithm>
using namespace std;

int64_t sum = 0, maxx = 0;
string s, keys, target;
int K, L, S;

void gen(int k) {
	if(k == S) {
		int64_t cnt = 0;
		for(int i = 0; i + L - 1 < S; ++i) {
			if (s.substr(i, L) == target)
				cnt++;
		}
		sum += cnt;
		maxx = max(maxx, cnt);
		return;
	}
	for(int i = 0; i < K; ++i) {
		s[k] = keys[i];
		gen(k + 1);
	}
}

int main() {
	int T;
	cin >> T;
	srand(123);
	for(int t = 1; t <= T; ++t) {
		cin >> K >> L >> S;
		cin >> keys >> target;
		s.resize(S + 1, 'x');
		sum = maxx = 0;
		gen(0);
		double est = (double) sum / pow((double)K, S);
		cout << "Case #" << t << ": " << (maxx - est) << endl;
	}
	return 0;
}