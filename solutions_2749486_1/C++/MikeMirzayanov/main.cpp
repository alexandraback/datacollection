#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

typedef long long li;

string path(int n, int xd, int yd, int x, int y)
{
	int sumx = 0;
	int sumy = 0;

	sumx += xd;
	sumy += yd;

	string result = "";

	for (int i = n; i >= 1; i--)
	{
		if (i == xd)
		{
				result += "W";
				continue;
		}
		if (i == yd)
		{
				result += "S";
				continue;
		}

		if (sumx + i <= x)
		{
			sumx += i;
			result += "E";
		}
		else
		{
			if (sumy + i <= y)
			{
				sumy += i;
				result += "N";
			}
			else
				return "";
		}
	}

	if (sumx == x && sumy == y)
	{
		reverse(result.begin(), result.end());
		return result;
	}
	else
		return "";
}

char ng[255];

string neg(string s)
{
	ng['N'] = 'E';
	ng['E'] = 'N';
	ng['S'] = 'W';
	ng['W'] = 'S';

	for (int i = 0; i < s.length(); i++)
		s[i] = ng[s[i]];

	return s;
}

int main(int argc, char* argv[])
{
    // freopen("input.txt", "rt", stdin);

    int testCases;
    cin >> testCases;

    forn(tt, testCases)
    {
    	int x, y;
    	cin >> x >> y;

    	int ox = x, oy = y;

    	bool negx = false, negy = false;
    	if (x < 0)
    		x = -x, negx = true;
    	if (y < 0)
    		y = -y, negy = true;

    	int n = 1;
    	int sum = 1;
    	while (true)
    	{
    		if (sum >= x + y && (sum % 2) == (x + y) % 2)
    			break;
    		n++;
    		sum += n;
    	}

    	// cout << n << endl;

    	string result;
    	int d = 0;

    	if (sum > x + y)
    	{
    		d = (sum - x - y) / 2;

    		for (int xd = 0; xd <= d; xd++)
    		{
	    		string s = path(n, xd, (d - xd), x + 2 * xd, y + 2 * (d - xd));
	    		if (s != "")
	    		{
	    			result = s;
    				goto end;
	    		}
    		}
    	}
		else
			result = path(n, 0, 0, x, y);

end:
		if (negx)
		{
			forn(i, result.length())
			{
				if (result[i] == 'E')
					result[i] = 'W';
				else if (result[i] == 'W')
					result[i] = 'E';
			}
		}

		if (negy)
		{
			forn(i, result.length())
			{
				if (result[i] == 'N')
					result[i] = 'S';
				else if (result[i] == 'S')
					result[i] = 'N';
			}
		}

		int ex = 0, ey = 0;
		forn(i, result.size())
		{
			if (result[i] == 'N')
				ey += i + 1;
			if (result[i] == 'S')
				ey -= i + 1;
			if (result[i] == 'E')
				ex += i + 1;
			if (result[i] == 'W')
				ex -= i + 1;
		}

		assert(ox == ex && oy == ey);

    	cout << "Case #" << (tt + 1) << ": " << result << endl;
    }

    return 0;
}
