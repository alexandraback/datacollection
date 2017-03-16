#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>

using namespace std;



int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t, r, c, w;
	cin >> t;
	for (int i = 0; i<t; i++)
	{
		int res = 0;
		cin >> r >> c >> w;


		res = c / w *r;

		res += w - 1;
		if (c%w != 0)
			res++;
		cout << "Case #" << i + 1 << ": " << res << endl;
	}

	return 0;
}