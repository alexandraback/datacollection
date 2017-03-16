#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

const int MN = 200 + 10;

int arr[MN], n;

bool good;

vector <int> v1, v2;

void solve(int pos, int s1, int s2, int s) {
	if (pos >= n)
		return;
	if (s1 && s1 == s2) {
		good = true;
		return;
	}
	if (abs(s1 - s2) > s)
		return;
	solve(pos + 1, s1, s2, s);
	if (good)
		return;
	solve(pos + 1, s1 + arr[pos], s2, s - arr[pos]);
	if (good) {
		v1.push_back(arr[pos]);
		return;
	}
	solve(pos + 1, s1, s2 + arr[pos], s - arr[pos]);
	if (good) {
		v2.push_back(arr[pos]);
		return;
	}
}

int main () {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for(int k = 0; k < t; k ++) {
		cin >> n;
		printf("Case #%d:\n", k + 1);
		int s = 0;
		for(int i = 0; i < n; i ++) {
			cin >> arr[i];
			s += arr[i];
		}
		sort(arr, arr + n);
		good = false;
		v1.clear();
		v2.clear();
		solve(0, 0, 0, s);
		
		if (!good)
			printf("Impossible\n");
		else {
			for(int i = 0; i < v1.size(); i ++)
				cout << v1[i] << " ";
			cout << endl;
			for(int i = 0; i < v2.size(); i ++)
				cout << v2[i] << " ";
			cout << endl;
		}
	}
	return 0;
}