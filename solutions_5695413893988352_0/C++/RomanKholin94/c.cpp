#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <memory.h>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <list>
#include <memory.h>

using namespace std;

long long ans, at, bt;
string s1, s2;

void pr(int i, long long a, long long b) {
	if (i == s1.length()) {
		if ((abs(a - b) < ans) || (abs(a - b) == ans && a < at) || (abs(a - b) == ans && a == at && b < bt)) {
			ans = abs(a - b);
			at = a;
			bt = b;
		}
		return;
	}
	if (s1[i] != '?' && s2[i] != '?') {
		a *= 10;
		a += s1[i] - '0';
		b *= 10;
		b += s2[i] - '0';
		pr(i + 1, a, b);
	} else if (s1[i] == s2[i] && s1[i] == '?') {
		a *= 10;
		b *= 10;
		pr(i + 1, a, b);
		if (a < b) {
			a += 9;
			pr(i + 1, a, b);
			a -= 9;
		}
		if (b < a) {
			b += 9;
			pr(i + 1, a, b);
			b -= 9;
		}
		if (a == b) {
			a += 1;
			pr(i + 1, a, b);
			a -= 1;
		
			b += 1;
			pr(i + 1, a, b);
			b -= 1;
		}
	} else if (s1[i] == '?') {
		b *= 10;
		a *= 10;
		
		if (a == b) {
			b += s2[i] - '0';
			a += (s2[i] - '0');
			pr(i + 1, a, b);
		
			a += - (s2[i] - '0') + (((s2[i] - '0') + 1) % 10);
			pr(i + 1, a, b);
		
			a += - (((s2[i] - '0') + 1) % 10) + (((s2[i] - '0') - 1 + 10) % 10);
			pr(i + 1, a, b);
		} else if (a < b) {
			b += s2[i] - '0';
			a += 9;
			pr(i + 1, a, b);
		} else {
			b += s2[i] - '0';
			pr(i + 1, a, b);
		}
	} else {		
		a *= 10;
		b *= 10;
		if (a == b) {
			a += s1[i] - '0';
			
			b += (s1[i] - '0');
			pr(i + 1, a, b);
			b += - (s1[i] - '0') + (((s1[i] - '0') + 1) % 10);
			pr(i + 1, a, b);
			b += - (((s1[i] - '0') + 1) % 10) + (((s1[i] - '0') - 1 + 10) % 10);
			pr(i + 1, a, b);
		} else if (a < b) {
			a += s1[i] - '0';
			pr(i + 1, a, b);
		} else {
			a += s1[i] - '0';
			b += 9;
			pr(i + 1, a, b);
		}
	}
}

void solve() {
	cin >> s1 >> s2;
	ans = 1000 * 1000 * 1000;
	ans = ans * ans + 1;
	pr(0, 0, 0);
	for (int i = s1.length() - 1; i >= 0; --i) {
		s2[i] = at % 10 + '0';
		at /= 10;
	}
	cout << s2 << " ";
	for (int i = s1.length() - 1; i >= 0; --i) {
		s2[i] = bt % 10 + '0';
		bt /= 10;
	}
	cout << s2 << endl;	
}

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		cout << "Case #" << i + 1 << ": ";
		solve();
	}
	
	return 0;
}

