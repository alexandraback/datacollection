#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

const int N = 4;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	cout.precision(8);
	for (int k = 0; k < t; ++k)
	{
		double c, f, x;
		
		cin >> c >> f >> x;
		
		double r1 = x/2.0;
		double r2 = c/2.0+x/(f+2.0);
		int i = 0;
		while (r2 < r1)
		{
			++i;
			r1 = r2;
			r2 = 0;
			for (int j = 0; j <= i; ++j)
			{
				r2 += c / (2.0 + j*f);
			}
			r2 += x / (2.0 + (i + 1)*f);
		}


		printf("Case #%i: ", k + 1);
		cout << r1 << endl;
	}


	return 0;
}
