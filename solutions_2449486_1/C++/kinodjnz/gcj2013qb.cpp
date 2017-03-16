#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
typedef long long ll;

bool solve(int h, int w, int b[101][101]) {
	int v[101][101];
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			v[y][x] = 100;
		}
	}
	for (int t = 100; t >= 1; t--) {
		for (int y = 0; y < h; y++) {
			bool ok = true;
			for (int x = 0; x < w; x++) {
				if (b[y][x] > t) {
					ok = false;
					break;
				}
			}
			if (ok) {
				for (int x = 0; x < w; x++) {
					v[y][x] = t;
				}
			}
		}
		for (int x = 0; x < w; x++) {
			bool ok = true;
			for (int y = 0; y < h; y++) {
				if (b[y][x] > t) {
					ok = false;
					break;
				}
			}
			if (ok) {
				for (int y = 0; y < h; y++) {
					v[y][x] = t;
				}
			}
		}
	}
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			if (b[y][x] != v[y][x])
				return false;
		}
	}
	return true;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int h, w;
		cin >> h >> w;
		int b[101][101] = {};
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				cin >> b[y][x];
			}
		}
		bool r = solve(h, w, b);
		cout << "Case #" << i+1 << ": " << (r ? "YES" : "NO") << endl;
	}
}
