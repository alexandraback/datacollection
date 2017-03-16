#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

const double eps = 1e-9;
const int inf = 1e9 + 23;

const int size = 1000;

const int N = 4;


int main (void){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	int t;
	string s;
	
	cin >> t;
	for (int it = 1; it <= t; it++) {
		cout << "Case #" << it << ": ";
		cin >> s;
		if (s[s.length() - 1] == '\n')
			s.erase(s.length() - 1);
		if (s.length() == 1) {
			if (s[0] == '+') {
				cout << "0" << endl;
				continue;
			}
			if (s[0] == '-') {
				cout << "1" << endl;
				continue;
			}
			cout << "Something went wrong!" << endl;
			cout << it << endl;
			return 0;
		}
		char last = s[0];
		int ans = 0;
		for (int i = 1; i < s.length(); i++) {
			if (s[i] != last) {
				ans++;
				last = s[i];
			}
		}
		if (s[s.length() - 1] == '-') {
			cout << ans + 1 << endl;
		} else {
			cout << ans << endl;
		}
	}
	
	return 0;
}