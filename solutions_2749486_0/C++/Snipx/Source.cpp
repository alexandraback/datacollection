# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <math.h>
# include <algorithm>
# include <string.h>
# include <stack>
# include <queue>
# include <sstream>
# include <set>
# include <map>
# include <assert.h>
using namespace std;
int main()
{
	//ios_base::sync_with_stdio(false);
	ifstream cin ("input.txt");
	ofstream cout ("output.txt");

	int tests;
	cin >> tests;
	for (int test = 0; test < tests; test++)
	{
		int x, y;
		cin >> x >> y;
		int curx = 0, cury = 0;
		string ans = "";
		int jump = 1;

		
		while (curx != x)
		{
			if (curx == 0)
			{
				if (x < 0)
					curx += jump++, ans += "E";
				else
					curx -= jump++, ans += "W";
			}
			else if (x >= 0 && curx >= 0)
				curx -= jump++, ans += "W";
			else if (x >= 0 && curx <= 0)
				curx += jump++, ans += "E";
			else if (x <= 0 && curx <= 0)
				curx += jump++, ans += "E";
			else if (x <= 0 && curx >= 0)
				curx -= jump++, ans += "W";
		}

		while (cury != y)
		{
			if (cury == 0)
			{
				if (y < 0)
					cury += jump++, ans += "N";
				else
					cury -= jump++, ans += "S";
			}
			else if (y >= 0 && cury >= 0)
				cury -= jump++, ans += "S";
			else if (y >= 0 && cury <= 0)
				cury += jump++, ans += "N";
			else if (y <= 0 && cury >= 0)
				cury -= jump++, ans += "S";
			else if (y <= 0 && cury <= 0)
				cury += jump++, ans += "N";
		}

		cout << "Case #" << test + 1 << ": " << ans << endl;
	}

	//system("pause");
	return 0;
}
