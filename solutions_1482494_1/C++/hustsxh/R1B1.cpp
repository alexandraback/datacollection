#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

typedef long long LL;

using namespace std;

struct Level {
	int star1, star2;
	bool operator < (const Level & a) const {
		return star2 < a.star2 || star2 == a.star2 && star1 > a.star1;
	}
}l[1001];

int visted[1001];

int solve(int n) {
	memset(visted, 0, sizeof(visted));
	sort(l + 1, l + 1 + n);
	int star = 0, ans = 0;
	for(int i = 1; i <= n; ++i) {
		while(star < l[i].star2) {
			int have = 0;
			for(int j = n; j >= i && !have; --j) {
				if(!visted[j] && l[j].star1 <= star) {
					have = j;
				}
			}
			if(have) {
				++ star;
				++ ans;
				visted[have] = 1;
			} else {
				return -1;
			}
		}
		star += 2 - visted[i];
		++ ans;
	}
	return ans;
}

int main()
{
	int T;
	freopen("B-large.in", "r", stdin);
	freopen("b.out", "w", stdout);
	cin >> T;
	for(int test = 1; test <= T; ++test) {
		cout << "Case #" << test << ": ";
		int n;
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			cin >> l[i].star1 >> l[i].star2;
		}
		int ans = solve(n);
		if(ans == -1) {
			cout << "Too Bad" << endl;
		} else {
			cout << ans << endl;
		}
	}
	return 0;
}
