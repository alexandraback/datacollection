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

const int table[5][5] = {{0, 0, 0, 0, 0}, {0, 1, 2, 3 ,4}, {0, 2, -1, 4, -3}, {0, 3, -4, -1, 2}, {0, 4, 3, -2, -1}};

int toInt (char c)
{
	switch (c) 
	{
		case 'i':
			return 2;
		case 'j':
			return 3;
		case 'k':
			return 4;
		default:
			return -1;
	}
}

int sign (int val)
{
	if (val < 0)
		return -1;
	else if (val > 0)
		return 1;
	else 
		return 0;
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

		unsigned long long L, X;
		vector<int> word;

		in >> L >> X;

		word.clear();
		word.resize(L);

		char c;
		int check = -1;
		int temp;
		bool f = false;


		for (unsigned long long i = 0; i < L; ++i)
		{
			in >> c;
			temp = toInt(c);

			if (check == -1)
				check = temp;
			else
			{
				if (check != temp)
					f = true;
			}

			word[i] = temp;
		}

		if (!f)
		{
			out << "NO" << endl;
			continue;
		}

		if (L * X < 3 || L == 1)
		{
			out << "NO" << endl;
			continue;
		}

		int last = word[0], cur;
		int needed = 2;
		bool ans = false;
		int sgn;

		for (unsigned long long x = 0; x < X; ++x)
		{
			unsigned long long i;

			if (x == 0)
				i = 1;
			else 
				i = 0;

			for (; i < L; ++i)
			{
				if (last == needed)
				{
					if (needed != 4)
					{
						last = word[i];
						++needed;
						continue;
					}
				}

				cur = word[i];

				sgn = sign(cur * last);

				last = abs(last);
				cur = abs(cur);

				last = table[last][cur];

				last *= sgn;
			}
		}

		if (last == needed && needed == 4)
			ans = true;

		if (ans)
			out << "YES" << endl;
		else
			out << "NO" << endl;

	}

	out.close();
	return 0;
}