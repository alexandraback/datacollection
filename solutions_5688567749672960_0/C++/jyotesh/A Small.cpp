/*Counter Culture*/

#include<cstdio>
#include<queue>
#include<utility>
#include<cstring>

#define MAX 1000000

using namespace std;

bool visited[MAX + 1];
int num_steps[MAX + 1];

void precompute(void);
int get_reverse(int);

int main()
{
	int N, t, T;
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A.out", "w", stdout);
	precompute();
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		scanf("%d", &N);
		printf("Case #%d: %d\n", t, num_steps[N]);
	}
	return 0;
}

void precompute(void)
{
	int current_count, rev, val;
	pair<int, int> p;
	queue< pair<int, int> > q;
	memset(visited, false, sizeof(visited));
	q.push(make_pair(1, 1));
	num_steps[1] = 1;
	visited[1] = true;
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		val = p.first;
		current_count = p.second;
		if (val > MAX)
			continue;
		if (!visited[val + 1])
		{
			q.push(make_pair(val + 1, current_count + 1));
			num_steps[val + 1] = current_count + 1;
			visited[val + 1] = true;
		}
		rev = get_reverse(val);
		if (!visited[rev])
		{
			q.push(make_pair(rev, current_count + 1));
			num_steps[rev] = current_count + 1;
			visited[rev] = true;
		}
	}
}

int get_reverse(int num)
{
	int revnum;
	revnum = 0;
	while (num > 0)
	{
		revnum = (revnum << 3) + (revnum << 1) + (num % 10);
		num /= 10;
	}
	return revnum;
}