#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

const long long NMAX = 1000002;

long long ups[14];

long long converttonum(vector <int> x) {
	long long ret = 0;
	for (int i = 0; i < x.size(); i++) {
		ret *= 10LL;
		ret += x[i];
	}
	return ret;
}

long long reversenum(long long x) {
	vector <int> digs;
	while (x) {
		digs.push_back(x % 10);
		x /= 10;
	}
	return converttonum(digs);
}

long long nextup(long long x) {
	vector <int> digs;
	while (x) {
		digs.push_back(x % 10);
		x /= 10;
	}

	if (digs[digs.size() - 2] == 0)
		digs[digs.size() - 2] = 9;
	else {
		digs[digs.size() - 1] = 0;
		digs.push_back(1);
	}
	reverse(digs.begin(), digs.end());
	return converttonum(digs);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//vector <int> nums();
	ups[0] = 1;
	ups[1] = 9;
	ups[2] = 19;

	for (int i = 3; i < 14; i++) 
		ups[i] = nextup(ups[i - 1]);
	


	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		long long ans = 0;
		long long n;
		cin >> n;
		if (n % 10 == 0)
			ans++, n--;

		long long cnt = 1LL;
		int i = 0;
		while (cnt <= n) {
			cnt *= 10LL;
			i++;
		}

		cnt /= 10LL;
		i--;

		while (i >= 0) {
			ans += ups[i];
			i--;
		}

		int x = n;
		vector <int> digs;
		while (x) {
			digs.push_back(x % 10);
			x /= 10;
		}


		reverse(digs.begin(), digs.end());
		vector <int> half;
		for (int i = 0; i < digs.size() / 2; i++)
			half.push_back(digs[i]);
		reverse(half.begin(), half.end());
		long long add = converttonum(half);
		if (add > 1)
			add++;
		ans += add;

		half.clear();
		for (int i = digs.size() / 2; i < digs.size(); i++)
			half.push_back(digs[i]);

		add = converttonum(half);
		if (add != 0)
			add--;

		ans += add;
		cout << "Case #" << test << ": " << ans << endl;
	}

	return 0;
}