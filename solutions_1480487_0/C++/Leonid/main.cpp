#include <iostream>
using namespace std;

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <vector>
#include <map>
#include <string>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <set>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)

void openFiles() {
	freopen("test_small.in", "rt", stdin);
	freopen("test_small.out", "wt", stdout);	
}

bool is_weakest(int contestant, int n, int* judge, int sumjudge, double votepublic) {
	double votepublicleft = 1 - votepublic;
	double scorecontestant = judge[contestant] + sumjudge * votepublic;
	for (int i = 0; i < n; i++) {
		if (i == contestant) continue;
		if (judge[i] >= scorecontestant) continue;

		double needsatleast = (scorecontestant - judge[i]) / sumjudge;
		votepublicleft -= needsatleast;
	}

	return votepublicleft >= 0.0;
}

const double EPS = 1e-9;

void solve()
{
	int judge[205];
	int n; scanf("%d ", &n);
	int sumjudge = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d ", &judge[i]);
		sumjudge += judge[i];
	}

	static int ntest = 0;
	printf("Case #%d:", ++ntest);

	for (int i = 0; i < n; i++) {

		double mn = 0.0, mx = 1.0;
		while (mx - mn > EPS) {

			double mid = (mx + mn) / 2;
			if (is_weakest(i, n, judge, sumjudge, mid)) {
				mn = mid;
			} else {
				mx = mid;
			}

		}

		double mid = (mx + mn) / 2;
		printf(" %.10lf", mid * 100);
	}
	printf("\n");

	
}

int main()
{
	openFiles();

	int n; scanf("%d ", &n);
	// make sure output directory exists MY_SOLUTION/output
	for (int i = 0; i < n; i++) {		
		solve();
	}
	
	return 0;
}