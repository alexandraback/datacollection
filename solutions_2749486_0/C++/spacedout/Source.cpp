#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

void solve () {

	int k;
	int x, y;

	cin>>x>>y;

	string dir = "E";
	string dir2 = "W";

	string diry = "N";
	string diry2 = "S";

	if (x > 0) {
		dir = "W";
		dir2 = "E";
	}
	else x *= -1;

	if (y > 0) {
		diry = "S";
		diry2 = "N";
	}
	else y *= -1;

	string ans = "";

	for (int i = 0; i < x; ++i) {ans += dir; ans += dir2;}
	for (int i = 0; i < y; ++i) {ans += diry; ans += diry2;}

	static int testN = 1;
	cout << "Case #" << testN << ": " << ans <<"\n";
	testN++;
}

int main () {

	int t;
	cin>>t;
	
	for (; t; t--)
		solve();

	return 0;
}
