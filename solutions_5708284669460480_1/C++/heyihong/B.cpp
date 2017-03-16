#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> build_automaton(const string & str) {
	vector<int> p(str.size() + 1);
	p[1] = p[0] = 0;
	int k = 0;
	for (int i = 2; i <= str.size(); ++i) {
		for (; k > 0 && str[k] != str[i - 1]; k = p[k]);
		if (str[k] == str[i - 1]) ++k;
		p[i] = k;
	}
	return p;
}

int main() {
	freopen("in.txt", "r", stdin);
	int test_case;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; ++tc) {
		int k, l, s;
		string kb, target;
		cin >> k >> l >> s;
		cin >> kb >> target;
		vector<int> aut = build_automaton(target);
		vector<double> prob(26, 0);
		for (int i = 0; i != kb.size(); ++i)
			++prob[kb[i] - 'A'];
		for (int i = 0; i != prob.size(); ++i)
			prob[i] = prob[i] / (double)k;
		double ans = 0;
		for (int i = 0, j = 0; i != s; ++i) {
			if (prob[target[j] - 'A'] > 0) 
				++j;
			if (j == target.size()) {
				++ans;
				j = aut[j];
			}
		}
		vector<double> f(target.size(), 0);
		f[0] = 1;
		for (int i = 0; i != s; ++i) {
			vector<double> tmp(f.size(), 0);
			for (int j = 0; j != l; ++j) 
				for (int c = 0; c != 26; ++c) {
					double pr = f[j] * prob[c];
					int _j = j;
					for (; _j > 0 && target[_j] != c + 'A'; _j = aut[_j]);
					if (target[_j] == c + 'A') ++_j;
					if (_j == l) {
						ans -= pr;
						_j = aut[_j]; 
					}
					tmp[_j] += pr;
				}
			f = tmp;
		}
		printf("Case #%d: %.7lf\n", tc, ans);
	}
	return 0;
}	
