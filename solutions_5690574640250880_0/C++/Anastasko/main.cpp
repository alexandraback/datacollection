//#pragma comment(linker, "/STACK:134217728")
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

typedef pair<int, int> PII;
typedef vector<int> VI;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(int i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair
#define MOD 1000000009
#define INF 1000000007
#define y1 agaga
#define ll long long
#define ull unsigned long long

string s[74];
bool ok;
int r, c, m;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;

	FOR(T, 0, t)
	{
		cin >> r >> c >> m;

		FOR(i, 0, r)
		{
			s[i] = "";
			FOR(j, 0, c)
				s[i] += '*';
		}

		m = r*c - m;
		ok = (m==1);

		if (m == r*c)
		{
			FOR(i, 0, r)
				FOR(j, 0, c)
				s[i][j] = '.';
			ok = true;
		}

		if (r == 1 || c == 1)
		{
			if (r == 1)
				FOR(i, 0, m)
				s[0][i] = '.';

			if (c == 1)
				FOR(i, 0, m)
				s[i][0] = '.';

			ok = true;
		}
		else
		{
			
			{
			
				FOR(mc, 2, c + 1)
					FOR(mr, 2, r + 1)
				if (!ok && mc*2+mr*2-4<=m && mc*mr>=m)
					{
						FOR(i, 0, mr)
						{						
							s[i][0] = '.';
							s[i][1] = '.';
						}

						FOR(j, 0, mc)
						{
							s[0][j] = '.';
							s[1][j] = '.';
						}

						int has = mc * 2 + mr * 2 - 4;

						int j = 2;
						int i = 2;

						while (has < m)
						{
							s[i][j] = '.';
							i++;

							if (i == mr)
							{
								i = 2;
								j++;
							}

							has++;
						}

						ok = true;
					}
			}
		}

		s[0][0] = 'c';
		cout << "Case #" << T + 1 << ":" << endl;
		if (ok)
		{
			FOR(i, 0, r)
				cout << s[i] << endl;
		}

		else
			cout << "Impossible" << endl;
	}

	return 0;
}
