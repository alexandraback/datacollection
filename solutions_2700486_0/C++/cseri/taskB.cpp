#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <limits>
#include <stdexcept>

#include "prettyprint.hpp"

using namespace std;

typedef long long int ll;


double
choose(unsigned long long n, unsigned long long k) {
    if (k > n) {
        return 0;
    }
    double r = 1;
    for (unsigned long long d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}



int main() {

	cout.precision(10);
	cerr.precision(10);

  int tn;
  cin >> tn;

  for (int ti = 0; ti < tn; ti++) {

    int n = -1;
    int x = -1;
    int y = -1;
    cin >> n >> x >> y;
		cerr << "ti: " << ti << " n: " << n << " x: " << x << " y: " << y << endl;

		if (x < 0) x *= -1;
    double result;

    if (x % 2 != y % 2) {
			result = 0.0;
		} else if (0 == x && 0 == y) {
			result = 1.0;
		} else {
			int round = (x + y) / 2;

      int rem = n;
      int completedround = 0;
			while (rem >= 1+4*completedround) {
				rem -= 1+4*completedround;
				++completedround;
				cerr << "after round " << completedround << " remains " << rem << endl;
			}

			int h = y + 1;

			cerr << "in round " << round << " completed " << completedround << endl;

			if (completedround > round) {
				result = 1.0;
			} else if (completedround < round) {
				result = 0.0;
			} else if (x == 0) {
				//top one is tricky it would need all the pieces
				result = 0.0;
//			} else if (rem < h) {
				//not enough remaining
//				result = 0.0;
			} else {
				//at least h of rem diamonds must fall to good place
				int maxdiamonds = 2 * round;
				cerr << rem << " diamonds, " << h << " must fall to good place, max " << maxdiamonds << " on a side" << endl;
				double nom = 0;
				for (int i = h; i <= rem; ++i) {
					cerr << "  rem-i: " << rem-i << endl;
					cerr << "    i: " << i << endl;
					if (rem - i <= maxdiamonds && i <= maxdiamonds) {
						cerr << "    ok" << endl;
					  nom += choose(rem, i);
					}
				}
        double denom = 0;
				for (int i = 0; i <= rem; ++i) {
					cerr << "  rem-i: " << rem-i << endl;
					cerr << "    i: " << i << endl;
					if (rem - i <= maxdiamonds && i <= maxdiamonds) {
						cerr << "    ok" << endl;
					  denom += choose(rem, i);
					}
				}
				result = nom/denom;
			}

		}


    cout << "Case #" << ti+1 << ": " << result << endl;
    cerr << "Case #" << ti+1 << ": " << result << endl;

  }
}

