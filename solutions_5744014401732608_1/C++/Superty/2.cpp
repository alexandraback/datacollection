#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <list>
#include <queue>
#include <map>
#include <stack>
#include <cmath>
#include <cstring>
#include <tuple>
#include <cassert>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for(int cs = 1; cs <= t; cs++)
	{
		long long b, m;
		cin >> b >> m;
		cout << "Case #" << cs << ": ";
		if(m > (1ll << (b - 2))) cout << "IMPOSSIBLE\n";
		else
		{
			cout << "POSSIBLE\n";
			int g[55][55] = { };
			for(int i = 2; i <= b; i++)
			{
				for(int j = 1; j <= b; j++)
				{
					g[i][j] = (i < j);
				}
			}
			m--;
			g[1][b] = 1;
			for(int i = b - 1; i >= 2; i--)
			{
				g[1][i] = (m % 2);
				m /= 2;
			}
			for(int i = 1; i <= b; i++)
			{
				for(int j = 1; j <= b; j++)
				{
					cout << g[i][j];
				} cout << '\n';
			}
		}			
	}

	return 0;
}