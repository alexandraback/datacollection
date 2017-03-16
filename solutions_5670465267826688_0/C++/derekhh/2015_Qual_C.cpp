//Problem C. Dijkstra

#include <iostream>
#include <string>
using namespace std;

int val[5][5] = 
{
	{ 0, 0, 0, 0, 0 },
	{ 0, 1, 2, 3, 4 },
	{ 0, 2, -1, 4, -3 },
	{ 0, 3, -4, -1, 2 },
	{ 0, 4, 3, -2, -1 }
};

int foo(int i,int j)
{
	int sign = 1;
	if (i < 0) sign *= -1;
	if (j < 0) sign *= -1;
	return sign * val[i > 0 ? i : -i][j > 0 ? j : -j];
}

int f[100000], nf;

int main()
{
	int t, kase = 0;
	cin >> t;
	while (t--)
	{
		kase++;
		int l, x;
		string str;
		cin >> l >> x >> str;
		nf = 0;
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < l; j++)
			{
				if (str[j] == 'i') f[nf++] = 2;
				else if (str[j] == 'j') f[nf++] = 3;
				else f[nf++] = 4;
			}
		}
		int tot = 1;
		for (int i = 0; i < nf; i++)
			tot = foo(tot, f[i]);
		if (tot != -1)
		{
			cout << "Case #" << kase << ": NO" << endl;
			continue;
		}

		tot = 1;
		int idx1 = -1, idx2 = -1;
		for (int i = 0; i < nf; i++)
		{
			tot = foo(tot, f[i]);
			if (tot == 2)
			{
				idx1 = i;
				break;
			}
		}
		if (idx1 == -1)
		{
			cout << "Case #" << kase << ": NO" << endl;
			continue;
		}
		tot = 1;
		for (int i = idx1 + 1; i < nf; i++)
		{
			tot = foo(tot, f[i]);
			if (tot == 3)
			{
				idx2 = i;
				break;
			}
		}
		if (idx2 == -1)
		{
			cout << "Case #" << kase << ": NO" << endl;
			continue;
		}
		cout << "Case #" << kase << ": YES" << endl; 
	}
	return 0;
}