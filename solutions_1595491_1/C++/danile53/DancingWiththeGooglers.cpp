/*
 * Google Code Jam
 * Qualification Round 2012
 * Problem C. Recycled Numbers
 */

#include <math.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main() {
	// read
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		int n, p, s, t[101];
		bool can_it_count[101], has_to_be_surprising_to_count[101];
		cin >> n >> s >> p;
		memset(can_it_count, false, sizeof(can_it_count));
		memset(has_to_be_surprising_to_count, true,
				sizeof(has_to_be_surprising_to_count));

		for (int i = 0; i < n; i++) {
			cin >> t[i];
			if (t[i] >= 3 * p - 4)
				can_it_count[i] = true;
			for (int d = p; d <= 10; d++)
				if ((t[i] - 3*d >= -2) && (t[i] - 3*d <= 2))
					has_to_be_surprising_to_count[i] = false;
		}

		int sol = 0;
		// step 1
		for (int i = 0; i < n; i++) {
			if (can_it_count[i] && has_to_be_surprising_to_count[i]) {
				if (s && t[i] <= 28 && t[i] >= 2) {
					sol++;
					s--;
				}
				can_it_count[i] = false;
			}
		}
		// step 2
		if (s) {
			for (int i = 0; i < n; i++)
				if (can_it_count[i] && s && t[i] <= 28 && t[i] >= 2) {
					for (int d = p; d <= 10; d++)
						if (t[i] - 2 - 2 <= 3 * d && 3 * d <= t[i] - 2 - 0) {
							s--;
							sol ++;
							can_it_count[i] = false;
						}
				}
		}
		// step 3
		for (int i = 0; i < n; i++) {
			if (can_it_count[i])
				sol++;
		}
		printf("Case #%d: %d\n", tt, sol);
	}

	return 0;
}
