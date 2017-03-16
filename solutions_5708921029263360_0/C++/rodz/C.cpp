#include <bits/stdc++.h>

using namespace std;

int ja, pa, sh, kk, ans;
vector<int> comb[3];
vector<int> vans;
vector<int> vmask[30];

int main()
{
	int T, tcnt = 0;

	scanf("%d", &T);
	while(T--)
	{
		comb[0].clear();
		comb[1].clear();
		comb[2].clear();
		ans = 0;
		vans.clear();

		scanf("%d %d %d %d", &ja, &pa, &sh, &kk);
		for (int i = 1; i <= ja; i++)
		{
			for (int j = 1; j <= pa; j++)
			{
				for (int k = 1; k <= sh; k++)
				{
					comb[0].push_back(i);
					comb[1].push_back(j);
					comb[2].push_back(k);
				}
			}
		}

		int japa[4][4] = {0}, jash[4][4] = {0}, pash[4][4] = {0};
		for (int i = 0; i < comb[0].size(); i++)
		{
			int cja = comb[0][i], cpa = comb[1][i], csh = comb[2][i];
			if (japa[cja][cpa] == kk or jash[cja][csh] == kk or pash[cpa][csh] == kk)
				continue;
			vans.push_back(i);
			ans++;
			japa[cja][cpa]++;
			jash[cja][csh]++;
			pash[cpa][csh]++;
		}
		printf("Case #%d: %d\n", ++tcnt, ans);
		for (int i = 0; i < vans.size(); i++)
		{
			int id = vans[i];
			printf("%d %d %d\n", comb[0][id], comb[1][id], comb[2][id]);
		}
	}
	return 0;
}
