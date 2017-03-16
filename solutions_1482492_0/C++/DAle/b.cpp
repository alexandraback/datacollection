#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <cmath>
#include <functional>
#include <stack>
#include <set>

using namespace std;

inline double timefromx(double x, double a)
{
	return sqrt(2*x/a);
}

int main()
{
	ifstream ifs("b.in");
	ofstream ofs("b.out");
	int t;
	ifs >> t;
	ios_base::sync_with_stdio(0);
	for (int test = 0; test < t; ++test)
	{
		double D;
		int n, acnt;
		ifs >> D >> n >> acnt;
		vector<double> t(n), x(n);
		for (int i = 0; i < n; ++i)
		{
			ifs >> t[i] >> x[i];
		}
		int pos = 0;
		for (; pos < n; ++pos)
			if (x[pos] >= D-1e-9)
				break;
		n = pos+1;
		if (pos == 0)
		{
			if (x[pos] > D+1e-9) t[pos] = 0;
		}
		else 
		{
			double newt = t[pos-1] + (t[pos]-t[pos-1]) * (D-x[pos-1]) / (x[pos]-x[pos-1]);
			x[pos] = D;
			t[pos] = newt;
		}
		ofs << "Case #" << test+1 << ": " << endl;

		for (int ai = 0; ai < acnt; ++ai)
		{
			double a;
			ifs >> a;
			double l = 0, r = 1000000;
			for (int iter = 0; iter < 100; ++iter)
			{
				double gap = (l+r) / 2;
				bool ok = true;
				for(int i = 0; i < n; ++i)
				{
					if (t[i] > gap + timefromx(x[i], a))
					{
						ok = false;
						break;
					}
				}
				if (ok) r = gap; else l = gap;
			}
			ofs << fixed << setprecision(10) << l+timefromx(D, a) << endl;
		}

	}
	return 0;
}
