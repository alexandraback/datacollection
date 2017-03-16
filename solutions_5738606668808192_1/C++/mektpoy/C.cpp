#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<cmath>
#include<cstdlib>
#include<queue>
using namespace std;

#define pb push_back
#define mp make_pair
#define sc second
#define ft first

#define FOR(i,N) for (int i=1; i<=N; i++)
#define REP(i,l,r) for (int i=l; i<=r; i++)

#define INF ~0U>>1
#define eps 1e-9

int ans[20];

bool Judge (unsigned int k, int i, int p)
{
	int d = 1, c = 0;
	vector <int> dk;
	while (k)
	{
		dk.pb (k & 1);
		k /= 2;
	}
	reverse (dk.begin(), dk.end());
	for (auto j : dk)
	{
		c = (c * i + j) % p;
	}
	if (c == 0) ans[i] = p;
	return c == 0;
}

bool judge (unsigned int k, int i)
{
	if (Judge (k, i, 2)) return true;
	if (Judge (k, i, 3)) return true;
	if (Judge (k, i, 5)) return true;
	if (Judge (k, i, 7)) return true;
	return false;
}

void print (unsigned int k)
{
	string s;
	while (k)
	{
		s += (k % 2) + '0';
		k /= 2;
	}
	reverse (s.begin(), s.end());
	cout << s << " ";
}

int main ()
{
#ifndef ONLINE_JUDGE
#ifndef MEKTPOY
	freopen (".in", "r", stdin);
	freopen (".out", "w", stdout);
#else
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif
#endif
	int T, N, J;
	cin >> T;
	while (T --)
	{
		printf ("Case #%d:\n", 1);
		cin >> N >> J;
		unsigned int k = (1 << N - 1) + 1;
		int cnt = 0;
		for (; ; k ++)
		{
			if (!(k & 1)) continue;
			int flag = 1;
			for (int i = 2; i <= 10; i ++)
				if (!judge(k, i)) flag = 0;
			if (flag)
			{
				print (k);
				for (int i = 2; i <= 10; i ++)
					printf ("%d ", ans[i]);
				puts("");
				J --;
			}
			if (!J) break;
		}
	}
	return 0;
}

