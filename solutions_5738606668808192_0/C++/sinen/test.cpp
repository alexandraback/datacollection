#include <bits/stdc++.h>
using namespace std;

const int K = 7;

int n, J, t;
vector < vector <int> > v;

int main () {
	freopen("out.txt", "w", stdout);
	cin >> t;
	cin >> n >> J;
	for(int bit = 0; bit < (1 << K); bit++) {
		vector <int> w(K);
		for(int i = 0; i < K; i++) w[i] = (bit >> i) & 1;
		v.push_back(w);
	}
	cout << "Case #1:\n";
	for(int i = 0; i < J; i++) {
		cout << "1";
		for(int j = 0; j < v[i].size(); j++) cout << v[i][j];
		for(int j = 0; j < v[i].size(); j++) cout << v[i][j];
		cout << "1 3 4 5 6 7 8 9 10 11\n";
	}
	return 0;
}