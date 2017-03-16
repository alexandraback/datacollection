#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

typedef long long LL;

int T;
LL A, B;

bool check(LL n)
{
	vector<int> d;
	while (n)
	{
		d.push_back(n % 10);
		n /= 10;
	}
	for(int i = 0; i < d.size(); i++)
		if (d[i] != d[d.size() - 1 - i])
			return 0;
	return 1;
}

int main()
{
	freopen("C-large-1.in", "r", stdin);
	freopen("C-large-1.out", "w", stdout);
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cin >> A >> B;
		LL i = 1;
		LL ans = 0;
		while (1)
		{
			LL n = i;
			vector<int> d;
			while (n)
			{
				d.push_back(n % 10);
				n /= 10;
			}
			LL cur = i;
			for(int j = 1; j < d.size(); j++) cur = cur * 10 + d[j];
			if (cur * cur > B) break;
			if (cur * cur >= A && check(cur * cur)) ans++;
			cur = i;
			for(int j = 0; j < d.size(); j++) cur = cur * 10 + d[j];
			if (cur * cur >= A && cur * cur <= B && check(cur * cur)) ans++;
			i++;
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
