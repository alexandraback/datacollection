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

#define foreach(e,x) for(__typeof((x).begin()) e=(x).begin(); e!=(x).end(); ++e)

void solve()
{
	int n;
	string s;
	cin >> n >> s;
	int cnt = s[0] - '0';
	int need = 0;
	for(int i = 1; i <= n; ++ i) {
		if (s[i] != '0') {
			need = max(need, i - cnt);
			cnt += s[i] - '0';
		}
	}
	cout << need << endl;
}

int main()
{
	int test_case;
	cin >> test_case;
	for(int i = 0; i < test_case; ++ i) {
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}
