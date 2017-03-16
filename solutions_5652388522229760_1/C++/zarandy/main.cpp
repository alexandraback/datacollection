#include <cstdio>
#include <iostream>

using namespace std;

int n;
int t;
bool volt[10];
int vdb;
int k;
int l;

int main()
{
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		cin >> n;
		if (n == 0)
		{
			cout << "Case #" << i << ": INSOMNIA" << endl;
			continue;
		}
		for (int j = 0; j < 10; j++)
		{
			volt[j] = false;
		}
		vdb = 0;
		for (k = 1; k < 100; k++)
		{
			for (l = n * k; l > 0; l /= 10)
			{
				//cerr << "  " << l << ' ' << l % 10 << ' ' << volt[l % 10] << endl;
				if (!volt[l % 10])
				{
					volt[l % 10] = true;
					vdb++;
				}
			}
			//cerr << "     " << k << " " << vdb << endl;
			if (vdb == 10) break;
		}
		cout << "Case #" << i << ": " << n * k << endl;
	}
	return 0;
}
