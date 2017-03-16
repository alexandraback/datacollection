#include <iostream>
#include <algorithm>

using namespace std;

struct cont
{
	int number;
	int count;
};

void solve()
{
	int n;
	cont s[200];
	int num[200];
	double ans[200];

	cin >> n;

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		s[i].number = i;
		cin >> s[i].count;
		sum += s[i].count;
	}

	sort(&s[0], &s[n], [](cont &a, cont& b){ return a.count < b.count; });

	int i = 1;
	double x = 0;
	while (i < n && static_cast<double>((s[i].count - s[i - 1].count) * i) / sum + x < 1)
	{
		x += static_cast<double>((s[i].count - s[i - 1].count) * i) / sum;
		i++;
	}

	for (int j = 0; j < n; j++)
		if (s[j].count <= s[i - 1].count)
			ans[s[j].number] = static_cast<double>(s[i - 1].count - s[j].count) / sum + (1 - x) / i;
		else
			ans[s[j].number] = 0;

	for (int j = 0; j < n; j++)
		printf("%.6f ", ans[j] * 100);
	cout << endl;
}

int main()
{
	int T;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cout << "Case #" << i + 1 << ": ";
		solve();
	}

	return 0;
}

