#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int x = 0;

int main()
{
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int T, N, S, p;
	int tmp, re;
	cin >> T;
	while (T--)
	{
		cin >> N >> S >> p;
		re = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> tmp;
			if (tmp-p < 0)
			{
				continue;
			}
			if (tmp-p >= 2*(p-1))
			{
				re++;
			}
			else if (S > 0 && tmp-p >= 2*(p-2))
			{
				re++;
				S--;
			}
		}
		cout << "Case #" << ++x << ": ";
		cout << re << '\n';
	}
	return 0;
}
