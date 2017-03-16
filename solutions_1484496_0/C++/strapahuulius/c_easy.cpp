// GCJ 2012 Round 1B - Problem C
// -- strapahuulius

// pre-written code follows
// #includes {{{
#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
// }}}
// constants, typedefs, macros {{{
typedef long long LL;
typedef unsigned long long ULL;
const int oo = 1000000000;
const LL OO = 1000000000000000000LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<string> VS;
typedef queue<int> QI;
typedef queue<PII> QPII;
typedef complex<double> tComp;
const double PI = 2.0 * acos(0.0);
const double EPS = 1e-9;
#define FORIT(i,c) for (typeof((c).end()) i=(c).begin(); i!=(c).end(); ++i)
#define CERR(x) cerr << (#x) << " = " << (x) << endl
#define COUT(x) cout << (#x) << " = " << (x) << endl
// }}}

// code written during the competition follows
int main()
{
	int kase;
	scanf("%d\n", &kase);
	for (int tkase=0; tkase<kase; tkase++)
	{
		printf("Case #%d:\n", tkase+1);
		int n;
		cin >> n;
		vector<int> v(n);
		int sum = 0;
		for (int i=0; i<n; i++)
		{
			cin >> v[i];
			sum += v[i];
		}
		bool impossible = true;
		int k = 1 << n;
		for (int i=1; i<k; i++)
		{
			int psum = 0;
			for (int j=0; j<n; j++)
				if (i & (1 << j))
					psum += v[j];
			vector<PII> dp(psum + 1, PII(0, 0));
			dp[0].first = 1;
			for (int j=0; j<n; j++)
				if (!(i & (1 << j)))
				{
					for (int s=psum-v[j]; s>=0; s--)
						if (dp[s].first)
						{
							dp[s + v[j]] = PII(1, dp[s].second | 1 << j);
						}
				}
			if (dp[psum].first == 1)
			{
				bool first = true;
				for (int j=0; j<n; j++)
					if (i & (1 << j))
					{
						if (first)
							first = false;
						else
							cout << " ";
						cout << v[j];
					}
				cout << endl;
				first = true;
				for (int j=0; j<n; j++)
					if (dp[psum].second & (1 << j))
					{
						if (first)
							first = false;
						else
							cout << " ";
						cout << v[j];
					}
				cout << endl;
				impossible = false;
				break;
			}
		}
		if (impossible)
			cout << "impossible" << endl;
	}
	return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
