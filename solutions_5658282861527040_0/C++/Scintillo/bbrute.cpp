#include <iostream>

using namespace std;

int solveCase()
{
	int a, b, k;
	cin >> a >> b >> k;
	a--;
	b--;
	k--;

	int total = 0;

	for(int i = 0; i <= a; i++)
	{
		for(int j = 0; j <= b; j++)
		{
			if((i & j) <= k)
				total++;
		}
	}

	return total;
}

int main()
{
	int n;
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		int res = solveCase();

		cout << "Case #" << i << ": ";
		cout << res;
		cout << endl;
	}

	return 0;
}