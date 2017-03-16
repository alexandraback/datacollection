#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;


int main()
{
	//ifstream infile("test.in");
	//ifstream infile("A-small-attempt0.in");
	//ifstream infile("A-small-attempt1.in");
	ifstream infile("A-large.in");
	ofstream outfile("A.out", ios::out);
	int T;
	infile >> T;
	int testcase;
	for (testcase = 1;testcase <= T;testcase++)
	{
		int a, n;
		infile >> a >> n;
		int i, j;
		int x[110];
		for (i = 0;i < n;i++)
			infile >> x[i];

		sort(x, x + n);
		int Min = 1000;
		int re = a;
		for (i = 0;i <= n;i++)
		{
			int cnt = 0;
			a = re;
			for (j = 0;j < n - i;j++)
			{
				if (a > x[j])
					a += x[j];
				else
				{
					while (a <= x[j])
					{
						a = a + a - 1;
						cnt ++;
						if (cnt > n)
							break;
					}
					a += x[j];
				}
			}
			if (Min > cnt + i)
				Min = cnt + i;
		}
		outfile << "Case #" << testcase << ": ";
		outfile << Min;
		outfile << endl;
	}
	return 0;
}