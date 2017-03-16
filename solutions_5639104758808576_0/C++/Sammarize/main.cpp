#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int next() {int x; cin >> x; return x;}

int main() {

	int tests = next();
	for (int test = 1; test <= tests; test++) {
		int m = next();
		string s;
		cin >> s;
		vector<int> v(0);
		for (int i = 0; i <= m; i++) 
			for (char c = '0'; c < s[i]; c++) 
				v.push_back(i);
		
		int mn = 0;
		for (int i = 0; i < v.size(); i++) mn = max(mn, v[i] - i);
		printf("Case #%d: %d\n", test, mn);
	}
}