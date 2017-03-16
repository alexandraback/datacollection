#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 1000010;

bool was[MAXN];
int N, d[MAXN];

int reverse(int X) {
	string s = "0";
	while (X) {
		s += X % 10 + '0';
		X /= 10;
	}
	return atoi(s.c_str());
}

void solve(int tc) {
	cin >> N;
	memset(was, 0, sizeof was);
	queue<int> Q;
	Q.push(1);
	was[1] = 1;
	d[1] = 1;
	while (!Q.empty()) {
		int c = Q.front(); Q.pop();
		if (c + 1 < MAXN && !was[c + 1]) {
			Q.push(c + 1);
			was[c + 1] = 1;
			d[c + 1] = d[c] + 1;
		}
		int add = reverse(c);
		if (add < MAXN && !was[add]) {
			Q.push(add);
			was[add] = 1;
			d[add] = d[c] + 1;
		}
	}
	int ans = d[N];
	cout << "Case #" << tc << ": " << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	#ifdef ACMTUYO
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
		clock_t start = clock();
	#endif
	
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc)
		solve(tc);
	
	#ifdef ACMTUYO
		fprintf(stderr, "\ntime=%.3lfsec\n", 1. * (clock() - start) / CLOCKS_PER_SEC);
	#endif
	return 0;
}

