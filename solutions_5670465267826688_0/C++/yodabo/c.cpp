// c.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int i = 2;
int j = 3;
int k = 4;

bool xor(bool a, bool b)
{
	return ((!a) && b) || ((!b) && a);
}

int mul(int a, int b)
{
	int sign = xor((a < 0), (b < 0)) ? -1 : 1;
	a = abs(a);
	b = abs(b);

	int table[5][5] = {
		{ 0, 0, 0, 0, 0 },
		{ 0, 1, i, j, k },
		{ 0, i, -1, k, -j },
		{ 0, j, -k, -1, i },
		{ 0, k, j, -i, -1 }
	};

	return sign * table[a][b];
}

void Check(int x)
{
	if (x != i && x != j && x != k)
	{
		int x = 5;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int T;
	cin >> T;

	for (int n = 0; n < T; ++n)
	{
		if (n == 57)
		{
			int z = 0;
		}
		int L; // number of characters
		long long X; // repeat count
		cin >> L;
		cin >> X;
		
		// read whitespace characters
		char c;
		do
		{
			c = cin.get();
		} while (c != 'i' && c != 'j' && c != 'k');

		int start = 1; // initial value of our string

		vector<int> values;
		values.reserve(L); // avoid some allocations
		int val = i + c - 'i';
		values.push_back(val);
		start = mul(start, val);
		for (int l = 1; l < L; ++l)
		{
			c = cin.get();
			val = i + c - 'i';
			start = mul(start, val);
			values.push_back(val);
		}

		int expReduced = (int)(X % 8); // regardless of what the value is, if it is repeated 4 times, we can multiply the string by itself 4 times to get 1 (1^4=i^4=j^4=k^4=1)
		val = 1;
		for (int l = 0; l < expReduced; ++l)
		{
			val = mul(start, val);
		}
		bool skip = (val != -1); // i*j*k = 1
		if (!skip)
		{
			// now we have a list we can use, and the value works out correctly - just need to find i/k at the beginning/end
			bool foundi = false;
			val = 1;
			int numBeforeI = 0;
			// find i at the begining
			for (int l = 0; l < 8 && !foundi; ++l)
			{
				for (int m = 0; m < values.size(); ++m)
				{
					val = mul(val, values[m]);
					if (val == i)
					{
						foundi = true;
						numBeforeI = 1 + m + values.size()*l;
						break;
					}
				}
			}
			int numAfterK = 0;
			// find k at the end
			bool foundk = false;

			if (foundi)
			{
				val = 1;
				for (int l = 0; l < 8 && !foundk; ++l)
				{
					for (int m = 0; m < values.size(); ++m)
					{
						val = mul(values[values.size() - 1 - m], val);
						if (val == k)
						{
							foundk = true;
							numAfterK = 1 + m + values.size()*l;
							break;
						}
					}
				}
			}

			long long numForJ = (long long)X * (long long)L - ((long long)numBeforeI + (long long)numAfterK);
			
			if (foundi && foundk && (numForJ > 0))
			{
				// we found it
			}
			else
			{
				skip = true;
			}

		}

		// validate either way:
		/*bool fi = false;
		bool fj = false;

		val = 1;
		for (long long b = 0; b < X; ++b)
		{
			for (long long a = 0; a < L; ++a)
			{
				val = mul(val, values[a]);
				if (!fi && val == i)
				{
					val = 1;
					fi = true;
				}
				else if (fi && !fj && val == j)
				{
					val = 1;
					fj = true;
				}
			}
		}
		bool slowAnswer = (fi && fj && (k == val));
		if ((slowAnswer && skip) || (!slowAnswer && !skip))
		{
			int x = 0;
		}*/

		cout << "Case #" << (1+n) << ": " << (skip ? "NO" : "YES") << endl;

	}

	return 0;
}

