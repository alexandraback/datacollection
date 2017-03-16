#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

const int MN = 500 + 10;

#define ll long long

ll arr[MN];
int n;

bool good;

int v1[MN], v2[MN], sz1, sz2;

inline ll myabs(ll a) {
	if (a < 0)
		return -1;
	return a;
}

int cnt = 0;

void solve(int pos, ll s1, ll s2, ll s) {
	if (pos >= n)
		return;
	if (s1 && s1 == s2) {
		good = true;
		return;
	}
	if (myabs(s1 - s2) > s || cnt > 1000 * 1000 * 1000)
		return;
	cnt ++;
	solve(pos + 1, s1, s2, s);
	if (good)
		return;
	solve(pos + 1, s1 + arr[pos], s2, s - arr[pos]);
	if (good) {
		v1[sz1 ++] = arr[pos];
		return;
	}
	solve(pos + 1, s1, s2 + arr[pos], s - arr[pos]);
	if (good) {
		v2[sz2 ++] = arr[pos];
		return;
	}
}

bool my(ll a, ll b) {
	return (a > b);
}

int main () {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for(int k = 0; k < t; k ++) {
		cin >> n;
		printf("Case #%d:\n", k + 1);
		ll s = 0;
		for(int i = 0; i < n; i ++) {
			cin >> arr[i];
			s += arr[i];
		}
		sort(arr, arr + n, my);
		good = false;
		sz1 = sz2 = cnt = 0;
		solve(0, 0, 0, s);
		if (!good)
			printf("Impossible\n");
		else {
			for(int i = 0; i < sz1; i ++)
				cout << v1[i] << " ";
			cout << endl;
			for(int i = 0; i < sz2; i ++)
				cout << v2[i] << " ";
			cout << endl;
		}
	}
	return 0;
}