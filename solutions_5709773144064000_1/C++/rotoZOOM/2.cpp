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

#define in_str(b) scanf("%s",(b))
#define in_int1(a) scanf("%d",&(a))
#define in_int2(a,b) scanf("%d%d",&(a),&(b))
#define in_int3(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
#define in_int4(a,b,c,d) scanf("%d%d%d%d",&(a),&(b),&(c),&(d))

int main ()
{
	freopen ("input.txt","rt",stdin);
	freopen ("output.txt","wt",stdout);
	int test;

	scanf ("%d",&test);
	for (int step=1;step<=test;step++)
	{
		double C, F, X;
		scanf("%lf %lf %lf", &C, &F, &X);
		double best = X / 2.0;
		double acc = 0.0;
		double speed = 2.0;
		double eps = 1e-9;
		while (true)
		{
			acc += C / speed;
			speed += F;
			if (acc + eps > best) break;
			double result = acc + X / speed;
			best = min(best, result);
		}

		printf ("Case #%d: %.7lf\n",step, best);
	}
	return 0;
}