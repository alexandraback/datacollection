#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool have[107];
int a[107];
bool good[107];
bool lst[107];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		int c, d, v;
		cin >> c >> d >> v;
		for (int i = 0; i <= v; i++)
		{
			have[i] = false;		
			lst[i] = false;
		}
		for (int i = 1; i <= d; i++)
		{
			cin >> a[i];
			have[a[i]] = true;
		}
		for (int i = 0; i < (1 << d); i++)
		{
			int cur = 0;
			int tmp = i;
			for (int j = 1; j <= d; j++)
			{
				if (tmp % 2 == 1)
				{
					cur += a[j];
				}
				tmp /= 2;
			}
			if (cur <= v)
			{
				have[cur] = true;
			}			
		}
		int ans = 0;
		for (int i = 1; i <= v; i++)
		{
			if (!have[i])
			{
				ans++;
				have[i] = true;
				lst[i] = true;
				for (int j = 0; j <= v; j++)
				{
					if (!have[j] && j - i >= 0 && !lst[j - i] && have[j - i])
					{
						lst[j] = true;
						have[j] = true;
					}
				}
				for (int j = 0; j <= v; j++)
				{
					lst[j] = false;
				}
			}
		}
		cerr << tt << endl;
		cout << "Case #" << tt << ": " << ans << endl;
	}
		
	
}