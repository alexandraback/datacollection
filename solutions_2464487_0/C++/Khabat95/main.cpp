#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <cassert>
#include <complex>

using namespace std;

typedef set<int>::iterator SETIT;
typedef map<int, int>::iterator MAPIT;
typedef pair<int, int> PAIR;

void algo() {
	long double r, t;
	cin >> r >> t;

	int res = 0;
	while(t > 0) {
		long double a = 2.0*r + 1.0;
		if(a <= t) {
			t -= a;
			r += 2.0;
			res++;
		}
		else {
			break;
		}
	}


	cout << res << endl;
}

int main() {
	int n_cases;
	cin >> n_cases;

	for(int i=0; i<n_cases; ++i) {
		cout << "Case #" << i+1 << ": ";
		algo();
	}
}

