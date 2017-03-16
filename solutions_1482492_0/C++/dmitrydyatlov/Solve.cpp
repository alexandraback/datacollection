#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long lint;
typedef vector<int> vi;
typedef vector<string> vs;
const int INF = 0x7fffffff;

int Solution()
{
	double d;
	int n, A;
	cin >> d >> n >> A;
	double x1, t1, x2, t2;
	cin >> t1 >> x1;
	if(n == 2)
		cin >> t2 >> x2;
	for(int i = 0; i < A; ++i)
	{
		double a;
		cin >> a;
		if(n == 1)
		{
			double ans = sqrt(d * 2. / a);
			printf("%.8lf\n", ans);
			continue;
		}

		double tt = t1 + (d - x1) / ((x2 - x1) / (t2 - t1));
		double tn = sqrt(d * 2. / a);
		double ans = max(tt, tn);
		printf("%.8lf\n", ans);
	}

	return 0;
}

#define debug 1

int main()
{
#ifdef debug
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
#endif
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		cout << "Case #" << i << ":" << endl;;
		Solution();
	}
	return 0;
}
