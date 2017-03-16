#include <fstream>

using namespace std;

int main()
{
	ifstream fin("C-small-attempt0.in");
	ofstream fout("out.txt");

	int t;
	fin >>t;
	for (int i = 1; i <= t; i++)
	{
		int N;
		long TW[1001] = {0}, RH[1001] = {0};
		long d[1000], n[1000], w[1000], e[1000], s[1000], dd[1000], dp[1000], ds[1000], now[1000] = {0};
		long aa = 0, ac = 0, nd = 0, as = 0;
		fin >>N;
		for (int j = 0; j < N; j++)
		{
			fin >>d[j] >>n[j] >>w[j] >>e[j] >>s[j] >>dd[j] >>dp[j] >>ds[j];
			aa += n[j];
		}
		while (ac < aa)
		{
			for (int j = 0; j < N; j++)
			{
				if (now[j] == n[j])
				{
					continue;
				}
				if (d[j] + now[j] * dd[j] == nd)
				{
					bool flag = false;
					for (int k = w[j] * 2 + 500; k < e[j] * 2 + 500; k++)
					{
						if (s[j] > TW[k])
						{
							as++;
							flag = true;
							break;
						}
					}
					if (flag)
					{
						for (int k = w[j] * 2 + 500; k < e[j] * 2 + 500; k++)
						{
							if (s[j] > RH[k])
							{
								RH[k] = s[j];
							}
						}
					}
					s[j] += ds[j];
					w[j] += dp[j];
					e[j] += dp[j];
					now[j]++;
					ac++;
				}
			}
			for (int j = 0; j < 1001; j++)
			{
				TW[j] = RH[j];
			}
			nd++;
		}

		fout <<"Case #" <<i <<": " <<as <<endl;
	}

	return 0;
}