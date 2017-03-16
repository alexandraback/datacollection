#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#include<set>
#include<map>
#include<fstream>
#define epsilon 0.000000001
#define cosinusa(a, b, c) ((a * a + b * b - c * c) / (2.0 * a * b));
#define infi 1000000000
using namespace std;

bool solve(int x, int r, int c)
{
	if (x >= 7)
		return true;
	if (r * c % x != 0)
		return true;
	if (r < x && c < x)
		return true;
	if (x <= 2)
		return false;
	if (r == 1 || c == 1)
		return true;
	if (x == 3)
		return false;
	if (r == 2 || c == 2)
		return true;
	if (x == 4)
		return false;
	if (r == 3 || c == 3)
		return true;
	if (x == 5)
		return false;
	return false;
}
int main()
{
	freopen("google.in", "r", stdin);
	freopen("google.out", "w", stdout);
	int numTests;
	cin >> numTests;
	for(int testCounter = 0; testCounter < numTests; ++testCounter)
	{
		printf("Case #%d: ", testCounter + 1);
		int x, r, c;
		cin >> x >> r >> c;
		if (solve(x, r, c))
		{
			cout << "RICHARD" << endl;
		} else {
			cout << "GABRIEL" << endl;

		}

	}
	return 0;
}
