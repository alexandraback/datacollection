#include <iostream>
#include <algorithm>

using namespace std;

double ans = 1e10;
double goal,farmCost,farmRate;

double calc(int fcnt)
{
	double rate = 2.0,curtime = 0.0;
	for (int i = 0; i < fcnt; i++)
	{
		curtime += farmCost / rate;
		rate += farmRate;
	}
	curtime += goal / rate;
	return curtime;
}

double bsearch(int lo,int hi)
{
	int mid = (lo + hi) / 2;
	double v1, v2, v3;
	v1 = calc(mid - 1);
	v2 = calc(mid);
	v3 = calc(mid + 1);
	if (lo > hi)
		return v2;
	if (v2 < v1 && v2 < v3)
		return v2;
	if (v2 < v3)
		return bsearch(lo, mid-1);
	else
		return bsearch(mid + 1, hi);
}

int main()
{
	int T;
	cin >> T;
	cout.setf(ios::fixed);
	cout.precision(7);
	for (int tt = 1; tt <= T; tt++)
	{
		cin >> farmCost >> farmRate >> goal;
		if (calc(0) < calc(1))
			ans = calc(0);
		else
			ans = bsearch(0, 101000);
		cout << "Case #" << tt << ": " << ans << endl;
	}
}
