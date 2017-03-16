#include <iostream>
#include <cstdio>

using namespace std;
typedef long long int ll;


int t;
int b;
ll m;
ll z;
ll x;
bool s[51][51];

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cin >> b >> m;
		//cerr << b << ' ' << m << endl;
		z = 1;
		for (int i = 1; i < b; i++)
		{
			z <<= 1;
			for (int j = i + 1; j <= b; j++)
			{
				s[i][j] = true;
			}
		}
		z >>= 1;
		if (z < m)
		{
			//cerr << z << ':' << m << endl;
			cout << "Case #" << tt << ": IMPOSSIBLE" << endl;
		}
		else
		{	
			x = z - m;
			z >>= 1;
			for (int i = b - 1; i > 1; i--)
			{
				if (x & z)
				{
					s[i][b] = false;
				}
				z >>= 1;
			}
			cout << "Case #" << tt << ": POSSIBLE" << endl;
			for (int i = 1; i <= b; i++)
			{
				for (int j = 1; j <= b; j++)
				{
					cout << s[i][j];
				}
				cout << endl;
			}
		}
	}
	return 0;
}
