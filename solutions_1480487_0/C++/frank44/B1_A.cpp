#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef long long Long;
typedef unsigned long long uLong;

const double PI = acos(-1.0);
const double EPS = 1e-12;

#define FOR(i,a,b) for (int i=(int)(a); i<(int)(b); ++i)

int n;
int J[256];
double ans[256];
int sum;

bool can_lose(int p, double y)
{
	double myScore = J[p] + y*sum;

	double left = 1.-y;
	FOR(i,0,n)
		if (i != p)
		{
			double y_i = (myScore - J[i])/sum;
			if (y_i > EPS + left) return false;

			if (y_i > 0)
				left -= y_i;
		}

	if (left < EPS) return false;
	return true;
}

double binarySearch(int p)
{
	double lo = 0., hi = 1., mid;

	for (int i=0; i<1000; i++)
	{
		mid = (lo + hi)/2;

		if (can_lose(p, mid))
		{
			lo = mid;
		}
		else 
		{
			hi = mid;
		}
	}

	return lo;
}

void solve()
{
	cin >> n;

	sum = 0;
	FOR(i,0,n)
	{
		cin >> J[i];
		sum += J[i];
	}

	FOR(i,0,n)
		ans[i] = 100*binarySearch(i);

	FOR(i,0,n)
		cout << " " << setprecision(10) << ans[i];
	cout << endl;
}

int main()
{
	freopen("data.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;
	cin >> T;
	for (int x=1; x<=T; x++) 
	{
		printf("Case #%d:", x);
		solve();
	}

	return 0;
}
