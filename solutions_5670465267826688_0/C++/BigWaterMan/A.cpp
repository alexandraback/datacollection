#pragma error(disable:4996)
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
const LL MAXSIZE = 120000;
int a[MAXSIZE*10];
int L;
int List[8][8] =
{

	1, 2, 3, 4, -1, -2, -3, -4,
	2, -1, 4, -3, -2, 1, -4, 3,
	3, -4, -1, 2, -3, 4, 1, -2,
	4, 3, -2, -1, -4, -3, -2, -1,
	-1, -2, -3, -4, 1, 2, 3, 4,
	-2, 1, -4, -3, 2, -1, 4, -3,
	-3, 4, 1, -2, 3, -4, -1, 2,
	-4, -3, 2, 1, 4, 3, -2, -1
};

	int cal(int c,int t)
	{
		int b = 1;
		if (c<0)
		{
			b = -b;
			c = -c;
		}
		if (t<0)
		{
			b = -b;
			t = -t;
		}

		return (List[c - 1][t - 1] * b);
	}


int main()
{
	errno_t err1;
	errno_t err2;
	FILE *fin, *fout;
	err1 = freopen_s(&fin, "C-small-attempt2.in", "r", stdin);
	//err1 = freopen_s(&fin, "in.txt", "r", stdin);
	err2 = freopen_s(&fout, "out.txt", "w", stdout);
	LL T;
	cin >> T;
	memset(a, 0, sizeof(a));
	for (LL z = 1; z <= T; ++z)
	{

		cout << "Case #" << z << ": ";
		int n, m;
		cin >> n >> m;
		if (m>8) m=m%16+16;
		string st;
		cin >> st;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (st[j] == '1')
					a[i*n + j] = 1;
				if (st[j] == 'i')
					a[i*n + j] = 2;
				if (st[j] == 'j')
					a[i*n + j] = 3;
				if (st[j] == 'k')
					a[i*n + j] = 4;
			}
		}
		int v = 0;
		int ans = 1;
		bool f1 = false, f2 = false, f3 = false;
		while (v < m*n)
		{
			ans = cal(ans, a[v]);
			++v;
			if (ans == 2)
			{
				f1 = true;
				break;
			}
		}
		ans = 1;
		while (v < m*n)
		{
			ans = cal(ans, a[v]);
			++v;
			if (ans == 3 && f1==true)
			{
				f2 = true;
				break;
			}
		}
		ans = 1;
		while (v < m*n)
		{
			ans = cal(ans, a[v]);
			++v;
		}
		if (ans == 4 && f1 && f2)
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}

}
