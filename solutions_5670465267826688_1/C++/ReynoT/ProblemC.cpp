
#include <iostream>
#include <istream>
#include <stdio.h>
#include <string>
#include <vector> 
#include <fstream>
#include <queue>
#include <algorithm>
#define INF 2147483647
#define BIG 1000000007

using namespace std; 

int cross (int a, int b)
{
	int aa = abs(a), bb = abs(b), ans;
	if (aa == 1 && bb == 1)
		ans = 1;
	else if (aa == bb && aa != 1)
		ans = -1; 
	else if ((aa == 1 && bb == 2) || (aa == 2 && bb == 1) || (aa == 3 && bb == 4))
		ans = 2;
	else if (aa == 4 && bb == 3)
		ans = -2;
	else if ((aa == 3 && bb == 1) || (aa == 1 && bb == 3) || (aa == 4 && bb == 2))
		ans = 3;
	else if (aa == 2 && bb == 4)
		ans = -3;
	else if ((aa == 4 && bb == 1) || (aa == 1 && bb == 4) || (aa == 2 && bb == 3))
		ans = 4;
	else if (aa == 3 && bb == 2)
		ans = -4;
	if (a*b < 0)
		ans = -ans; 
	return ans;
}

int conv (char a)
{
	if (a == '1')
		return 1; 
	return a - 'i' + 2;
}

int main ()
{
    freopen ("C-large.in", "r", stdin);
	freopen ("C.out", "w", stdout); 
 	int tt; 
 	cin >> tt; 
 	for (int cases = 1; cases <= tt; cases++)
 	{
 		cout << "Case #" << cases << ": ";
 		int l; 
		long long xx; 
 		string ss;
 		cin >> l >> xx >> ss;
 		int s [l], vs = 1;
		for (int x = 0; x < l; x++)
		{
			s[x] = conv (ss.at(x));
			vs = cross (vs, s[x]);
		}
		if (vs == 1 || (vs != -1 && xx%4 != 2) || (vs == -1 && xx%2 != 1))
		{
			cout << "NO\n";
			continue;
		}
		int cur = 1, ind = 0;
		long long xxx = 0, orig = 0;
		while (xxx < xx && xxx - orig < 4)
		{
			for (int x = 0; x < l; x++)
			{
				cur = cross (cur, s[x]);
				ind = x;
				if (cur == 2)
					goto J;
			}
			xxx++;
		}
		cout << "NO\n";
		continue;
		J:
		ind++;
		if (ind == l)
		{
			ind = 0;
			xxx++;
		}
		orig = xxx;
		bool first = true;
		while (xxx < xx && xxx - orig < 4)
		{
			int x; 
			if (first)
			{
				first = false;
				x = ind;
			}
			else
				x = 0;
			for (; x < l; x++)
			{
				cur = cross (cur, s[x]);
				ind = x;
				if (cur == 4)
					goto FIN;
			}
			xxx++;
		}
		cout << "NO\n";
		continue;
		FIN: 
		cout << "YES\n";
	}
}
