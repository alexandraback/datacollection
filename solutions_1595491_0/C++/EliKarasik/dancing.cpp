/*
 * Eli Karasik
 * CodeJam 2012 - Qualification - B
 *
 * C++ - compile with any free compiler
 */

#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	int n,s,p,cur, res;

	int i,j;
	for (i = 0; i < t; i++) {
		cin >> n >> s >> p;
		res = 0;
		for (j = 0; j < n; j++) {
			cin >> cur;
			if (p + 2*max(0,p-1) <= cur) {
				res++;
			} else {
				if ((s > 0) && (p + 2*max(0,p-2) <= cur)) {
					s--;
					res++;
				}
			}
		}
		cout << "Case #" << (i+1) << ": " << res << endl;
	}
}