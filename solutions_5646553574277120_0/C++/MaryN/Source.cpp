#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<conio.h>
using namespace std;


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++)
	{
		int ans = 0;
		int c, d, v;
		int a[10] = { 0 }, vv[60] = { 0 };
		cin >> c >> d >> v;
		for (int i = 1; i <= d; i++)
			cin >> a[i];
		vv[0] = 1;
		vv[a[1]] = 1;
		for (int i = 2; i <= d; i++)
		{
			//vv[a[i]] = i;
			for (int j = v; j >= 0; j--)
				if (vv[j] > 0 && j + a[i] <= v)
					vv[j + a[i]] = i;
		}
		for (int i = 1; i <= v; i++)
		{
			if (!vv[i])
			{
				ans++;
				//vv[i] = d + 1;
				d++;
				for (int j = v; j >= 0; j--)
					if (vv[j] > 0 && j + i <= v)
						vv[j + i] = d;
			}
		}
		cout << "Case #" << tt << ": " << ans << endl;
	}
	return 0;
}