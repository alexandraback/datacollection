#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include "math.h"

using namespace std;

typedef long long ll;

int main() {
	int ntc;
	cin >> ntc;
	for (int tc = 1; tc <= ntc; tc++) {
		int a, b, k;
		cin >> a >> b >> k;
		cout << "Case #" << tc << ": ";
		int s = 0;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				int x = i & j;
				if (x < k) {
					s++;
				}
			}
		}
		cout << s;
		cout << endl;
	}
	return 0;
}

