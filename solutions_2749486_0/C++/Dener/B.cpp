#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

int x, y;

void solve() {
	cin >> x >> y;

	if (x < 0) {
		for (int i = 0; i < abs(x); i++)
			cout << "EW";
	}
	else
		for (int i = 0; i < abs(x); i++)
			cout << "WE";

	if (y < 0) {
		for (int i = 0; i < abs(y); i++)
			cout << "NS";
	}
	else
		for (int i = 0; i < abs(y); i++)
			cout << "SN";

	cout << endl;

	return;
}

int main() {
#ifdef OFFLINE
	freopen("B_input.txt","r", stdin);
	freopen("B_output.txt","w", stdout);
#endif
	int t;
	scanf("%d\n", &t);
	for (int testnum = 0; testnum < t; testnum++) {
		printf("Case #%d: ", testnum + 1);
		solve();
	}
}
