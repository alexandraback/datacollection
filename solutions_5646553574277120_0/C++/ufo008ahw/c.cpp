#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int arr[100];
int d;
int ok;

void dfs(int a, int p)
{
	if (ok == 1)
		return;
	if (a == 0)
	{
		ok = 1;
		return;
	}
	if (p < 0)
		return;

	for(int i = p;i >= 0;i--)
	{
		if (a >= arr[i])
			dfs(a - arr[i], i - 1);
	}
}

int main()
{
	int ncase;
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);

	cin >> ncase;

	for(int icase = 0;icase < ncase;icase++)
	{
		int c, v;
		cin >> c >> d >> v;

		for(int i = 0;i < d;i++)
			cin >> arr[i];
		sort(arr, arr + d);

		int preD = d;
		for(int i = 1;i <= v;i++)
		{
			ok = 0;
			dfs(i, d - 1);
			if (ok == 0)
				arr[d++] = i;
		}
		cout << "Case #" << icase + 1 << ": " << d - preD << endl;
	}
	return 0;
}
