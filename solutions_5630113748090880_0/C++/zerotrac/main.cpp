#include <iostream>

using namespace std;

int cnt[2510];

void Work()
{
	int sz;
	cin >> sz;

	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < sz + sz - 1; i++)
		for (int j = 0; j < sz; j++)
		{
			int x;
			cin >> x;
			cnt[x]++;
		}
	for (int i = 1; i <= 2500; i++)
	{
		//if (i <= 6) cout << "n = " << cnt[i] << endl;
		if (cnt[i] & 1) cout << i << " ";
	}
	cout << endl;
}

int main()
{
	freopen("123.in", "r", stdin);
	freopen("123.out", "w", stdout);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "Case #" << i << ": ";
		Work();
	}
	return 0;
}