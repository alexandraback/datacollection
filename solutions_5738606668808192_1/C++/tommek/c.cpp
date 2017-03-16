#include <bits/stdc++.h>

using namespace std;

long long v[1005], divi[11];
long long pot[1005][1005][11];

set<vector<long long> > V;

int main()
{
	srand(42);

	for (int r = 1; r <= 1004; ++ r)
	{	
		for (int i = 2; i <= 10; ++ i)
		{
			pot[0][r][i] = 1;
			for (int j  = 1; j <= 1004; ++ j)
			{
				pot[j][r][i] = (pot[j-1][r][i] * i) % r;
			}
		}
	}
	
	int ttte; scanf("%d", &ttte); for (int ttt = 1; ttt <= ttte; ++ ttt)
	{	
		printf("Case #%d: \n", ttt);

		int n, j; scanf("%d%d", &n, &j);
		while (j)
		{
			vector<long long> wekt;

			v[0] = v[n-1] = 1;
			for (int i = 1; i < n-1; ++ i)
			{
				v[i] = rand()%2;
				wekt.push_back(v[i]);
			}

			if (V.find(wekt) != V.end())
			{
				continue;
			}
			else
			{
				V.insert(wekt);
			}
			
			bool czy = true;
			for (int base = 2; base <= 10; ++ base)
			{
				divi[base] = -1;
				for (int r = 2; r <= 1004; ++ r)
				{
					long long val = 0;
					for (int i = 0; i < n; ++ i)
					{
						if (v[i])
						{
							val = (val + pot[i][r][base]) % r;
						}
					}		
					if (val == 0)
					{
						divi[base] = r;
						break;
					}
				}			
				if (divi[base] == -1)
				{
					czy = false;
					break;
				}
			}
			
			if (czy)
			{
				-- j;
				for (int i = n-1; i >= 0; -- i)
				{
					printf("%lld", v[i]);
				}
				for (int i = 2; i <= 10; ++ i)
				{
					printf(" %lld", divi[i]);
				}
				printf("\n");
			}
		}		
	}
}
