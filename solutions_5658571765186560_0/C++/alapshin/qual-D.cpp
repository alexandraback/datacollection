#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <set>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <queue>

#define ST first
#define ND second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void print_g(int i) {
	cout << "Case #" << i << ": GABRIEL" << endl;
}

void print_r(int i) {
	cout << "Case #" << i << ": RICHARD" << endl;
}

int main()
{
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x, r, c;
		cin >> x >> r >> c;

		if (x == 1) print_g(i + 1);
		
		if (x == 2) {
			if (r % 2 == 0 || c % 2 == 0) print_g(i + 1); else print_r(i + 1);
		}

		if (x == 3) {
			if ((r == 3 && c == 2) || (r == 2 && c == 3) || (r == 3 && c == 3) || (r == 4 && c == 3) || (r == 3 && c == 4)) print_g(i + 1); else print_r(i + 1);
		}

		if (x == 4) {
			if ((r == 3 && c == 4) || (r == 4 && c == 3) || (r == 4 && c == 4)) print_g(i + 1); else print_r(i + 1);
		}
	}
	
	return 0;
}

