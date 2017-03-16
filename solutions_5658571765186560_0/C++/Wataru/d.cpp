#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;


int x, c, r;

void Load()
{
	cin >> x >> r >> c;
}





bool Solve()
{
	if (x == 1)
		return false;
	if (r*c % x != 0) return true;
	int t;
	if (r > c) {
		t = r;
		r = c;
		c = t;
	}
	//case 0: obstruct corner;
	if (x >= r+c-1 && x > 1) {
		return true;
	}
	if (x >= r+r) {
		if (x*(r+1) > (c+r-1)*r)
			return true;
	}
	return false;
}




int main()
{
	cout.setf(ios::fixed|ios::showpoint);
	cout.precision(10);
	int nt, tt;
	cin >> nt;
	for (tt = 1; tt <= nt; tt++) {
		cout << "Case #" << tt << ": ";
		Load();
		if (Solve())
			cout << "RICHARD\n";
		else
			cout << "GABRIEL\n"; 
	}
	return 0;
}
