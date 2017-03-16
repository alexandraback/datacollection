#define _USE_MATH_DEFINES

#ifdef ONLINE_JUDGE
#define FINPUT(file) 0
#define FOUTPUT(file) 0
#else
#define FINPUT(file) freopen(file,"r",stdin)
#define FOUTPUT(file) freopen(file,"w",stdout)
#endif

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <set>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

typedef long long ll;
static const int M = 110;
static const int N = 4;
static const int LEN = 4;
static const int MAX = 0x7fffffff;
static const int MIN = ~MAX;
static const double EPS = 1e-8;

void solve(int ncase)
{
	double c, f, x;
	scanf("%lf %lf %lf", &c, &f, &x);

	int k = 0;
	double init = 2.0f;
	double cost_time = 0.0f;
	double prev_time = x / init;
	k++;

	while (true) {
		cost_time += c / init;
		init += (k * f);
		double cur_time = x / (init);
		if (prev_time > (cur_time + cost_time)) {
			prev_time = cur_time + cost_time;
		}
		else {
			break;
		}
	}

	printf("Case #%d: %.7lf\n", ncase, prev_time);
}

int main()
{
	FINPUT("in.txt");
	FOUTPUT("out.txt");

	int c, ncase = 1;
	scanf("%d", &c);
	for (int i = 0; i < c; i++) {
		solve(ncase++);
	}
	return 0;
}