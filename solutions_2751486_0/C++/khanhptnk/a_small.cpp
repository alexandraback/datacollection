#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

int ntest;
string s;
int k;

bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool ok(string s) {
	int cnt = 0;
	for (int i = 0; i < s.length(); i++)
		if (!isVowel(s[i])) cnt++;
		else {
			if (cnt >= k) return true;
			cnt = 0;
		}
	return cnt >= k;
}

int main() {
	//freopen("input.txt", "r", stdin);
	freopen("input_small.txt", "r", stdin);
	freopen("output_small.txt", "w", stdout);
	cin >> ntest;	
	for (int test = 0; test < ntest; test++) {
		cin >> s >> k;
		int n = s.length();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			string tmp = "";
			for (int j = i; j < n; j++) {
				tmp += s[j];
				if (ok(tmp)) {
					//cout << tmp << endl;
					ans++;
				}
			}
		}
		cout << "Case #" << test + 1 << ": " << ans << endl;
	}
}
