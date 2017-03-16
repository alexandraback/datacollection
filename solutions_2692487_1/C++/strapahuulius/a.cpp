// GCJ Round 1B 2013
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
bool check(LL a, VI v, int n_add)
{
	priority_queue<int, VI, greater<int> > pq;
	FORIT(it, v)
		pq.push(*it);
	while (!pq.empty())
	{
		if (pq.top() < a)
		{
			a += pq.top();
			pq.pop();
		}
		else
		{
			if (n_add <= 0)
				return false;
			a += a - 1;
			assert(a < OO);
			n_add--;
		}
	}
	return true;
}
int main(int argc, char **argv)
{
	int kase;
	int n_read = scanf("%d\n", &kase);
	assert(n_read == 1);
	int kase_a = 0, kase_b = oo;
	if (argc > 1)
	{
		assert(argc == 3);
		int n_read = sscanf(argv[1], "%d", &kase_a);
		assert(n_read == 1);
		n_read = sscanf(argv[1], "%d", &kase_b);
		assert(n_read == 1);
		if (kase_a >= kase)
			return 0;
	}
	for (int tkase=0; tkase<kase; tkase++)
	{
		// read case
		int a, n;
		cin >> a >> n;
		VI v(n);
		for (int i=0; i<n; i++)
			cin >> v[i];
		if (tkase < kase_a || tkase >= kase_b)
			continue;
		// process case
		int res = n;
		sort(v.begin(), v.end());
		for (int i=0; i<res; i++)
			for (int j=0; j+i<res; j++)
			{
				VI w = v;
				for (int k=0; k<i; k++)
					w.pop_back();
				if (check(a, w, j))
					res = min(res, i + j);
			}
		printf("Case #%d: ", tkase+1);
		cout << res << endl;
	}
	return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
