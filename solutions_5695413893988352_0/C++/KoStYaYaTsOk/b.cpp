#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include<string>
#include<algorithm>

using namespace std;

#define mp make_pair
#define pb push_back 
#define fi(n) for(int i = 0; i < n; i++)
#define fj(n) for(int j = 0; j < n; j++)
#define f first
#define s second
#define ll long long
#define itt ::iterator it = 

ifstream in;
ofstream out;

void f(string & x, string & y, int i, ll & mindist, string &mx, string &my)
{
	if (i == x.size())
	{
		ll xl = _atoi64(x.c_str());
		ll yl = _atoi64(y.c_str());
		ll d = abs(xl - yl);
		if (d < mindist || (d == mindist && _atoi64(mx.c_str()) > xl) || (d == mindist && _atoi64(mx.c_str()) == xl && _atoi64(my.c_str()) > yl))
		{
			mindist = d;
			mx = x;
			my = y;
		}
		return;
	}


	if (x[i] == '?')
	{
		if (y[i] == '?')
		{
			x[i] = '0'; y[i] = '0';
			f(x, y, i + 1, mindist, mx, my);
			x[i] = '0'; y[i] = '1';
			f(x, y, i + 1, mindist, mx, my);
			x[i] = '1'; y[i] = '0';
			f(x, y, i + 1, mindist, mx, my);
			x[i] = '0'; y[i] = '9';
			f(x, y, i + 1, mindist, mx, my);
			x[i] = '9'; y[i] = '0';
			f(x, y, i + 1, mindist, mx, my);
			x[i] = '?';
			y[i] = '?';
		}
		else
		{
			if (y[i] != '0')
			{
				x[i] = y[i] - 1;
				f(x, y, i + 1, mindist, mx, my);
			}
			if (y[i] != '9')
			{
				x[i] = y[i] + 1;
				f(x, y, i + 1, mindist, mx, my);
			}
			x[i] = '9';
			f(x, y, i + 1, mindist, mx, my);
			x[i] = '0';
			f(x, y, i + 1, mindist, mx, my);
			x[i] = y[i];
			f(x, y, i + 1, mindist, mx, my);
			x[i] = '?';
		}
	}
	else if (y[i] == '?')
	{
		if (x[i] != '0')
		{
			y[i] = x[i] - 1;
			f(x, y, i + 1, mindist, mx, my);
		}
		if (x[i] != '9')
		{
			y[i] = x[i] + 1;
			f(x, y, i + 1, mindist, mx, my);
		}
		y[i] = '9';
		f(x, y, i + 1, mindist, mx, my);
		y[i] = '0';
		f(x, y, i + 1, mindist, mx, my);
		y[i] = x[i];
		f(x, y, i + 1, mindist, mx, my);
		y[i] = '?';
	}
	else
		f(x, y, i + 1, mindist, mx, my);
}

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		ll mindist = 0x7FFFFFFFFFFFFFFF;
		string x, y;
		cin >> x >> y;
		
		string mx, my;
		f(x, y, 0, mindist, mx, my);

		cout << "Case #" << tc << ": " << mx << " " << my << endl;
	}
	

	return 0;
}

