#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stdio.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );

	int t;
	cin >> t;
	for( int tt = 1; tt <= t; tt++ )
	{
		long long n;
		cin >> n;
		int set = 0;

		if (n == 0)
		{
			cout << "Case #" << tt << ": INSOMNIA" << endl;
			continue;
		}

		for (int i = 1; ;i++)
		{
			long long curN = n * i;
			while (curN > 0)
			{
				set |= 1 << (curN % 10);
				curN /= 10;
			}

			if (set == (1 << 10) - 1)
			{
				cout << "Case #" << tt << ": " << n * i << endl;
				break;
			}
		}
	}
	return 0;
}