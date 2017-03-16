#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

const int N = 2500 + 10;
int s[N];

void solve()
{
	int n;
	memset(s, 0, sizeof s);
	cin >> n;
	for(int i = 0; i < n + n - 1; ++ i) {
		for(int j = 0; j < n; ++ j) {
			int x;
			scanf("%d", &x);
			s[x] ^= 1;
		}
	}
	for(int i = 0; i < N; ++ i) {
		if (s[i]) {
			printf(" %d", i);
		}
	}
	puts("");
}

int main()
{
	//freopen("B-small-attempt0.in", "r", stdin); freopen("B-small-attempt0.out", "w", stdout);
	//freopen("B-small-attempt1.in", "r", stdin); freopen("B-small-attempt1.out", "w", stdout);
	//freopen("B-small-attempt2.in", "r", stdin); freopen("B-small-attempt2.out", "w", stdout);
	freopen("B-large.in", "r", stdin); freopen("B-large.out", "w", stdout);
	int test_case;
	cin >> test_case;
	for(int i = 0; i < test_case; ++ i) {
		printf("Case #%d:", i + 1);
		cerr << "Start: " << i << endl;
		solve();
	}
	return 0;
}
