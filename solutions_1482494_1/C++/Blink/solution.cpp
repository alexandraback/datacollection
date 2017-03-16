#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

vector <int> a, b;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int c = 1; c <= t; ++c)
	{
		int n;
		cin >> n;
		a.resize(n);
		b.resize(n);
		vector <char> d(n, 0);
		vector <int> q1(n), q2(n);
		for (int i = 0; i < n; ++i)
		{
			q1[i] = i;
			q2[i] = i;
			cin >> a[i] >> b[i];
		}
		sort(q1.begin(), q1.end(), [](int x, int y){return (b[x] > b[y]);});
		sort(q2.begin(), q2.end(), [](int x, int y){return (b[x] < b[y]);});
		int stars = 0, ans = 0;
		bool flag = true;
		while (flag)
		{
			flag = false;
			for (int i = 0; i < n; ++i)
				if (d[q2[i]] != 2 && stars >= b[q2[i]])
				{
					flag = true;
					stars += 2 - d[q2[i]];
					d[q2[i]] = 2;
					++ans;
				}
			if (flag)
				continue;
			for (int i = 0; i < n; ++i)
				if (d[q1[i]] == 0 && stars >= a[q1[i]])
				{
					flag = true;
					stars += 1;
					d[q1[i]] = 1;
					++ans;
					break;
				}
		}
		flag = true;
		for (int i = 0; i < n; ++i)
			if (d[i] != 2)
				flag = false;
		printf("Case #%d: ", c);
		if (flag)
			printf("%d\n", ans);
		else
			printf("Too Bad\n");
	}
	return 0;
}