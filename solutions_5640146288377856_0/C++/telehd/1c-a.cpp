//============================================================================
// Name        : 1c-a.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int T, R, C, W;
	int i;

	cin >> T;

	for (i = 0; i < T; i++) {
		cin >> R >> C >> W;
		int firstHit = C / W;
		int cost;
		firstHit = firstHit * R;
		if (C % W == 0) {
			cost = firstHit + W - 1;
		} else {
			cost = firstHit + W;
		}

		cout << "Case #" << i + 1 << ": " << cost << endl;
	}

	return 0;
}
