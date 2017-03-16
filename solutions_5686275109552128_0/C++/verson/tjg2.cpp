#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <string>
#pragma warning(disable:4996)

using namespace std;

int T, n;
int a[2000];

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

void tsort(int pos)
{
	int key = a[pos];
	while (pos > 0 && key < a[pos - 1]) 
	{
		a[pos] = a[pos - 1];
		pos--;
	}
	a[pos] = key;
}
int main()
{
	freopen("B-small-attempt4.in", "r", stdin);
	freopen("B-small-attempt4.out", "w", stdout);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int times = 0;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a+n);

		int ans = a[n-1];
		for (int i = 1; i <= a[n-1]; i++)
		{
			int value = 0;
			for (int j = n - 1; j >= 0 && a[j] > i; j--)
				value += (a[j]-1) / i;
			ans = min(ans, value + i);
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
}