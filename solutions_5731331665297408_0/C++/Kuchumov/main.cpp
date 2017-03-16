#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 100;

int n;
int mx[N][N];
int perm[N];
string code[N];

bool good;
int pos;
string res;

void rec(int v)
{
	if (pos == n)
		return;

	while (pos < n)
	{
		int to = perm[pos];
		if (mx[v][to])
		{
			res += code[to];
			pos++;
			rec(to);
		}
		else
		{
			if (v == perm[0])
				good = false;
			return;
		}
	}
}

string solve()
{
	int m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> code[i];
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			mx[i][j] = 0;

	for (int i = 0; i < m; i++)
	{
	 	int a, b;
	 	cin >> a >> b;
	 	a--;
	 	b--;
	 	mx[a][b] = 1;
	 	mx[b][a] = 1;
	}

	for (int i = 0; i < n; i++)
		perm[i] = i;

	string ans = "z";
	do
	{
		good = true;
		res = code[perm[0]];
		pos = 1;
		rec(perm[0]);

		//cout << res << endl;
		
		if (good)
		{
			//cout << res << endl;
			ans = min(ans, res);
		}

	} while (next_permutation(perm, perm + n));

	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int it = 1; it <= t; it++)
	{
		string ans = solve();
		printf("Case #%d: %s\n", it, ans.c_str());
	}	

 	return 0;
}