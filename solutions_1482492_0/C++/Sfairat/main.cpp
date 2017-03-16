#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;
typedef pair <int, int> pii;
typedef long long ll;

const double EPS = 1e-10;

void test(int testNo)
{
    int N, A;
	double D;
    scanf("%lf%d%d", &D, &N, &A);
    double x1, t1, x2, t2;
	scanf("%lf%lf", &t1, &x1);
	if (N == 2)
		{
			scanf("%lf%lf", &t2, &x2);
		}

	if (x1 > D-EPS)
	{
		t1 = t1 / x1 * D;
		x1 = D;
		N = 1;
	}

	double as[500];
	for (int i = 0; i < A; i++)
	{
		scanf("%lf", as+i);
	}

	printf("Case #%d: \n", testNo+1);

	if (N == 1)
	{
		for (int i = 0; i < A; i++)
		{
			double tman = sqrt(2*x1 / as[i]);
			if (tman < t1)
				tman = t1;
			printf("%.7lf\n", tman);
		}
	}
	else
	{
		if (x2 > D)
		{
			t2 = t1 + (t2-t1) * (D-x1) / (x2-x1);
			x2 = D;
		}
		for (int i = 0; i < A; i++)
		{
			double tman = sqrt(2*x1 / as[i]);
			double tst = 0;
			if (tman < t1)
				tst = t1 - tman;
			double res = max(t2, tst + sqrt(2*x2/as[i]));
			printf("%.7lf\n", res);
		}
	}
    
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int TC;
    scanf("%d", &TC);
    
    for (int i = 0; i < TC; i++)
        test(i);
    
    return 0;
}