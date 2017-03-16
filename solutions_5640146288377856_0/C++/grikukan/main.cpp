#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int solve(int c, int w)
{
	if (c%w == 0)
	{
		int blocks = c / w;
		return blocks + w - 1;
	}
	else
	{
		int blocks = c / w + 1;
		return blocks + w - 1;
	}
}
int solve2(int c, int w)
{
	if (c%w == 0)
	{
		int blocks = c / w;
		return blocks - 1;
	}
	else
	{
		int blocks = c / w + 1;
		return blocks - 1;
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		int r, c, w;
		cin >> r >> c >> w;
		cout << "Case #" << tt << ": " << (r-1)*solve2(c, w)+solve(c,w) << endl;
	}
}