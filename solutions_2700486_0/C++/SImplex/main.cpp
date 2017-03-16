#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int const MAX_SIZE = 50005;
int precalc[MAX_SIZE];

long double matrix[2991][2991] = {};

void pre()
{
	matrix[0][0] = 1.0;
	for (int i = 0; i < 2990; ++i)
	{
		for (int j = 0; j <= i ; ++j)
		{
			matrix[i+1][j] += matrix[i][j]/2.0;
			matrix[i+1][j+1] += matrix[i][j]/2.0;
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w", stdout);
	cout << fixed;
	cout << setprecision(10);
    ios_base::sync_with_stdio(false);
	int cur = 1;
	int st = 1;
	int i = 0;
	for (i = 0; i < 750; ++i)
	{
		precalc[i] = cur;
		st += 4;
		cur += st;
	}
	for (i = 750; i < MAX_SIZE; ++i)
		precalc[i] = cur;
	pre();
	int t = 0;
	cin >> t;
	for (int step = 1; step <= t; ++step)
	{
		int n,x,y;
		cin >> n >> x >> y;
		int l = (abs(x)+y)/2;
		if (n >= precalc[l])
		{
			cout << "Case #" << step << ": " << 1.0 << "\n";
			continue;
		}
		if ((n <= precalc[l-1]) || (x == 0))
		{
			cout << "Case #" << step << ": " << 0.0 << "\n";
			continue;
		}
		int r = n - precalc[l-1];
		if (y < (r-2*l))
		{
			cout << "Case #" << step << ": " << 1.0 << "\n";
			continue;
		}
		long double ans = 0.0;
		for (int i = 0; i <= r; ++i)
			if (i > y)
				ans += matrix[r][i];
		cout << "Case #" << step << ": " << ans << "\n";	

	//	cout << "Case #" << step << ": " << ans << "\n";
	}
	
    return 0;
}