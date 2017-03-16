#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <utility>
#include <memory.h>
#include <cassert>
#include <iterator>
#include <bitset>
#include <iomanip>
#include <complex>
#include <queue>
#include <ctime>
#include <deque>
#include <stack>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second

const int N = 1010;

int n;
string s;
string f[N][N];

string solve(int l, int r) {
	if (l > r) return "";
	f[l][r] = s.substr(l, r - l + 1);
	string add = "";
	for (int j = r; j >= l; --j) {
		f[l][r] = max(f[l][r], s[j] + solve(l, j - 1) + add);
		add = s[j] + add;
	}
	return f[l][r];
}

void solve(int test) {
	cin >> s;
	n = (int)s.size();
	string result = "";
	result += s[0];
	for (int i = 1; i < (int)s.size(); i++) {
		if (s[i] >= result[0]) {
			result = s[i] + result;
		} else result += s[i];
	}
	cout << "Case #" << test << ": " << result << "\n";
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int tc;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++) {
		solve(i);
	}
	return 0;
}