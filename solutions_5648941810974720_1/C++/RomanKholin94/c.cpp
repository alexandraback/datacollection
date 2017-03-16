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

void d(int a[], string s, int x) {
	for (int i = 0; i < s.length(); ++i) {
		a[s[i] - 'A'] -= x;
		//cout << x << endl;
	}
}

void solve() {
	string s;
	int a[100], b[100];
	memset(a, 0, sizeof(a));
	
	cin >> s;
	//cout << s << endl;
	for (int i = 0; i < s.length(); ++i) {
		++a[s[i] - 'A'];
		//cout << s[i] << endl;
	}
	
	b[0] = a['Z' - 'A'];
	d(a, "ZERO", a['Z' - 'A']);
	b[2] = a['W' - 'A'];
	d(a, "TWO", a['W' - 'A']);
	b[6] = a['X' - 'A'];
	d(a, "SIX", a['X' - 'A']);
	b[8] = a['G' - 'A'];
	d(a, "EIGHT", a['G' - 'A']);
	b[7] = a['S' - 'A'];
	d(a, "SEVEN", a['S' - 'A']);
	b[5] = a['V' - 'A'];
	d(a, "FIVE", a['V' - 'A']);
	b[4] = a['F' - 'A'];
	d(a, "FOUR", a['F' - 'A']);
	b[1] = a['O' - 'A'];
	d(a, "ONE", a['O' - 'A']);
	b[3] = a['T' - 'A'];
	d(a, "THREE", a['T' - 'A']);
	b[9] = a['I' - 'A'];
	d(a, "NINE", a['I' - 'A']);
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < b[i]; ++j) {
			cout << i;
		}
		//cout << b[i] << endl;
	}
	cout << endl;
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

