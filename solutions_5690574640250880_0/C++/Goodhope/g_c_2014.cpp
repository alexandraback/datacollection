// gj.cpp
//

#include <assert.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <utility>

using namespace std;

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned __int64 uint64;

#define EPS (1E-10)
#define PI 3.1415926535897932384626433832795

char b[50][51];

int main(int argc, char* argv[])
{
	uint64 cases;
	cin >> cases;

	for (uint64 i = 1; i <= cases; ++i)
	{
		uint r, c, m;
		cin >> r >> c >> m;

		bool ok = true;

		if (c == 1 || r == 1)
		{
			uint cm = 0;
			for (uint j = 0; j < r; ++j)
			{
				for (uint k = 0; k < c; ++k)
				{
					b[j][k] = cm < m ? '*' : '.';
					++cm;
				}
			}
		}
		else if (c == 2 || r == 2)
		{
			if (m & 1 && m != r * c - 1 || m == r * c - 2)
				ok = false;
			else
			{
				uint cm = 0;
				bool sw = false;
				if (c > 2)
				{
					swap(r, c);
					sw = true;
				}

				for (uint j = 0; j < r; ++j)
				{
					for (uint k = 0; k < c; ++k)
					{
						if (sw)
							b[k][j] = cm < m ? '*' : '.';
						else
							b[j][k] = cm < m ? '*' : '.';
						++cm;
					}
				}

				if (sw)
					swap(r, c);
			}
		}
		else
		{
			uint fr = r * c - m;
			if (fr == 2 || fr == 5 || fr == 3 || fr == 7)
				ok = false;
			else
			{
				for (uint j = 0; j < r; ++j)
				{
					for (uint k = 0; k < c; ++k)
						b[j][k] = '.';
				}

				bool sw = false;
				if (r < c)
				{
					swap(r, c);
					sw = true;
				}

				uint fl = m / c;
				if (r - fl < 3)
					fl = r - 3;

				for (uint j = 0; j < fl; ++j)
				{
					for (uint k = 0; k < c; ++k)
					{
						if (sw)
							b[k][j] = '*';
						else
							b[j][k] = '*';
					}
				}

				uint cm = m - fl * c;
				uint fc = cm / (r - fl);

				for (uint j = fl; j < r; ++j)
				{
					for (uint k = 0; k < fc; ++k)
					{
						if (sw)
							b[k][j] = '*';
						else
							b[j][k] = '*';
					}
				}

				cm -= fc * (r - fl);

				if (cm > 0)
				{
					uint er = r - fl,
						 ec = c - fc,
						 ecl = er * ec;

					if (ecl > 9)
					{
						for (uint j = fl; cm && j < r - 2; ++j)
						{
							for (uint k = fc; cm && k < c - 2; ++k)
							{
								if (sw)
									b[k][j] = '*';
								else
									b[j][k] = '*';

								--cm;
							}
						}
					}
					else
					{
						if (ecl == 3 && cm == 2)
						{
							if (sw)
							{
								b[c - 1][r - 2] = '*';
								b[c - 1][r - 3] = '*';
							}
							else
							{
								b[r - 2][c - 1] = '*';
								b[r - 3][c - 1] = '*';
							}
						}
						else if (ecl == 6)
						{
							if (sw)
							{
								b[c - 2][r - 3] = '*';
								b[c - 1][r - 3] = '*';
							}
							else
							{
								b[r - 3][c - 2] = '*';
								b[r - 3][c - 1] = '*';
							}
						}
						else if (ecl == 9)
						{
							if (sw)
								b[c - 3][r - 3] = '*';
							else
								b[r - 3][c - 3] = '*';
						}
					}
				}

				if (sw)
					swap(r, c);
			}
		}

		b[r - 1][c - 1] = 'c';

		if (ok)
		{
			cout << "Case #" << i << ":\n";
			for (uint j = 0; j < r; ++j)
			{
				cout << b[j][0];
				for (uint k = 1; k < c; ++k)
					cout << b[j][k];
				cout << endl;
			}
		}
		else
			cout << "Case #" << i << ":\nImpossible\n";
	}

	return 0;
}
