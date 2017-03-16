#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

const int MOD = 1000000007 ;

struct NODE {
	int x, y, st;
	NODE () {}
	int read()
	{
		char str[105];
		scanf("%s", str);
		int len = strlen(str);
		x = str[0] - 'a';
		y = str[len - 1] - 'a';
		
		st = 0;
		for (int i = 0; i < len; i++)
		{
			int t = 1 << (str[i] - 'a');
			if ((t & st) && str[i] != str[i-1]) return 1;
			st |= t;
		}
		return 0;
	}
}	nd[105];


int vis[105];
int N, ANS;

int check(int st, int bf, int x, int st1)
{
	if (x == bf)
	{
		if ((st ^ (1 << x)) & st1) return 0;
		return 1;
	}
	if (st & st1) return 0;
	return 1;
}

void dfs(int step, int st, int bef)
{
	if (step == 0) { ANS ++; return ; }
	
	for (int i = 1; i <= N; i++)
		if (vis[i] == 0)
		{
			if (check(st, bef, nd[i].x, nd[i].st) == 0) continue ;
			vis[i] = 1;
			dfs(step - 1, st | nd[i].st, nd[i].y);
			vis[i] = 0;
		}
}

int main()
{
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	int cas, T;
	
	for (cas = scanf("%d", &T); cas <= T; cas++)
	{
		int n;
		cin >> n;
		
		int mark = 0;
		for (int i = 1; i <= n; i++) mark |= nd[i].read();
		
		printf("Case #%d: ", cas);
		if (mark == 1) { puts("0"); continue ; }
		
		N = n;
		ANS = 0;
		
		dfs(n, 0, -1);
		
		cout << ANS << endl;
	}
	
	return 0;
}
