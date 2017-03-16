#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	
	for (int c = 1; c <= t; ++c) {
		int x, y;
		cin >> x >> y;
		string z;
		if (x > 0) {
			for (int i = 0; i < x; ++i) z = z + string("WE");
		} else if (x < 0) {
			for (int i = 0; i < -x; ++i) z = z + string("EW");
		}
		if (y > 0) {
			for (int i = 0; i < y; ++i) z = z + string("SN");
		} else if (y < 0) {
			for (int i = 0; i < -y; ++i) z = z + string("NS");
		}
		printf("Case #%d: %s\n", c, z.c_str() );
	}
	
	return 0;
}
