// GCJ 2012 Round 1B - Problem A
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
		int n;
		cin >> n;
		VI p;
		int sum = 0;
		for (int i=0; i<n; i++)
		{
			int x;
			cin >> x;
			p.push_back(x);
			sum += x;
		}
		printf("Case #%d:", tkase+1);
		for (int i=0; i<n; i++)
		{
			double a = 0.0, c = 1.0;
			for (int k=0; k<300; k++)
			{
				double b = 0.5 * (a + c);
				double s = p[i] + b * sum;
				double r = 1.0 - b;
				for (int j=0; j<n; j++)
				{
					if (j == i)
						continue;
					if (s < p[j])
						continue;
					r -= (s - p[j]) / sum;
				}
				if (r < 0)
					c = b;
				else
					a = b;
			}
			printf(" %.6lf", a * 100.0);
		}
		puts("");
	}
	return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
