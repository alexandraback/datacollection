#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>

using namespace std;
int C, D, V;
int l[110];
bool a[123123];

int solve() {
	for (int i = 1; i <= V; i++) a[i] = 0;
	a[0] = 1;

	for (int i = 0; i < D; i++) {
		for (int j = 0; j < C; j++) {
			for (int k = V - l[i]; k >= 0; k--) {
				a[k + l[i]] |= a[k];
			}
		}
	}
	int result = 0;
	while (true) {
		int pos;
		for (pos = 0; pos <= V && a[pos]; pos++);
		if (pos <= V) {
			for (int j = 0; j < C; j++) {
				for (int k = V - pos; k >= 0; k--) {
					a[k + pos] |= a[k];
				}
			}
			result++;
		} else {
			break;
		}
	}
	return result;
}

int main() {
	int T, tn = 0;
	cin >> T;
	while (T --> 0) {
		tn++;
		cerr << "Case #" << tn << "\n";
		cin >> C >> D >> V;
		for (int i = 0; i < D; i++) {
			cin >> l[i];
		}
		cout << "Case #" << tn << ": " << solve() << "\n";
	}
}