#include <iostream>
using namespace std;

long long int ipow(long long int a, long long int b)
{	if (b >= 0)
	{
		long long int ans = 1;
		for (long long int i = 0; i < b; i++)
		{
			ans *= a;
		}

		return ans;
	}
	else
	{
		return 1;
	}
}

long long int floorlog2(long long int b)
{
	if (b < 1)
	{
		return -1;
	}
	else
	{
		long long int count = 0;
		while (b > 1)
		{
			b /= 2;
			count += 1;
		}

		return (count);
	}
}

int main()
{
	long long int T;
	cin >> T;
	for (long long int i = 0; i < T; i++)
	{
		long long int B, K;
		cin >> B >> K;
		cout << "Case #" << i+1 << ": ";
		if ( (K*4) > ipow(2, B))
		{
			cout << "IMPOSSIBLE" << endl;
		}
		else
		{
			cout << "POSSIBLE" << endl;
			long long int answer[B][B];
			for (long long int j = 0; j < B; j++)
			{
				for (long long int k = 0; k < B; k++)
				{
					answer[j][k] = 0;
				}
			}

			for (long long int j = 0; j < B-1; j++)
			{
				answer[j][B-1] = 1;
			}

			long long int willuse = floorlog2(K);

			for (long long int j = 0; j < B; j++)
			{
				for (long long int k = 0; k < B; k++)
				{
					if ((k>j) && (k <= willuse))
					{
						answer[j][k] = 1;
					}
				}
			}

			long long int remainingcount = K - ipow(2, willuse);

			for (long long int j = willuse; j >= 0; j--)
			{
				if (remainingcount >= ipow(2, j - 1))
				{
					answer[j][willuse+1] = 1;
					remainingcount -= ipow(2, j - 1);
				}
			}

			for (long long int j = 0; j < B; j++)
			{
				for (long long int k = 0; k < B; k++)
				{
					cout << answer[j][k];
				}
				cout << endl;
			}

		}
	}	
}