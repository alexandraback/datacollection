#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <deque>

using namespace std;

bool used[2505];

int main() {

	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B.txt", "w", stdout);

	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		cin >> n;
		for (int j = 0; j <= 2500; j++)
			used[j] = false;
		for (int j = 0; j < 2 * n - 1; j++) {
			for (int k = 0; k < n; k++) {
				int x;
				cin >> x;
				used[x] ^= true;
			}
		}
		cout << "Case #" << i << ": ";
		for (int j = 0; j <= 2500; j++)
			if (used[j])
				cout << j << ' ';
		cout << '\n';

	}

}