#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <list>
#include <queue>
#include <map>
#include <stack>
#include <cmath>
#include <cstring>
#include <tuple>
#include <cassert>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for(int cs = 1; cs <= t; cs++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int ans = 0;
		int ijcnt[11][11] = { }, jkcnt[11][11] = { }, ikcnt[11][11] = { };
		vector<tuple<int,int,int>> l;
		bool used[11][11][11] = { };
		for(int i = 1; i <= a; i++)
		{
			for(int j = 1; j <= b; j++)
			{
				while(ijcnt[i][j] < d)
				{
					int lo = d, seclo = d, lopos = -1;
					for(int k = 1; k <= c; k++)
					{
						if(!used[i][j][k] && jkcnt[j][k] < d)
						{
							if(ikcnt[i][k] < lo || (ikcnt[i][k] == lo && jkcnt[j][k] < seclo))
							{
								lo = ikcnt[i][k];
								seclo = jkcnt[j][k];
								lopos = k;
							}

						}
					}
					//cout << i << ' ' << j << ' ' << lopos << " | " << lo << '\n';
					if(lo == d) break;
					ijcnt[i][j]++;
					jkcnt[j][lopos]++;
					ikcnt[i][lopos]++;
					ans++;
					l.push_back(make_tuple(i, j, lopos));
					used[i][j][lopos] = true;
				}
			}
		}
		cout << "Case #" << cs << ": " << ans << '\n';
		for(auto x : l)
		{
			int i, j, k;
			tie(i, j, k) = x;
			cout << i << ' ' << j << ' ' << k << '\n';
		}
	}

	return 0;
}