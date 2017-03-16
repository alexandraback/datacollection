#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <fstream>
#include <math.h>
#include <map>
#include <string>
#include <ctime>
#define LL long long int
#define double long double
using namespace std;

double solve (double c, double f, double x)
{
	int i;
	double res = 0, ans = 1e18;
	for (i = 0; i <= 100002; i++)
	{
		ans = min(res + x/(2.0 + i*f), ans);
		res += c/(2.0 + i*f);
	}
	return ans;
}

int main()
{
	freopen("B-large.in", "r", stdin); freopen("output.txt", "w", stdout);
	int i, t;
	double c,f,x;
	cin >> t;
	cout.precision(7);
	for (i = 1; i <= t; i++)
	{
		cin >> c >> f >> x;
		cout << "Case #" << i <<": ";
		cout << fixed << solve(c, f, x) << endl;
	}
	return 0;
}