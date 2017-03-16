#include <cstdio>
#include <math.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <bitset>
#include <cassert>

using namespace std;

uint64_t rings(uint64_t r, uint64_t t) {
	uint64_t rings = 0;
	uint64_t paintNeeded = 2*r+1;

	while (t >= paintNeeded)
	{
		rings++;
		r = r + 2;
		t = t - paintNeeded;
		paintNeeded = 2*r+1;
	}
	return rings;
}

int main(int argc, char *argv[]) {
	int c, cases;
	cin >> cases;
	
	for(c = 1; c <= cases; c++) {
		uint64_t r, t;
		cin >> r;
		cin >> t;
		
		//cout << "r: " << r << " t: " << t << "\n";

		cout << "Case #" << c << ": ";
		cout << rings(r, t) << '\n';
	}
}

