#include <iostream>

using namespace std;

long long powArr[50];

long long getPowOfTwo(int exp)
{
	return powArr[exp];
}

void setPowOfTwo(int toExp)
{
	for (int i = 0; i <= toExp; ++i)
	{
		powArr[i] = (long long)1 << i;
	}
}

int setPart(char* part, long long num)
{
	int i = 0;
	while (true)
	{
		if (num % 2 == 1)
		{
			part[i] = '1';
		}
		else
		{
			part[i] = '0';
		}
		i++;
		num /= 2;
		if (num == 0)
		{
			break;
		}
	}
	part[i] = '\0';
	return i; // len
}

int main(void)
{
	char part[51];
	char mat[50][51];
	setPowOfTwo(49);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc)
	{
		int B, M;
		cin >> B >> M;

		long long max = getPowOfTwo(B - 2);
		if (M <= max)
		{
			cout << "Case #" << tc << ": POSSIBLE" << endl;
			// 예시셋팅(1 way)
			// 최하단
			for (int k = 0; k < B; ++k)
			{
				mat[B-1][k] = '0';
			}
			mat[B - 1][B] = '\0';

			// 최하단 제외
			int curMaxExp = 0;
			long long curMax = 1;
			bool last = false;
			for (int i = B - 2; i >= 0; --i)
			{
				if (last)
				{
					for (int k = 0; k < B; ++k)
					{
						if (k - i == 1)
						{
							mat[i][k] = '1';
						}
						else
						{
							mat[i][k] = '0';
						}
					}
					mat[i][B] = '\0';
					continue;
				}

				// 각 라인별 가득 채우는 케이스
				if (M >= curMax)
				{
					for (int k = 0; k < B; ++k)
					{
						if (k > i)
						{
							mat[i][k] = '1';
						}
						else
						{
							mat[i][k] = '0';
						}
					}
					mat[i][B] = '\0';
					curMax <<= 1;
					curMaxExp++;
					continue;
				}

				last = true;

				for (int k = 0; k < B; ++k)
				{
					if (k <= i)
					{
						mat[i][k] = '0';
						continue;
					}

					// upper

					// 해당 라인 세밀하게 채우자.
					if (k - i == 1)
					{
						mat[i][k] = '1';
					}
					else
					{
						mat[i][k] = '0';
					}
				}

				if (last && M > 1)
				{
					int len = setPart(part, M - (curMax / 2));
					for (int a = 0; a < len; ++a)
					{
						mat[i][B - a - 2] = part[a];
					}
				}

				mat[i][B] = '\0';
				curMax <<= 1;
				curMaxExp++;

			}

			// 예시출력
			for (int i = 0; i < B; ++i)
			{
				cout << mat[i] << endl;
			}

		}
		else
		{
			cout << "Case #" << tc << ": IMPOSSIBLE" << endl;
		}

	}
	return 0;
}
