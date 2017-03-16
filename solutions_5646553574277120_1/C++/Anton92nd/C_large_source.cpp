#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int c, d, ans;
int v;
vector<long long> ar;
vector<long long> canGet;

void solve()
{
	if (ar[0] != 1)
	{
		ans++;
		ar.insert(ar.begin(), 1);
	}
	canGet.clear();
	canGet.resize(ar.size());
	canGet[0] = c;
	int i = 0, j;
	while(true)
	{
		j = i + 1;
		while (j < ar.size() &&	canGet[j - 1] >= ar[j] - 1)
		{
			canGet[j] = canGet[j - 1] + c * ar[j];
			if (canGet[j] >= v)
			{
				return;
			}
			j++;
		}
		i = j - 1;
		if (canGet[i] >= v)
		{
			return;
		}
		ar.insert(ar.begin() + j, canGet[i] + 1);
		canGet.push_back(0);
		ans++;
		i++;
		canGet[i] = canGet[i - 1] + c * ar[i];
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int q = 0; q < t; q++)
	{
		scanf("%d%d%d", &c, &d, &v);
		ar.resize(d);
		for (int i = 0; i < d; i++)
		{
			scanf("%d", &ar[i]);
		}
		sort(ar.begin(), ar.end());
		ans = 0;
		solve();
		printf("Case #%d: %d\n", q + 1, ans);
	}
	return 0;
}