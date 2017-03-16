#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <cstdlib>
#include <numeric>
#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long lint;

int n;
int m;
std::vector<int> type[2];
std::vector<lint> amount[2];

lint Solve()
{
	std::vector<std::vector<lint> > dp(n + 1, std::vector<lint>(m + 1));
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{			
			lint capacity = 0;
			dp[i][j] = dp[i - 1][j - 1];
			for(int k = j; k >= 1; k--)
			{
				if(type[1][k - 1] == type[1][j - 1])
				{
					capacity += amount[1][k - 1];
				}

				lint take = 0;
				for(int l = i; l >= 1 && take <= capacity; l--)
				{
					if(type[0][l - 1] == type[1][j - 1])
					{
						take += amount[0][l - 1];
					}

					dp[i][j] = std::max(dp[i][j], dp[l - 1][k - 1] + std::min(take, capacity));
				}
			}
		}
	}

	return *std::max_element(dp.back().begin(), dp.back().end());
}

int main(int argc, char * argv[])
{
	int testCount;
	freopen("in.txt", "r", stdin);
	std::cin >> testCount;
	for(int test = 1; test <= testCount; test++)
	{
		std::cin >> n >> m;
		int cnt[] = {n, m};
		for(int k = 0; k < 2; k++)
		{
			amount[k].assign(cnt[k], 0);
			type[k].assign(cnt[k], 0);
			for(int i = 0; i < cnt[k]; i++)
			{
				std::cin >> amount[k][i] >> type[k][i];
			}
		}

		std::cout << "Case #" << test << ": " << Solve() << std::endl;
	}

	return 0;
}