#include <iostream>
#include <fstream>

using namespace std;
int T, r, n, m, k;
bool f[200];
int ans[10];
int h[200];
bool ok = false;

void parse(int num, int d)
{
	if (ok)
		return;
	if (num == n + 1) {
		f[d] = true; return;
	}
	parse(num + 1, d);
	parse(num + 1, d * ans[num]);
}

void check()
{
	if (ok)
		return;
	for (int i = 1; i <= 125; i++)
			f[i] = false;
	parse(1, 1);
	for (int i = 1; i <= k; i++)
		if (!f[h[i]]) 
			return;
	ok  =true; 	for (int i = 1; i <= n; i++)
			cout << ans[i];
}

void build(int nom)
{
	if (ok)
		return;
	if (nom > n) {
		check(); return; }
	for (int i = 2; i <= m; i++)
	{
		ans[nom] = i;
		build(nom+1);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> T;
	cin >> r >> n >> m >> k;
	cout << "Case #1:" << endl;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= k; j++)
			cin >> h[j];
		ok = false;
		build(1);
	
		cout << endl;
	}
}


	