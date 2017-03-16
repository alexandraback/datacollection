// Fractiles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

void computePos(int k, int c, int s);

int main()
{
	int t;
	int k, c, s;

	cin >> t;

	// getline(cin, str); // read until end of line (needed if getline is used)

	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ":";

		cin >> k >> c >> s;

		int samples = (k + c - 1) / c;

		if (samples > s) {
			cout << " IMPOSSIBLE";
		}
		else if (k == s+1000000) {
			for (int i = 1; i <= k; i++) {
				cout << " " << i;
			}
		}
		else {
			computePos(k, c, s);
		}

		cout << "\n";
	}

	return 0;
}


void computePos(int k, int cx, int s)
{
	unsigned long runPos = 0;
	unsigned long sum;
	unsigned long factor = 1;
	unsigned long currFactor;

	int tilesPerSample = (k + s - 1) / s;

	// compute k^(tilesPerSample - 1)
	for (int i = 0; i < tilesPerSample - 1; i++) {
		factor *= k;
	}

	for (int i = 0; i < s && runPos < k; i++) {
		sum = 0;
		currFactor = factor;
		for (int j = runPos; j < runPos + tilesPerSample && j < k; j++) {
			sum += j * currFactor;
			currFactor /= k;
		}
		runPos += tilesPerSample;

		cout << " " << sum + 1;
	}
}
