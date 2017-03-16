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

using namespace std;

const int MAX = 1005;


int toInt (char c) 
{
	switch (c)
	{
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		default:
			return -1;
	}
}


int main()
{
	ifstream in ("in.in");
	ofstream out ("out.txt");

	int T;

	in >> T;

	for (int t = 1; t <= T; ++t) 
	{
		out << "Case #" << t << ": ";

		int n;
		int ad[MAX];
		char c;

		in >> n;

		for (int i = 0; i <= n; ++i)
		{
			in >> c;

			ad[i] = toInt(c);
		}

		long long sum = 0, res = 0;

		for (int i = 0; i <= n; ++i)
		{
			if (sum < i)
			{
				res += i - sum;
				sum += i - sum;
			}

			sum += ad[i];
		}

		out << res << endl;
	}

	out.close();
	return 0;
}