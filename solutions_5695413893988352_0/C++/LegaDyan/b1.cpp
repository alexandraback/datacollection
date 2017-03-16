#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#define rep(i, j, k) for(int i = j; i <= k; i++)

using namespace std;

int a[1000], b[10000], ans_a[10000], ans_b[100000], AnsA, AnsB, n, m;
int cnt_a, cnt_b;

void dfs_a (int x)
{
	if (x > n)
	{
		int ret = 0, now = 1;
		for (int i = n; i >= 1; i--)
			ret += a[i] * now, now *= 10;
		ans_a[++cnt_a] = ret;
		//printf ("dfs a %d\n", ret);
		return;
	}
	if (a[x] > -1)
		dfs_a (x + 1);
	if (a[x] == -1)
	rep (i, 0, 9)
	{
		a[x] = i;
		dfs_a (x + 1);
		a[x] = -1;
	}
	return;
}

void dfs_b (int x)
{
	//printf ("=====================%d\n", x);
	if (x > m)
	{
		int ret = 0, now = 1;
		for (int i = m; i >= 1; i--)
			ret += b[i] * now, now *= 10;
		ans_b[++cnt_b] = ret;
		//printf ("dfs b %d\n", ret);
	//	rep (i, 1, m)
	//		printf ("%d", b[i]);
	//	cout << endl;
		return;
	}
	if (b[x] > -1)
	{
		dfs_b (x + 1);
		return;
	}
	rep (i, 0, 9)
	{
		b[x] = i;
		dfs_b (x + 1);
		b[x] = -1;
	}
}


int main ()
{
	//freopen ("2.in", "r", stdin); freopen ("2.out", "w",stdout); 
	int ti;
	cin >> ti;
	rep (ff, 1, ti)
	{
		int Min = 0x7fffffff;
		cnt_a = cnt_b = 0;
		string aa, bb;
		cin >> aa >> bb;
		n = aa.length ();
		m = bb.length ();
		rep (i, 1, n)
			a[i] = aa[i - 1] == '?' ? -1 : aa[i - 1] - '0';
		rep (i, 1, m)
			b[i] = bb[i - 1] == '?' ? -1 : bb[i - 1] - '0';
		dfs_a (1);
		dfs_b (1);
		sort (ans_a + 1, ans_a + 1 + cnt_a);
		sort (ans_b + 1, ans_b + 1 + cnt_b);
		rep (i, 1, cnt_a)
			rep (j, 1, cnt_b)
				if (abs (ans_a[i] - ans_b[j]) < Min)
					Min = abs (ans_a[i] - ans_b[j]), AnsA = ans_a[i], AnsB = ans_b[j];
		printf ("Case #%d: ", ff);
		int num_a = 0, num_b = 0, now_a = AnsA, now_b = AnsB;
		if (AnsA == 0)
			num_a = 1;
		if (AnsB == 0)
			num_b = 1;
		while (AnsA)
			num_a ++, AnsA /= 10;
		while (AnsB)
			num_b++, AnsB /= 10;
		num_a = n - num_a;
		num_b = n - num_b;
		rep (i, 1, num_a)
			printf ("0");
		cout << now_a << ' ';
		rep (i, 1, num_b)
			printf ("0");
		cout << now_b << endl;
	}
	return 0;
}
