/**					Be name Khoda					**/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <bitset>
#include <limits>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <memory.h>
using namespace std;

#define ll long long
#define un unsigned
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define VAL(x) #x << " = " << x << "   "
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define CLR(x, a) memset(x, a, sizeof x)
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define X first
#define Y second
#define SAL cerr << "Salam!\n"
#define PI 3.141592654

#define cout fout
#define cin fin

ifstream fin("A-small-attempt0.in");
ofstream fout("A-small-attempt0.out");

const int MAXN = 1 * 1000 + 10, INF = 1e9 + 7;

ll a[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc ++)
	{
		ll s, n, cur = 0, ans;
		cin >> s >> n;
		ans = n;
		for (int i = 0; i < n; i ++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; i ++)
		{
			ans = min(ans, cur + n - i);
			while (s <= a[i])
			{
				s *= 2;
				s --;
				if (s == 1)
				{
					cur ++;
					break;
				}
				cur ++;
			}
			if (s > 1)
				s += a[i];
			//cout << VAL(cur) << endl;
		}
		ans = min(ans, cur);
		cout << "Case #" << tc << ": " << ans << endl;
	}
	return 0;
}
