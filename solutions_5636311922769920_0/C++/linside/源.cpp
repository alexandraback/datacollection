#include <iostream>
#include <fstream>
using namespace std;
ofstream fout("output.out");
int main()
{
	int t;
	int k, c, s;
	cin >> t;
	for (int i = 1;i <= t;i++)
	{
		cin >> k >> c >> s;
		fout << "Case #" << i << ":";
		if (c - 1 == 0 && k > s)
		{
			fout << " IMPOSSIBLE";
		}
		else
		{
			int d;
			if (c - 1 == 0)
			{
				d = s;
			}
			else
			{
				d = ceil(double(k) / double(c));
			}
			long long int m = 1;
			for (int j = 0;j < d;j++)
			{
				long long int n = 1;
				for (int h = 1;h <= c;h++)
				{	
					n = (n - 1) * k + m;
					if (m == k) break;
					m++;
				}
				fout << " " << n;
			}
		}
		fout << endl;
	}
	return 0;
}