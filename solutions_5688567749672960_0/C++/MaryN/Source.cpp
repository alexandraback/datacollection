#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<conio.h>
using namespace std;
int a[1000010] = { 0 };
const int n = 1000000;
int rev(int b)
{
	int ans = 0; 
	while (b)
	{
		ans = ans * 10 + b % 10;
		b /= 10;
	}
	return ans;
}
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, c;
	a[1] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (a[i + 1] != 0)
			a[i + 1] = fmin(a[i] + 1, a[i + 1]);
		else
			a[i + 1] = a[i] + 1;
		c = rev(i);
		if (c > i)
		{
			if (a[c] != 0)
				a[c] = fmin(a[i] + 1, a[c]);
			else
				a[c] = a[i] + 1;
		}
	}

	cin >> T;
	for (int tt = 1; tt <= T; tt++)
	{
		cin >> c;
		cout << "Case #" << tt << ": " << a[c] << endl;
	}
	return 0;
}