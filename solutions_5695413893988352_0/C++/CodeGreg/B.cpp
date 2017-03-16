#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <tuple>

using namespace std;

#define D(x) x
#define REP(i,a,b) for (int i = (a); i < (b); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cout << setprecision(12) << fixed;

    int T; cin >> T;
    REP(t,1,T+1) {
    	string c, j;
    	cin >> c >> j;

    	int i = 0;
    	while (i < c.length() && !(c[i] != '?' && j[i] != '?' && c[i] != j[i])) {
    		i++;
    	}

    	for (int t = 0; t < i; ++t) {
			if (c[t] == '?' && j[t] == '?') {
				c[t] = '0';
				j[t] = '0';
			} else if (c[t] == '?') {
				c[t] = j[t];
			} else if (j[t] == '?') {
				j[t] = c[t];
			}
		}

    	if (i == c.length() || c[i] < j[i]) {
    		for (int t = i+1; t < c.length(); ++t) {
				if (c[t] == '?') {
					c[t] = '9';
				}
				if (j[t] == '?') {
					j[t] = '0';
				}
			}
    	} else {
    		for (int t = i+1; t < c.length(); ++t) {
				if (c[t] == '?' && j[t] == '?') {
					c[t] = '0';
				}
				if (j[t] == '?') {
					j[t] = '9';
				}
			}
    	}

    	cout << "Case #" << t << ": " << c << " " << j << endl;
    }

	return 0;
}
