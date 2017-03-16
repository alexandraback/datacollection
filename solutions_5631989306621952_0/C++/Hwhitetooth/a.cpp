#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

const int N = 1000;

string f[N];
int testCases, n;

int main() {
	cin >> testCases;
	for (int _ = 1; _ <= testCases; ++_) {
		string s;
		cin >> s;
		f[0] = s[0];
		for (int i = 1; i < s.length(); ++i) {
			f[i] = max(s[i] + f[i - 1], f[i - 1] + s[i]);
		}
		cout << "Case #" << _ << ": " << f[s.length() - 1] << endl;
	}
	return 0;
}
