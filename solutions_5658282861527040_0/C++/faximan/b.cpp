#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <math.h>
#include <stack>
#include <queue>
#include <stdio.h>

using namespace std;

long long a, b, k;

int main() {

	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		cin >> a >> b >> k;
		long long res = 0;
		for (int aa = 0; aa < a; aa++) {
			for (int bb = 0; bb < b; bb++) {
				if ( (aa & bb) < k) {
					res++;
				}
			}
		}


		printf("Case #%d: %lld\n", tt, res);
	}


  return 0;
}
