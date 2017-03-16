#include <bits/stdc++.h>
using namespace std;


string player1 = "RICHARD";
string player2 = "GABRIEL";

bool canHandle(int n, int m, int up, int down, int s)
{
	for(int row = 1; row <= m; row ++)
	{
		int row1 = row - 1;
		int row2 = m - row;
		if(row1 < up) continue;
		if(row2 < down) continue;
		row1 = row1 * n - up;
		row2 = row2 * n - down;
		if(row1 % s == 0 || row2 % 2 == 0)
			return true;
	}
	return false;
}

bool haveKill(int n, int m, int size)
{
	int more = size - n;
	for(int i = 0; i <= more; i++)
		if(!canHandle(n, m, i, more - i, size))
		{
			return true;
		}
	return false;
}

string sol(int x, int n, int m)
{
	if(n * m % x > 0)
		return player1;

	if(n >= x && m >= x)
		return player2;

	int t = min(n, m) + 1;
	if(x >= 2 * t - 1)
		return player1;

	if(n < x)
		if(haveKill(n, m, x))
			return player1;
	if(m < x)
		if(haveKill(m, n, x))
			return player1;
	return player2;
}

void solve()
{
	int x, n, m;
	cin >> x >> n >> m;
	cout << sol(x, n, m) << endl;
}

int MAIN()
{
	int TestCase;
	cin >> TestCase;
	for(int caseID = 1; caseID <= TestCase; caseID ++)
	{
		cout << "Case #" << caseID << ": ";
		solve();
	}
	return 0;
}

int main()
{
	int start = clock();
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	int ret = MAIN();
	#ifdef LOCAL_TEST
		cout << "[Finished in " << clock() - start << " ms]" << endl;
	#endif
	return ret;
}
