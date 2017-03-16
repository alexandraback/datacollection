#include <bits/stdc++.h>
using namespace std;

/*
*/

char C[25];
char J[25];
int n;
string r1, r2;
string c1, c2;
bool cmp()
{
	long long a, b, c, d;
	a = b = c = d = 0;
	long long pw = 1;
	for (int i = n-1; i >= 0; i--)
	{
		c += pw*(r1[i]-'0');
		d += pw*(r2[i]-'0');
		a += pw*(c1[i]-'0');
		b += pw*(c2[i]-'0');
		pw *= 10;
	}
	if (abs(a-b) < abs(c-d))
		return true;
	else if (abs(a-b) > abs(c-d))
		return false;
	return make_pair(a, b) < make_pair(c, d);
}

void solve(int i, int p)
{
	for (int j = i; j < n; j++)
	{
		if (p == 0)
		{
			if (C[j] == '?')
				c1[j] = '9';
			if (J[j] == '?')
				c2[j] = '0';
		}
		else
		{
			if (C[j] == '?')
				c1[j] = '0';
			if (J[j] == '?')
				c2[j] = '9';
		}
	}
	if (cmp())
	{
		r1 = c1;
		r2 = c2;
	}
}

int main()
{
	freopen("input.in", "r", stdin);
	freopen("input.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int z = 1; z <= T; z++)
	{
		scanf("%s", C);
		scanf("%s", J);
		n = strlen(C);
		r1 = string(C);
		r2 = string(J);
		for (int i = 0; i < n; i++)
		{
			if (r1[i] == '?')
				r1[i] = '0';
			if (r2[i] == '?')
				r2[i] = '0';
		}
		for (int i = 0; i <= n; i++)
		{
			bool ok = true;
			c1 = string(C);
			c2 = string(J);
			for (int j = 0; j < i; j++)
			{
				if (c1[j] == '?')
					c1[j] = c2[j];
				if (c2[j] == '?')
					c2[j] = c1[j];
				if (c1[j] == '?')
					c1[j] = c2[j] = '0';
				if (c1[j] != c2[j])
					ok = false;
			}
			if (!ok)
				break;
			if (i < n)
			{
				if (c1[i] == '?' && c2[i] == '?')
				{
					c1[i] = '1';
					c2[i] = '0';
					solve(i+1, 1);
					c1[i] = '0';
					c2[i] = '1';
					solve(i+1, 0);
				}
				else if (c1[i] == '?')
				{
					if (c2[i] < '9')
					{
						c1[i] = c2[i]+1;
						solve(i+1, 1);
					}
					if (c2[i] > '0')
					{
						c1[i] = c2[i]-1;
						solve(i+1, 0);
					}
				}
				else if (c2[i] == '?')
				{
					if (c1[i] < '9')
					{
						c2[i] = c1[i]+1;
						solve(i+1, 0);
					}
					if (c1[i] > '0')
					{
						c2[i] = c1[i]-1;
						solve(i+1, 1);
					}
				}
			}
			solve(i, 0);
			solve(i, 1);
		}
		cout<<"Case #"<<z<<": "<<r1<<" "<<r2<<endl;
	}
}