#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <cstdlib>
#include <queue>
#include <set>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <sstream>
#include <cassert>

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int m;
		string s;
		cin >> m >> s;
		int cur = 0, ans = 0;
		for (int i = 0; i <= m; ++i) {
			if (cur < i) {
				ans += i - cur;
				cur = i;
			}
			cur += s[i] - '0';
		}
		cout << "Case #" << t + 1 << ": " << ans << "\n";
	}
    return 0;
}