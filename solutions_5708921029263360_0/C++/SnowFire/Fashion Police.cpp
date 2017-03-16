#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int ALL[11][11][11];
int First[11][11], Second[11][11], Third[11][11]; //AB, BC, AC
int F, S, T, K, MAX;
vector< pair<int, pair<int, int> > > ANS;

inline void init()
{
	scanf("%d %d %d %d", &F, &S, &T, &K);

	ANS.clear();
	memset(ALL, 0, sizeof(ALL));
	memset(First, 0, sizeof(First));
	memset(Second, 0, sizeof(Second));
	memset(Third, 0, sizeof(Third));
}

void solve(int f, int s, int t, int step)
{
	if (step == 4)
	{
		if (ALL[f][s][t])
			return;
		if (First[f][s] == K)
			return;
		if (Second[s][t] == K)
			return;
		if (Third[f][t] == K)
			return;

		ALL[f][s][t] = 1;
		First[f][s]++;
		Second[s][t]++;
		Third[f][t]++;
		MAX = max(MAX, max(First[f][s], max(Second[s][t], Third[f][t])));

		ANS.push_back(make_pair(f, make_pair(s, t)));
	}

	int i;

	if (step == 1)
		for (i = 1; i <= T; i++)
			solve(i, s, t, 2);
	else if (step == 2)
		for (i = 1; i <= S; i++)
			solve(f, i, t, 3);
	else if (step == 3)
		for (i = 1; i <= F; i++)
			solve(f, s, i, 4);
}

inline void print()
{
	int i;

	printf("%d\n", ANS.size());

	for (i = 0; i < ANS.size(); i++)
		printf("%d %d %d\n", ANS[i].second.second, ANS[i].second.first, ANS[i].first);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, i;

	scanf("%d", &T);

	for (i = 1; i <= T; i++)
	{
		init();
		solve(0, 0, 0, 1);
		printf("Case #%d: ", i);
		print();
	}

	return 0;
}