#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <ctime>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define VAL(x) #x << " = " << (x) << "   "
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define CLR(x, a) memset(x, a, sizeof x)
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define FOR(i, n) for (int i = 0; i < (n); i ++)
#define X first
#define Y second
#define EPS (1e-8)

//#define cin fin
//#define cout fout

//ifstream fin("problem.in");
//ofstream fout("problem.out");

const int MAXN = 1 * 10 + 10;

double a[MAXN], b[MAXN];
bool mark[MAXN];

int main ()
{
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	
	for (int o = 1; o <= tc; o ++)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i ++) cin >> a[i];
		for (int i = 0; i < n; i ++) cin >> b[i];

		sort(a, a + n);
		sort(b, b + n);

		int ans1 = 0, ans2 = 0;
		do
		{
			CLR(mark, 0);
			int cur = 0;
			for (int i = 0; i < n; i ++) cur += (a[i] > b[i]);
			ans1 = max(ans1, cur);
		}
		while (next_permutation(a, a + n));

		sort(a, a + n);
		do
		{
			CLR(mark, 0);
			int cur = 0;
			for (int i = 0; i < n; i ++)
			{
				bool check = true;
				for (int j = 0; j < n; j ++)
					if (!mark[j] && b[j] > a[i])
					{
						check = false;
						mark[j] = true;
						break;
					}
				if (check)
				{
					for (int j = 0; j < n; j ++)
						if (!mark[j])
						{
							mark[j] = true;
							break;
						}
				}
				cur += check;
			}

			ans2 = max(ans2, cur);
		}
		while (next_permutation(a, a + n));

		cout << "Case #" << o << ": ";
		cout << ans1 << ' ' << ans2 << endl;
	}
	return 0;
}

