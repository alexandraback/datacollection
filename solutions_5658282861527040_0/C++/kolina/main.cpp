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

using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);

	long long t;
	cin >> t;
	for (long long i = 0; i < t; ++i) {
		long long a, b, k;
		cin >> a >> b >> k;
		long long ans = 0;
		long long l = 0;
		while ((1ll << l) <= k)
			++l;
		--l;
		long long cur = 0;
		long long l1 = 0, l2 = 0;
		while ((1ll << l1) <= a)
			++l1;
		--l1;
		while ((1ll << l2) <= b)
			++l2;
		--l2;
		long long beg = max(l, max(l1, l2));
		vector<vector<long long> > v(beg + 2, vector<long long>(4));
		v[beg + 1][3] = 1;
		if (k & (1ll << beg)) {
			if ((a & (1ll << beg)) && (b & (1ll << beg)))
				v[beg][3] = 1;
		}
		else {
			if ((a & (1ll << beg)) && (b & (1ll << beg))) {
				v[beg][0] = 1;
				v[beg][1] = 1;
				v[beg][2] = 1;
			}
			if ((a & (1ll << beg)) && !(b & (1ll << beg))) {
				v[beg][3] = 1;
				v[beg][2] = 1;
			}
			if (!(a & (1ll << beg)) && (b & (1ll << beg))) {
				v[beg][3] = 1;
				v[beg][1] = 1;
			}
		}
		for (long long bit = beg - 1; bit >= 0; --bit)
			if ((1ll << bit) & k) {
				v[bit][0] += v[bit + 1][0];
				if (a & (1ll << bit))
					v[bit][1] += v[bit + 1][1];
				if (b & (1ll << bit))
					v[bit][2] += v[bit + 1][2];
				if ((a & (1ll << bit)) && (b & (1ll << bit)))
					v[bit][3] += v[bit + 1][3];
			}
			else {
				if ((a & (1ll << bit)) && (b & (1ll << bit))) {
					v[bit][0] += v[bit + 1][3];
				}
				if ((a & (1ll << bit)) && !(b & (1ll << bit))) {
					v[bit][1] += v[bit + 1][3];
				}
				if (!(a & (1ll << bit)) && (b & (1ll << bit))) {
					v[bit][2] += v[bit + 1][3];
				}
				if (!(a & (1ll << bit)) && !(b & (1ll << bit))) {
					v[bit][3] += v[bit + 1][3];
				}
				if (b & (1ll << bit))
					v[bit][0] += v[bit + 1][2];
				else
					v[bit][2] += v[bit + 1][2];
				if (a & (1ll << bit))
					v[bit][0] += v[bit + 1][1];
				else
					v[bit][1] += v[bit + 1][1];
				v[bit][0] += v[bit + 1][0];
				if (a & (1ll << bit)) {
					if (b & (1ll << bit))
						v[bit][1] += v[bit + 1][3];
					else
						v[bit][3] += v[bit + 1][3];
					v[bit][1] += v[bit + 1][1];
				}
				if (b & (1ll << bit))
					v[bit][0] += v[bit + 1][2];
				else
					v[bit][2] += v[bit + 1][2];
				v[bit][0] += v[bit + 1][0];
				if (b & (1ll << bit)) {
					if (a & (1ll << bit))
						v[bit][2] += v[bit + 1][3];
					else
						v[bit][3] += v[bit + 1][3];
					v[bit][2] += v[bit + 1][2];
				}
				if (a & (1ll << bit))
					v[bit][0] += v[bit + 1][1];
				else
					v[bit][1] += v[bit + 1][1];
				v[bit][0] += v[bit + 1][0];
			}
		long long cur1 = 0, cur2 = 0;
		for (long long j = beg; j >= 0; --j) {
			if (k & (1ll << j)) {
					ans += max(0ll, (min(a, cur1 + (1ll << j)) - cur1) * (min(b, cur2 + (1ll << j)) - cur2) * v[j + 1][3]);
					ans += max(0ll, (1ll << (2 * j)) * v[j + 1][0]);
					ans += max(0ll, (min(a, cur1 + (1ll << j)) - cur1) * (1ll << j) * v[j + 1][1]);
					ans += max(0ll, (1ll << j) * (min(b, cur2 + (1ll << j)) - cur2) * v[j + 1][2]);
					ans += max(0ll, (min(a, cur1 + (1ll << (j + 1))) - cur1 - (1ll << j)) * (min(b, cur2 + (1ll << j)) - cur2) * v[j + 1][3]);
					ans += max(0ll, (min(a, cur1 + (1ll << (j + 1))) - cur1 - (1ll << j)) * (1ll << j) * v[j + 1][1]);
					ans += max(0ll, (1ll << (2 * j)) * v[j + 1][0]);
					ans += max(0ll, (1ll << j) * (min(b, cur2 + (1ll << j)) - cur2) * v[j + 1][2]);
					ans += max(0ll, (min(a, cur1 + (1ll << j)) - cur1) * (min(b, cur2 + (1ll << (j + 1))) - cur2 - (1ll << j)) * v[j + 1][3]);
					ans += max(0ll, (min(a, cur1 + (1ll << j)) - cur1) * (1ll << j) * v[j + 1][1]);
					ans += max(0ll, (1ll << (2 * j)) * v[j + 1][0]);
					ans += max(0ll, (1ll << j) * (min(b, cur2 + (1ll << (j + 1))) - cur2 - (1ll << j)) * v[j + 1][2]);
			}
			if (a & (1ll << j))
				cur1 += (1ll << j);
			if (b & (1ll << j))
				cur2 += (1ll << j);
		}
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}

	return 0;
}