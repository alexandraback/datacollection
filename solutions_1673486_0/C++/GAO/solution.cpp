#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>

using namespace std;

double option1(int a, int b, const vector<double>& p);
double option2(int a, int b, const vector<double>& p);
double option3(int a, int b, const vector<double>& p);

double solve()
{
	int a, b;
	scanf("%d %d", &a, &b);

	vector<double> p(b);
	for (int i = 0; i < a; ++i)
		scanf("%lf", &p[i]);

	double ans = option1(a, b, p);
	ans = min(ans, option2(a, b, p));
	ans = min(ans, option3(a, b, p));

	return ans;
}

double option1(int a, int b, const vector<double>& p)
{
	double q = 1;
	for (int i = 0; i < a; ++i)
		q *= p[i];

	double ans = q * (b - a + 1) + (1 - q) * (b + 1 + b - a + 1);
	return ans;
}

double option2(int a, int b, const vector<double>& p)
{
	double q = 1;
	double ret = DBL_MAX;
	for (int i = 0; i < a; ++i)
	{
		double tmp = q * (b - i + 1 + a - i) + (1 - q) * (b - i + 1 + b + 1 + a - i);
		ret = min(ret, tmp);

		q *= p[i];
	}

	return ret;
}

double option3(int a, int b, const vector<double>& p)
{
	return b + 2;
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);

	int caseNum;
	scanf("%d", &caseNum);

	for (int caseId = 1; caseId <= caseNum; ++caseId)
	{
		printf("Case #%d: %.6lf\n", caseId, solve());
	}
	
	return 0;
}