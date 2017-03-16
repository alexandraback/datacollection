#include <iostream>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <functional>

using namespace std;

#define upto(i,n) for(int i = 0; i<n; ++i)


typedef long long  ll;

int main() {
	int t, x,r,c;
	bool first;
	cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		first = false;
		cin >> x >> r >> c;
		
		//cout << x << ",  " << r << " x " << c <<"  ";
		if (r > c) swap(r, c);

		if (x == 1) {
			first = false;
			goto PRINT;
		}

		if (x == 2) {
			first =( r % 2 == 1 && c % 2 == 1);
			goto PRINT;
		}

		if (x == 3) {
			if (r == 1) 
				first = true;
			else
				first = (r*c % 3 != 0);
			goto PRINT;
		}

		if (x == 4) {
			if (r == 1)
				first = true;
			else
				first = !(r == 3 && c == 4 || r == 4);
			goto PRINT;
		}

		if (x >= 7) {
			first = true;
			goto PRINT;
		}
		PRINT:
		cout << "Case #" << tc << ": ";
		if (first)
			cout << "RICHARD" << endl;
		else
			cout << "GABRIEL" << endl;
	}


	return 0;
}