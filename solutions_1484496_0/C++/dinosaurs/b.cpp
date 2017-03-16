#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int MAXN = 555;

map<int, vector<int> > sums;
int T, N, vals[MAXN];

int main()
{
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		sums.clear();
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
			scanf("%d", &vals[i]);
		for(int i = 0; i < (1 << N); i++)
		{
			int s = 0;
			for(int j = 0; j < N; j++)
				if((1 << j) & i)
					s += vals[j];
			if(sums.find(s) == sums.end())
				sums[s] = vector<int>();
			sums[s].push_back(i);
		}
		int best_i, best_j;
		bool good = false;
		for(map<int, vector<int> >::iterator it = sums.begin(); !good && it != sums.end(); it++)
		{
			vector<int> cur = (*it).second;
			for(int a = 0; a < cur.size() && !good; a++)
				for(int b = a + 1; b < cur.size() && !good; b++)
					if((cur[a] | cur[b]) == cur[a] + cur[b])
					{
						good = true;
						best_i = cur[a];
						best_j = cur[b];
					}
		}
		if(!good)
			printf("Case #%d:\nImpossible\n", t);
		else
		{
			vector<int> a, b;
			for(int i = 0; i < N; i++)
			{
				if((1 << i) & best_i)
					a.push_back(vals[i]);
				else if((1 << i) & best_j)
					b.push_back(vals[i]);
			}
			printf("Case #%d:\n", t);
			for(int i = 0; i < a.size(); i++)
			{
				printf("%d", a[i]);
				if(i == a.size() - 1) printf("\n");
				else printf(" ");
			}
			for(int i = 0; i < b.size(); i++)
			{
				printf("%d", b[i]);
				if(i == b.size() - 1) printf("\n");
				else printf(" ");
			}
		}
	}
	return 0;
}
