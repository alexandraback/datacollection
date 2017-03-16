#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int c, d, v, ans;
vector<int> cns;
int p[500];

void rec(int pos, int sum)
{
	if (pos == cns.size())
	{
		p[sum] = 1;
		return;
	}
	else
	{
		rec(pos + 1, sum);
		rec(pos + 1, sum + cns[pos]);
	}
}

bool full()
{
	for (int i = 0; i <= v; i++)
	{
		if (p[i] == 0)
			return false;
	}	
	return true;
}

void rec2(int pos, int cnt)
{
	if (pos > v)
	{
		fill(p, p + 500, 0);
		rec(0, 0);	
		if (full())
			ans = min(ans, cnt);
	}	
	else
	{
		rec2(pos + 1, cnt);
		if (cnt < 5 && find(cns.begin(), cns.end(), pos) == cns.end())
		{
			cns.push_back(pos);
			rec2(pos + 1, cnt + 1);
			cns.pop_back();
		}
	}
}

int main()
{
	freopen("C-small.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		cin >> c >> d >> v;
		cns = vector<int>(d);
		for (int j = 0; j < d; j++)
			cin >> cns[j];
		ans = (1 << 30);
		rec2(1, 0);
		printf("Case #%d: %d\n", i, ans);
	}

	return 0;
}
