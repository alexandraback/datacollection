// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

__int64 getTile(__int64 start, __int64 end, __int64 k, __int64 c) {
	if (c == 1) {
		if (start != end) {			
			return -2;
		}
		return start;
	}
	if (start == end)
		return getTile(start, start, k, c - 1) * k;
	else
		return getTile(start, end - 1, k, c - 1) * k + end;

}

void solve(int k, int c, int s) {
	int minS = k / c + ((k%c != 0) ? 1 : 0);
	if (minS > s) {
		cout << "IMPOSSIBLE";
		return;
	}
	int start = 0;
	for (int i = 0; i < minS; i++) {
		int end = start + c - 1;
		if (end >= k) {
			start -= end - k + 1;
			end = k - 1;
		}
		if (start < 0)
			start = 0;
		cout << getTile(start, end, k, c) + 1;
		if (i < minS - 1)
			cout << " ";
		start = end + 1;
	}


}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int k, c, s;
		cin >> k >> c >> s;
		cout << "Case #" << i + 1 << ": ";
		solve(k, c, s);
		cout << endl;

	}
	return 0;
}

