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
	int a[15][15] = { 0 };
	a[1][1] = 1;
	for (int i = 2; i <= 10; i++)
		for (int j = 1; j <= i; j++)
		{
			if (j == 1)
				a[i][j] = i;
			else if (j <= i / 2)
				a[i][j] = 1 + a[i - j][j];
			else if (i == j)
				a[i][j] = j;
			else a[i][j] = j + 1;
		}
	cin >> T;
	for (int tt = 1; tt <= T; tt++)
	{
		int r, c, w, ans = 0;
		cin >> r >> c >> w;
		ans = a[c][w];
		cout << "Case #" << tt << ": " << ans << endl;
	}
	return 0;
}