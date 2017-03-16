#include <iostream>
#include <algorithm>


using namespace std;

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int t;
	scanf("%d ", &t);

	for (int k = 0; k < t; k++)
	{

		long long A,N;
		scanf("%lld %lld ", &A, &N);
		long long res = 100000;
		long long mas[105] = {0};
		
		for (int i = 0; i < N; i++)
			scanf("%lld ", &mas[i]);
		sort(mas, mas + N);

		for (int i = N; i >= 0; i--)
		{
			long long mest = N - i;
			long long cur = A;
			for (int j = 0; j < i; j++)
			{
				if (cur > mas[j])
					cur += mas[j];
				else
				{
					if (cur == 1)
					{
						mest = 100000;
						break;
					}
					while (cur <= mas[j])
					{
						cur = cur + cur - 1;
						mest++;
					}
					cur += mas[j];
				}
			}

			res = __min(res, mest);
		}

		printf("Case #%d: %lld\n", k + 1, res);
	}
	return 0;
}