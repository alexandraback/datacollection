#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;
int data[60][60];

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int t;
	cin >> t;
	for (size_t s = 0; s < t; s++)
	{
		memset(data, 0, sizeof(data));
		long long n, m;
		cin >> n >> m;
		cout << "Case #" << s + 1 << ": ";
		if (m>1 << (n - 2))
		{
			cout << "IMPOSSIBLE\n";
		}
		else
		{
			cout << "POSSIBLE\n";
			data[0][n - 1] = 1;
			for (size_t i = 0; i < n-1; i++)
			{
				for (size_t s = i+1; s < n-1; s++)
				{
					data[i][s] = 1;
				}
			}
			m--;
			for (size_t i = 1; i < n-1; i++)
			{
				if (m >> (i-1) & 1)
				{
					data[i][n - 1] = 1;
				}
				else
				{
					data[i][n - 1] = 0;
				}
			}
			for (size_t i = 0; i < n; i++)
			{
				for (size_t s = 0; s < n; s++)
				{
					cout << data[i][s];
				}
				cout << "\n";
			}
		}
	}

}