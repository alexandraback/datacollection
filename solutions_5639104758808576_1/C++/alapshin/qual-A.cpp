#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <set>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <queue>

#define ST first
#define ND second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int smax = 0;
		string s;
		cin >> smax >> s;

		int stands = 0;
		int ans = 0;
		for (int j = 0; j < s.length(); j++) {
			if (j <= stands) {
				stands += s[j] - '0';
			} else {
				ans += (j - stands);
				stands += (j - stands + s[j] - '0');
			}
		}

		cout << "Case #" << i + 1 << ": " << ans << endl;
	}

	return 0;
}

