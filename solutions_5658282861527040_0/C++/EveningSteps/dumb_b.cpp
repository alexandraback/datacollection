#include <utility>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int t, a, b, k, total;
	cin >> t;
	for (int q = 0; q < t; ++q)
	{
		cin >> a >> b >> k;
		total = 0;
		for (int i = 0; i < a; ++i)
			for (int j = 0; j < b; ++j)
			{
				if ((i & j) < k)
					++total;
			}
		
		cout << "Case #" << q+1 << ": " << total << endl;
	}
	
	return 0;
}
