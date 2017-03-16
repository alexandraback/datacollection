#include<algorithm>
#include<cstdio>
#include<ctime>
#include<iostream>
#include <cassert>
#include <vector>
#include <bitset>
#include <string>

using namespace std;

typedef pair<int, int> PairInt;
#define sqr(x) ((x)*(x))

const double EPS = 1e-8;

double t[2010], x[2010];

double sovle_equation(double a, double b, double c)
{
	double d = sqr(b) - 4*a*c;
	assert(d >= 0);
	d = sqrt(d);
	double dt1 = (-b+d) / (2*a), dt2 = (-b-d)/ (2*a);
	double Min = min(dt1, dt2), Max = max(dt1,dt2);
	return Min > 0 ? Min : Max;
}

double Work(double D, int n, double a)
{
	double now_x = 0, now_v = 0, now_t = 0;
	for (int i = 0; i < n - 1; i++) {
		assert(now_x <= x[i]);
		double c = (x[i+1] - x[i]) / (t[i+1] - t[i]);
		double dt = sovle_equation(-a/2, c-now_v, x[i]-now_x);
		dt = min(dt, min(D, x[i+1]) / c);
		double xx = x[i] + c * dt;
		now_x += now_v*dt + a/2*dt*dt;
		now_v += a*dt;
		now_t += dt;
		if (xx >= D) {
			break;
		}
		if (fabs(now_x - xx) < EPS) { 
			double rx = min(D, x[i+1]) - now_x;
			now_x += rx;
			now_t += rx / c;
			now_v = c;
		} else { 

		}
	}
	return now_t + sovle_equation(a/2, now_v, now_x - D);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, c = 1;
	for (scanf("%d", &T); T--; ) {
		printf("Case #%d:\n", c++);
		double D;
		int n, A;
		scanf("%lf%d%d", &D, &n, &A);
		for (int i = 0 ; i < n;  i++)  {
			scanf("%lf%lf", &t[i], &x[i]);
		}
		for (int i = 0; i < A; i++) {
			double a;
			scanf("%lf", &a);
			printf("%.8f\n", Work(D, n, a));
		}
	}
	return 0;
}


