#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>


using namespace std;

#pragma comment(linker, "/STACK:64000000")

typedef long long ll;

const int MAXK = 0;
const int MAXN = 1 << MAXK;
const int INF = (int)1e9;


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		cout << "Case #" << test << ": ";
		cerr << "Case #" << test << ": ";
		
		string s;
		cin >> s;
		int n = s.length();
		vector<char> f(n, 0);
		for (int i = n - 1; i >= 0; i--) {
			f[i] = 1;
			for (int j = 0; j < i; j++) {
				f[i] &= s[j] <= s[i];
			}
		}
		deque<char> q;
		for (int i = 0; i < n; i++) {
			if (f[i]) q.push_front(s[i]);
			else q.push_back(s[i]);
		}
		
		string ans = "";
		for (int i = 0; i < n; i++) ans += q[i];
		cout << ans << endl;
		cerr << ans << endl;
	}

	return 0;
}