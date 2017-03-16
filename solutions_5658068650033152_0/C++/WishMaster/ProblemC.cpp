// ProblemB.cpp : Defines the entry point for the console application.
//

#include <fstream>

using namespace std;

int main()
{
	ifstream fi("C-small-attempt0.in");
	ofstream fo("c.out");

	int t;
	fi >> t;

	for (int i = 0; i < t; i++)
	{
		int n,m,k;

		fi >> n >> m >> k;

		fo << "Case #" << i+1 << ": ";

		int min = n*m;

		if (k < 5)
		{
			fo << k << endl;
		}
		else
		{
			for (int x = 1; x < n; x++)
			{
				double y_r = (double)(k - 2*x) / (x + 2);
				int y = ceil(y_r);

				int res = 2*x + 2*y;
				if ((y < m) && (res < min))
				{
					min = res;
				}
			}
			fo << min << endl;
		}
	}

	fi.close();
	fo.close();

	return 0;
}

