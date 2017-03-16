#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	cin >> t;
	for (int ii = 1; ii <= t; ii++)
	{
		int j, p, s, k;
		int ans;
		cin >> j >> p >> s >> k;
		cout << "Case #" << ii << ": ";
		
		if (k >= s)
		{
			ans = j*p;
			cout << endl << ans << endl;
			for (int i1 = 1; i1 <= j; i1++)
				for (int i2 = 1; i2 <= p; i2++)
					for (int i3 = 1; i3 <= s; i3++)
						cout << i1 << ' ' << i2 << ' ' << i3 << ' ' << endl;
		}
		else
		{
			//int a[120] = { 0 };
			//for (int i = 1; )
			int cnt, s0 = 0, st;
			ans = 0;
			for (int i1 = 1; i1 <= j; i1++)
			{
				
				s0++;
				st = 0;
				for (int i2 = 1; i2 <= p; i2++)
				{
					cnt = 0;
					for (int i3 = 1; i3 <= s, cnt < k; i3++)
					{
						cnt++;
						st++;
						ans++;
						//cout << i1 << ' ' << i2 << ' ' << (st + s0)%s + 1 << ' ' << endl;
					}
				}
			}
			cout << endl << ans << endl;
			s0 = 0;
			for (int i1 = 1; i1 <= j; i1++)
			{
				
				s0++;
				st = 0;
				for (int i2 = 1; i2 <= p; i2++)
				{
					cnt = 0;
					for (int i3 = 1; i3 <= s, cnt < k; i3++)
					{
						cnt++;
						st++;
						//ans++;
						cout << i1 << ' ' << i2 << ' ' << (st + s0)%s + 1 << ' ' << endl;
					}
				}
			}
		}
		//cout << endl;
	}
	return 0;
}