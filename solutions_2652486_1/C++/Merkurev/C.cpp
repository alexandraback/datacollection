#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
using namespace std;

int v[105];

int cnt[14];
int ans[12];
int x[12];

string gen()
{
	string answ = "";
	memset(ans, 0, sizeof ans);

	for (int i = 8; i >= 2; i--)
	{
		x[i] = cnt[i] / 6 + 1;
	}
	
	int cnt = 0;
	while (x[5] )
	{
		cnt++;
		ans[5]++;
		x[5]--;
	}
	while (x[7] )
	{
		cnt++;
		ans[7]++;
		x[7]--;
	}

	while (x[3] > x[6] && x[3] > 0 && cnt < 12)
	{
		cnt++;
		ans[3]++;
		x[3]--;
	}
	while (x[2] > 2 * x[4] && cnt < 12)
	{
		cnt++;
		ans[2]++;
		x[2]--;
	}
	while (x[6] > (ans[2] + ans[3] ) / 8 && cnt < 12)
	{
		x[6]--;
		cnt++;
		ans[6]++;
	}
	while (x[4] > x[8] && x[4] > ( ans[2] + ans[6] ) / 8 && cnt < 12 && x[4] > 0)
	{
		cnt++;
		ans[4]++;
		x[4]--;
	}
	while (cnt < 12)
	{
		cnt++;
		ans[8]++;
	}
	for (int i = 2; i <= 8; i++)
	{
		for (int j = 0; j < ans[i]; j++)
			answ.push_back(i + '0');
	}
	return answ;
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		printf("Case #%d: \n", t + 1);
		int r, n, m, k;
		scanf("%d%d%d%d", &r, &n, &m, &k);


		for (int i = 0; i < r; i++)
		{
			vector <int> muls;
			for (int j = 0; j < k; j++)
			{
				scanf("%d", &v[j] );
				multiset <int> curmuls;
				for (int h = 2; h <= 8; h++)
				{
					int x = v[j];
					while (x % h == 0)
					{
						x /= h;
						muls.push_back(h);
						curmuls.insert(h);
					}
				}
			}
			sort(muls.begin(), muls.end() );
			memset(cnt, 0, sizeof cnt);
			for (int j = 0; j < muls.size(); j++)
				cnt[muls[j] ]++;
			string ans = gen();
			printf("%s\n", ans.c_str() );

		}


	}



	return 0;
}