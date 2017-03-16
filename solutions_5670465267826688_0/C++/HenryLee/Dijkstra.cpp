#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

enum
{
	U = 1,
	I = 2,
	J = 3,
	K = 4
};

int product(int a, int b)
{
	int matrix[5][5] = {
		{0, 0, 0, 0, 0},
		{0, U, I, J, K},
		{0, I, -U, K, -J},
		{0, J, -K, -U, I},
		{0, K, J, -I, -U}
	};
	bool negative = false;

	if (a < 0)
	{
		a = -a;
		negative = negative^true;
	}

	if (b < 0)
	{
		b = -b;
		negative = negative^true;
	}

	if (negative)
		return (-matrix[a][b]);
	else
		return matrix[a][b];
}

using namespace std;

int main(void)
{
	int t;

	cin >> t;

	for (int i=1; i<=t; i++)
	{
		string sl;
		long long x;
		long long l;
		vector <int> vl;
		long long pt;
		int pd;
		bool foundi = false;
		bool foundj = false;
		bool foundk = false;

		cin >> l;
		cin >> x;

		cin >> sl;

		if (x > 16)
			x = x % 16 + 16;

		for (int j=0; j<x; j++)
		{
			for (long long k=0; k<sl.length(); k++)
			{
				if (sl[k] == 'i')
					vl.push_back(I);
				else if (sl[k] == 'j')
					vl.push_back(J);
				else
					vl.push_back(K);
			}
		}

		pt = 0;
		pd = U;

		for (long long j=pt; j<vl.size(); j++)
		{
			pd = product(pd, vl[j]);

			if (pd == I)
			{
				foundi = true;
				pt = j;
				break;
			}
		}

		pt += 1;
		pd = U;

		for (long long j=pt; j<vl.size(); j++)
		{
			pd = product(pd, vl[j]);

			if (pd == J)
			{
				foundj = true;
				pt = j;
				break;
			}
		}

		pt += 1;
		pd = U;
		for (long long j=pt; j<vl.size(); j++)
		{
			pd = product(pd, vl[j]);
		}
		if (pd == K)
		{
			foundk = true;
		}

		if (foundi && foundj && foundk)
			printf("Case #%d: YES\n", i);
		else
			printf("Case #%d: NO\n", i);
	}

	return 0;
}
