#include <cstdio>
#include <vector>

using namespace std;
vector<long long int> answer;

int k, c, s;

void input()
{
	scanf("%d %d %d", &k, &c, &s);
}

void solve()
{
	long long int step = 1;
	for (int i = 0; i < c-1; i++)step *= k;
	answer.clear();
	if (k == s)//small input
	{
		long long int now = 1;
		answer.push_back(now);
		for (int i = 0; i < k - 1; i++)
		{
			now += step;
			answer.push_back(now);
		}
	}
}

void output(int casen)
{
	printf("Case #%d: ", casen);
	if (answer.empty())
	{
		puts("IMPOSSIBLE"); return;
	}
	for (auto i : answer) printf("%lld ", i);
	puts("");
}

int main()
{
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("fract.txt", "w", stdout);
	int T; scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		input();
		solve();
		output(i);
	}
}