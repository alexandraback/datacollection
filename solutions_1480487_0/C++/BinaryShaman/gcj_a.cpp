#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t, n, s, p;
	ifstream in;
	ofstream out;
	in.open("A-small-attempt2.in");
	out.open("A-small-attempt2.out");
	in >> t;
	for (int caseN = 1; caseN <= t; ++caseN)
	{
		double result = 1.0;
		cout << caseN << ' ';

		in >> n;
		vector<int> sm;
		vector<int> smo;
		vector<int> smoo;
		vector<double> smd;
		int ss;
		int m = 0;
		int tm;
		for (int i = 0; i < n; ++i)
		{
			in >> ss;
			m += ss;
			sm.push_back(ss);
			smo.push_back(ss);
			smoo.push_back(ss);
			smd.push_back(0.0);
		}

		tm = m;
		sort(smo.begin(), smo.end());
		sort(smoo.begin(), smoo.end());
		while (tm)
		{
			int cur = smo[0];
			int i = 1;
			for ( i = 1; i < n, smo[i] == cur; ++i);
			cout << i << ' ';

			if (i == n)
			{
				for (int j = 0; j < n; ++j)
					smd[j] += (double) tm / (double) n;
				tm = 0;
			}
			else
			{
				int tmcur = (smo[i] - smo[0]) * i;
				if (tmcur > tm)
					tmcur = tm;
				for (int j = 0; j < i; ++j)
				{
					smd[j] += (double) tmcur / (double) i;
					smo[j] += (double) tmcur / (double) i;
				}
				tm -= tmcur;
			}
			for (int j = 0; j < n; ++j)
				cout << smo[j] << ' ';
			cout << endl;
		}

		out << "Case #" << caseN << ": ";
		out.precision(6);
		for (int i = 0; i < n; ++i)
		{
			vector<int>::iterator it = find(smoo.begin(), smoo.end(), sm[i]);
			double d = smd[it - smoo.begin()];
			result = (double) d / (double) (m) * 100;
			out << fixed << result << ' ';
		}
		out << endl;
	}

	out.close();
	in.close();
}

