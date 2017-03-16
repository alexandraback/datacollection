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
	in.open("A-large.in");
	out.open("A-large.out");
	in >> t;
	for (int caseN = 1; caseN <= t; ++caseN)
	{
		in >> n;
		cout << caseN << ' ';
		vector< vector<bool> > tt;
		vector<bool> temp;
		temp.resize(n, false);
		tt.resize(n, temp);

		int m, cur;
		bool res = false;
		cout << 'n' << n << ' ';
		for (int i = 0; i < n; ++i)
		{
			in >> m;
			cout << 'm' << m << ' ';
			for (int j = 0; j < m; ++j)
			{
				in >> cur;
				--cur;
				cout << i << ' ' << cur << ' ';
				if (tt[i][cur])
					res = true;
				tt[i][cur] = true;
				for (int k = 0; k < n; ++k)
				{
					if (tt[cur][k])
					{
						if (tt[i][k])
							res = true;
						tt[i][k] = true;
					}
				}
			}
			for (int j = 0; j < n; ++j)
			{
				if (tt[i][j])
				for (int k = 0; k < n; ++k)
				{
					if (tt[k][i])
					{
						if (tt[k][j])
						{
							res = true;
						}
						tt[k][j] = true;
					}
				}
			}

		}


		cout << endl;
		out << "Case #" << caseN << ": ";
		if (res)
			out << "Yes" << endl;
		else
			out << "No" << endl;
	}

	out.close();
	in.close();
}

