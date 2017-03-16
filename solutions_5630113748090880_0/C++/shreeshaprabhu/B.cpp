#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;
map<int, int>::iterator it;

int main()
{
	int T, N, s;
	
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%d", &N);
		mp.clear();
		for (int i = 0; i < 2 * N - 1; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &s);
				it = mp.find(s);
				if (it == mp.end())
					mp.insert(make_pair(s, 1));
				else
					it->second++;
			}
		}
		printf("Case #%d:", t);
		for (it = mp.begin(); it != mp.end(); it++)
		{
			if (it->second % 2 == 1)
				printf(" %d", it->first);
		}
		printf("\n");
	}
	
	return 0;
}