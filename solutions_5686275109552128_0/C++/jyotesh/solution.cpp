/*Infinite House of Pancakes*/

#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

int main()
{
	int best_time, count, D, i, max_val, P, t, T;
	priority_queue< int, vector<int> > q;
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		scanf("%d", &D);
		for (i = 0; i < D; i++)
		{
			scanf("%d", &P);
			q.push(P);
		}
		best_time = max_val = q.top();
		count = 0;
		while (max_val > 1)
		{
			q.pop();
			q.push((max_val + 1) / 2);
			q.push(max_val - (max_val + 1) / 2);
			max_val = q.top();
			count++;
			if (best_time > count + max_val)
				best_time = count + max_val;
		}
		printf("Case #%d: %d\n", t, best_time);
		while (!q.empty())
			q.pop();
	}
	return 0;
}