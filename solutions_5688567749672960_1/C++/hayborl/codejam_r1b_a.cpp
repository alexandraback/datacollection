#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

ll reverse(ll N)
{
	ll res = 0;
	while (N != 0)
	{
		int tmp = N % 10;
		res = (res * 10 + tmp);
		N /= 10;
	}

	return res;
}

ll count(ll N)
{
	int cnt = 0;

	while (N != 0)
	{
		N /= 10;
		cnt++;
	}

	cnt /= 2;

	ll base = 1;
	while (cnt > 0)
	{
		base *= 10;
		cnt--;
	}

	return base;
}

ll solve(ll N)
{
	ll cnt = 0;
	while (N != 0)
	{
		while (reverse(N) >= N || N % 10 == 0)
		{
			if (N == 0)
			{
				break;
			}

			N--;
			cnt++;
		}

		if (N == 0)
		{
			break;
		}

		ll base = count(N);
 		ll tmp = (N / base) * base + 1;
		if (tmp < N)
		{
			cnt += N - tmp;
			N = tmp;
		}

		if (N % 10 == 0)
		{
			N--;
			cnt++;
		}
		else
		{
			N = reverse(N);
			cnt++;
		}
	}

	return cnt;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		ll N;
		cin >> N;

		cout << "Case #" << i << ": " << solve(N) << endl;
	}

	return 0;
}