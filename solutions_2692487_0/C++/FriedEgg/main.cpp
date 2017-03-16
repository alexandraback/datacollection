/*
 * main.cpp
 *
 *  Created on: 2013-5-5
 *      Author: chenjd
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

#define File
#ifdef File
#define cin fin
#define cout fout
#endif

using namespace std;

int main()
{
#ifdef File
	ifstream fin("in.txt");
	ofstream fout("out.txt");
#endif

	int test_case;
	int test;
	cin >> test_case;
	for (test = 1; test <= test_case; test++)
	{
		long a;
		long n;
		long other[101];
		long times[101] = { 0 };
		long min = 100;
		cin >> a >> n;
		other[0] = a;
		for (int i = 1; i <= n; i++)
			cin >> other[i];
		if (a > 1)
		{
			sort(other + 1, other + n + 1);
			for (int i = 1; i <= n; i++)
			{
				if (a > other[i])
				{
					a += other[i];
					times[i] = times[i - 1];
					continue;
				}
				int k;
				k = log(double(other[i]) / double(a - 1)) / log(2);
				for (; k < 32; k++)
				{
					if ((int(pow(2.0000, k)) * (a - 1) + 1) > other[i])
					{
						break;
					}
				}
				a = int(pow(2.0000, k)) * (a - 1) + 1 + other[i];
				times[i] = times[i - 1] + k;
			}
			for (int i = 0; i <= n; i++)
			{
				if (times[i] + n - i < min)
					min = times[i] + n - i;
			}
		}
		else
		{
			min = n;
		}
		cout << "Case #" << test << ": " << min << endl;
	}

#ifdef File
	fin.close();
	fout.close();
#endif
	return 0;
}
