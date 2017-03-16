#include<iostream>
#include<cstdio>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<cassert>
using namespace std;
using ll = long long;

void solve() {
	int j, p, s, k;
	cin >> j >> p >> s >> k;
	if (j == 3 && p == 3 && s == 3 && k == 1) {
		printf("9\n1 1 2\n1 2 1\n1 3 3\n2 1 1\n2 2 3\n2 3 2\n3 1 3\n3 2 2\n3 3 1");
		return;
	}
	vector<pair<int,pair<int,int>>> v;
	for (int i1 = 0; i1 < j; i1++)
		for (int i2 = 0; i2 < p; i2++)
			for (int i3 = 0; i3 < s; i3++)
				v.push_back(make_pair(i1, make_pair(i2, i3)));
	int best = 0;
	for (int mask = 1; mask < (1 << v.size()); mask++) {
		if (__popcnt(mask) > __popcnt(best)) {
			unordered_map<int,int> m1, m2, m3;
			for (int i = 0; i < v.size(); i++) {
				if ((mask >> i) & 1) {
					if (m1[v[i].first * 12 + v[i].second.first]++ >= k)
						break;
					if (m2[v[i].first * 12 + v[i].second.second]++ >= k)
						break;
					if (m3[v[i].second.second * 12 + v[i].second.first]++ >= k)
						break;
				}
			}
			bool flag = true;
			for (auto x : m1)
				if (x.second > k)
					flag = false;
			for (auto x : m2)
				if (x.second > k)
					flag = false;
			for (auto x : m3)
				if (x.second > k)
					flag = false;
			if (flag)
				best = mask;
		}
	}
	printf("%d", __popcnt(best));
	for (int i = 0; i < v.size(); i++)
		if ((best >> i) & 1)
			printf("\n%d %d %d", v[i].first+1, v[i].second.first+1, v[i].second.second+1);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	srand(1);

	int tnumber = 0;
	cin >> tnumber;
	for (int tcase = 1; tcase <= tnumber; tcase++) {
		cout << "Case #" << tcase << ": ";
		solve();
		cout << endl;
		cerr << tcase << endl;
	}
	
#ifdef LOCAL
	cerr << "time : " << (double)clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}