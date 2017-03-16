#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
using namespace std;

#define M 16

long long reverse(long long N)
{
	long long result = 0;
	while (N > 0)
	{
		result = result * 10 + N % 10;
		N = N / 10;
	}
	return result;
}

long long count(long long N)
{
	long long firstN = N;
	long long lastN = N % 10;
	long long countN = 1;
	while (firstN >= 10)
	{
		firstN = firstN / 10;
		++countN;
	}
	long long result = 0;
	long long ten[M], start[M];
	ten[0] = 1;
	start[0] = 0;
	for (int i = 1; i < M; ++i)
	{
		ten[i] = ten[i - 1] * 10;
		start[i] = ten[i];
	}
	long long current = 0;
	long long i = 0;
	while (current < N)
	{
		long long reuse = (i + 1) / 2 + (i + 1) % 2;
		long long first = 9;
		if (N < ten[i + 1])
		{
			long long revN = reverse(N);
			if (N % 10 == 0)
			{
				revN = reverse(N - 1);
			}
			long long reuseLow = revN % ten[reuse];
			//cout << revN << " " << reuseLow << " " << reuse << " " << reverse(((i == 0) ? 0 : ten[i]) + reuseLow) <<  endl;
			result += min(N - start[i], reuseLow + 1 + N - (reverse(start[i] + reuseLow)));
			current = N;
		}
		else
		{
			result += start[reuse] - 1;
			if (i > 0)
			{
				// reverse
				result += 1;
			}
			// count up to ten[i]
			result += start[i + 1] - (reverse(start[i] + start[reuse] - 1));
			//cout << reuse << " " << i << " " << reverse(ten[i] + ten[reuse] - 1) << " " << ten[i] + ten[reuse] - 1 << endl;
			++i;
			current = ten[i];
			//cout << i << " " << current << " " << result << endl;
		}
	}
	return result;
}

void Solve()
{
	long long N;
	cin >> N;
	cout << count(N);
	//cout << min<long long>(count(N), N % 10 > 0 ? count(reverse(N)) + 1 : N);
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cout << "Case #" << i + 1 << ": ";
		Solve();
		cout << endl;
	}
	return 0;
}