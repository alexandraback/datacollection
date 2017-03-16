//g++ -std=c++0x your_file.cpp -o your_program
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#define fname ""
#define mp make_pair
#define F first
#define pb push_back
#define S second
#define ub upper_bound
#define lb lower_bound
#define inf 2000000000
#define INF 2000000000000000000ll
using namespace std;

string C, J;

int a[5];

inline bool valid(string s, int x)
{
	int it = 0;
	memset(a, 0, sizeof(a));
	while (x)
	{
		a[it++] = x % 10;
		x /= 10;
	}
	if (it > (int)s.length())
		return 0;
	for (int i = 0; i < (int)s.length(); i++)
		if (isdigit(s[(int)s.length() - i - 1]) && (int)s[(int)s.length() - i - 1] - '0' != a[i])
			return 0;
	return 1;
}

inline void Print(int ln, int x)
{
	int it = 0;
	memset(a, 0, sizeof(a));
	while (x)
	{
		a[it++] = x % 10, x /= 10;
	}
	for (int i = ln - 1; i >= 0; i--)
		printf("%d", a[i]);
	printf(" ");
}

inline void solve()
{
	cin >> C >> J;
	int X, Y, ans = inf;
	for (int x = 0; x < 1000; x++)
	{
		if (!valid(C, x))
			continue;
//		cout << C << " " << x << endl;
		for (int y = 0; y < 1000; y++)
		{
			if (!valid(J, y))
				continue;
			if (abs(x - y) < ans)
			{
				ans = abs(x - y);
				X = x, Y = y;
			}
			else if (abs(x - y) == ans && x < X)
			{
				X = x, Y = y;
			}
			else if (abs(x - y) == ans && x == X && y < Y)
				Y = y;
		}
	}
	Print((int)C.length(), X);
	Print((int)J.length(), Y);
	puts("");
//	cout << X << " " << Y << endl;
}

int main()
{
	freopen (fname"input.txt", "r", stdin);
	freopen (fname"output.txt", "w", stdout);
	int T;
	cin >> T;
	scanf("\n");
	for (int Case = 1; Case <= T; Case++)
	{
		printf("Case #%d: ", Case);
		solve();
	}


	return 0;
}
