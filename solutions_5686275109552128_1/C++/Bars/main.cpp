#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <memory.h>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <functional>

using namespace std;

const int MAX = 1005;


int main()
{
	ifstream in ("in.in");
	ofstream out ("out.txt");

	int T;

	in >> T;


	for (int t = 1; t <= T; ++t) 
	{
		out << "Case #" << t << ": ";

		int p[MAX];
		int D;

		in >> D;

		int maxTime = 0;

		for (int i = 0; i < D; ++i)
		{
			in >> p[i];

			maxTime = max(p[i], maxTime);
		}

		int res = maxTime;

		for (int m = 1; m <= maxTime; ++m)
		{
			int temp = 0;

			for (int i = 0; i < D; ++i)
				if (p[i] > m) 
					temp += (p[i] + m - 1) / m - 1;

			res = min(res, m + temp);
		}

		out << res << endl;
	}

	out.close();
	return 0;
}

void solve()
{

}