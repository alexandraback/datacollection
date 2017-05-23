/*Counter Culture*/

#include<cstdio>
#include<queue>
#include<utility>
#include<cstring>

#define MAX 1000000

using namespace std;

bool visited[MAX + 1];
int num_steps[MAX + 1];
long long powers[16];

void precompute(void);
long long get_reverse(long long);

int main()
{
	int count, i, t, T;
	long long base, N, prefix, p, prefix_rev, rev, temp, total;
	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout);
	precompute();
	powers[0] = 1;
	for (i = 1; i < 16; i++)
		powers[i] = powers[i - 1] * 10;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		scanf("%lld", &N);
		total = 0;
		while (1)
		{
			if (N <= MAX)
			{
				total += num_steps[N];
				break;
			}
			temp = N;
			count = 0;
			while (temp > 0)
			{
				count++;
				temp /= 10;
			}
			p = powers[(count + 1) / 2];
			prefix = N / p;
			base = prefix * p + 1;
			total += N - base;
			rev = get_reverse(base);
			prefix_rev = get_reverse(prefix);
			if (N > rev - prefix_rev + 1)
			{
				N = rev - prefix_rev + 1;
				total += prefix_rev;
			}
			else if (N < rev - prefix_rev + 1)
				N = rev - prefix_rev + 1;
			temp = N;
			count = 0;
			while (temp > 0)
			{
				count++;
				temp /= 10;
			}
			p = powers[count - 1];
			if (N == p + 1)
				N -= powers[count / 2];
			total += powers[count / 2];
		}
		printf("Case #%d: %lld\n", t, total);
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
		rev = (int)get_reverse(val);
		if (!visited[rev])
		{
			q.push(make_pair(rev, current_count + 1));
			num_steps[rev] = current_count + 1;
			visited[rev] = true;
		}
	}
}

long long get_reverse(long long num)
{
	long long revnum;
	revnum = 0;
	while (num > 0)
	{
		revnum = (revnum << 3) + (revnum << 1) + (num % 10);
		num /= 10;
	}
	return revnum;
}