#include <stdio.h>
#include <math.h>
#include <map>
#include <vector>
#include <time.h>
using namespace std;

map<int, map<int, int> > mp;
map<int, map<int, int> >::iterator it;
vector<int> ans;
int R, N, M, K;

void init()
{
	for (int i = 2; i <= M; ++i)
		for (int j = i; j <= M; ++j)
			for (int k = j; k <= M; ++k)
			{
				int p = i*100+j*10+k;
				mp[p][i] = 1;
				mp[p][i*j] = 1;
				mp[p][i*j*k] = 1;
				mp[p][i*k] = 1;
				mp[p][j] = 1;
				mp[p][j*k] = 1;
				mp[p][k] = 1;
				mp[p][1] = 1;
			}
}

int k[10];
int main()
{
	freopen("C-small-1-attempt0.in", "r", stdin);
	freopen("C-small-1-attempt0.out", "w", stdout);
	int T, nt = 0;
	scanf("%d", &T);
	srand(time(0));
	while(T--)
	{
		scanf("%d%d%d%d", &R, &N, &M, &K);
		init();
		printf("Case #%d:\n", ++nt);


		while(R--)
		{
			for (int i = 0; i < K; ++i)
				scanf("%d", &k[i]);
			ans.clear();
			for (it = mp.begin(); it != mp.end(); ++it)
			{
				int p = it->first;

				int i;
				for (i = 0; i < K; ++i)
					if (mp[p][k[i]] != 1)
					{
						break;
					}
				if (i == K)
					ans.push_back(p);
			}

			int r = rand()%(ans.size());
			printf("%d\n", ans[r]);
		}
	}
	return 0;
}