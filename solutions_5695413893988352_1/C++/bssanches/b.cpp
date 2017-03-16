#include <bits/stdc++.h>

using namespace std;
#define MAX 20
typedef long long ll;
const ll INF = LLONG_MAX;

int t;
char in1[MAX], in2[MAX];
string a,b;
string resa1,resb1;
string resa2,resb2;
ll dp[MAX][2];
int mark[MAX][2];
ll pot[MAX];
pair<int,int> path[MAX][2];

ll solve(int curr, int f, string &a, string &b)
{
	if (curr == a.size())
		return 0;

	ll & ret = dp[curr][f];
	if (mark[curr][f] != -1)
		return ret;

	mark[curr][f] = 1;
	ret = INF;
	ll poten = pot[a.size() - 1 - curr];

	if (a[curr] == '?' && b[curr] == '?')
	{
		for (int i = 0; i <= 9; ++i)
		{
			if (!f)
			{
				for (int j = 0; j < i; ++j)
				{
					ll ret2 = solve(curr + 1, 1, a, b);
					if (ret2 == INF)
						continue;
					ret2 += (i - j) * poten;
					if (ret2 < ret)
					{
						ret = ret2;
						path[curr][f] = make_pair(i, j);
					}
				}
				ll ret2 = solve(curr + 1, 0, a, b);
				if (ret2 < ret)
				{
					ret = ret2;
					path[curr][f] = make_pair(i,i);
				}
			}
			else
			{
				for (int j = 0; j <= 9; ++j)
				{
					ll ret2 = solve(curr + 1, 1, a, b);
					if (ret2 == INF)
						continue;
					ret2 += (i - j) * poten;

					if (ret2 < ret)
					{
						ret = ret2;
						path[curr][f] = make_pair(i, j);
					}
				}	
			}
		}
	}
	else if (a[curr] == '?' && b[curr] != '?')
	{
		if (!f)
		{
			ll ret2 = solve(curr + 1, 0, a, b);
			if (ret2 < ret)
			{
				ret = ret2;
				path[curr][f] = make_pair(b[curr]-'0', b[curr]-'0');
			}

			for (int i = b[curr]-'0' + 1; i <= 9; ++i)
			{
				ll ret2 = solve(curr + 1, 1, a, b);
				if (ret2 == INF)
					continue;
				ret2 += (i - (int)(b[curr]-'0')) * poten;
				if (ret2 < ret)
				{
					ret = ret2;
					path[curr][f] = make_pair(i, b[curr]-'0');
				}
			}
		}
		else
		{
			for (int i = 0; i <= 9; ++i)
			{
				ll ret2 = solve(curr + 1, 1, a, b);
				if (ret2 == INF)
					continue;
				ret2 += (i - (int)(b[curr]-'0')) * poten;
				if (ret2 < ret)
				{
					ret = ret2;
					path[curr][f] = make_pair(i, b[curr]-'0');
				}
			}
		}
	}
	else if (a[curr] != '?' && b[curr] == '?')
	{
		if (!f)
		{
			for (int j = 0; j < a[curr]-'0'; ++j)
			{
				ll ret2 = solve(curr + 1, 1, a, b);
				if (ret2 == INF)
					continue;
				ret2 += ((int)a[curr]-'0' - j) * poten;
				if (ret2 < ret)
				{
					ret = ret2;
					path[curr][f] = make_pair(a[curr]-'0', j);
				}
			}

			ll ret2 = solve(curr + 1, 0, a, b);
			if (ret2 < ret)
			{
				ret = ret2;
				path[curr][f] = make_pair(a[curr]-'0', a[curr] - '0');
			}
		}
		else
		{
			for (int j = 0; j <= 9; ++j)
			{
				ll ret2 = solve(curr + 1, 1, a, b);
				if (ret2 == INF)
					continue;
				ret2 += ((int)a[curr]-'0' - j) * poten;
				if (ret2 < ret)
				{
					ret = ret2;
					path[curr][f] = make_pair(a[curr]-'0', j);
				}
			}
		}
	}
	else if (!f && a[curr] < b[curr])
	{
		return INF;
	}
	else if (!f)
	{
		path[curr][f] = make_pair(a[curr]-'0',b[curr]-'0');
		if (a[curr] > b[curr])
		{
			ll ret2 = solve(curr + 1, 1, a, b);
			if (ret2 == INF)
			{
				ret = INF;
			}
			else
			{
				ret = ret2 + ((int)a[curr] - (int)b[curr]) * poten;
			}
		}
		else
		{
			return ret = solve(curr + 1, 0, a, b);
		}
	}
	else
	{
		path[curr][f] = make_pair(a[curr]-'0',b[curr]-'0');
		ll ret2 = solve(curr + 1, 1, a, b);
		if (ret2 == INF)
			ret = INF;
		else
			ret = ret2 + ((int)a[curr] - (int)b[curr]) * poten;
	}
	return ret;
}


void build(int curr, int f, string& ansa, string& ansb)
{
	if (curr == a.size())
	{
		return;
	}
	int x = path[curr][f].first;
	int y = path[curr][f].second;
	ansa += x + '0';
	ansb += y + '0';

	if (!f && x > y)
	{
		build(curr + 1, 1, ansa, ansb);
	}
	else
		build(curr + 1, f, ansa, ansb);
}

int main(void)
{
	
	scanf("%d",&t);
	pot[0] = 1;
	for (int i = 1; i < MAX; ++i)
		pot[i] = pot[i - 1] * 10;
	for (int cases = 1; cases <= t; ++cases)
	{
		string c,j;
		scanf("%s %s",in1,in2);
		a = in1;
		b = in2;
		memset(mark, -1, sizeof mark);
		ll ret1 = solve(0, 0, a, b);
		resa1.clear();
		resb1.clear();
		build(0, 0, resa1, resb1);

		memset(mark, -1, sizeof mark);
		ll ret2 = solve(0, 0, b, a);
		resa2.clear();
		resb2.clear();
		build(0, 0, resb2, resa2);
		
		if (ret2 < ret1)
		{
			c = resa2;
			j = resb2;
		}
		else if (ret1 < ret2)
		{
			c = resa1;
			j = resb1;
		}
		else
		{
			if (resa1 < resa2)
			{
				c = resa1;
				j = resb1;
			}
			else if (resa1 == resa2)
			{
				if (resb1 < resb2)
				{
					c = resa1;
					j = resb1;
				}
				else
				{
					c = resa2;
					j = resb2;	
				}
			}
			else
			{
				c = resa2;
				j = resb2;
			}
		}

		printf("Case #%d: %s %s\n",cases,c.c_str(), j.c_str());
	}
	return 0;
}