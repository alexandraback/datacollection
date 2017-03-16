#include<algorithm>
#include<cstdio>
#include<ctime>
#include<iostream>
#include <cassert>
#include <vector>
#include <bitset>
#include <string>

using namespace std;

typedef pair<int, int> pii;
#define sqr(x) ((x)*(x))

const double EPS = 1e-8;

double t[2010], x[2010];

double sovle_equation(double a, double b, double c)
{
	//cout<<a<<" "<<b<<" "<<c<<endl;
	double d = sqr(b) - 4*a*c;
	assert(d >= 0);
	d = sqrt(d);
	double dt1 = (-b+d) / (2*a), dt2 = (-b-d)/ (2*a);
	double Min = min(dt1, dt2), Max = max(dt1,dt2);
	//cout<<"Min "<<Min<<" Max "<<Max<<endl;
	return Min > 0 ? Min : Max;
}

double gao(double D, int n, double a)
{
	double now_x = 0, now_v = 0, now_t = 0;
	//分阶段的
	for (int i = 0; i < n - 1; i++) {
		assert(now_x <= x[i]);
		double c = (x[i+1] - x[i]) / (t[i+1] - t[i]);
		//先全速加到“撞”
		//-a/2*dt*dt + (c-now_v)*dt + (x[i] - now_x) = 0;
		double dt = sovle_equation(-a/2, c-now_v, x[i]-now_x);
		//cout<<dt<<endl;
		dt = min(dt, min(D, x[i+1]) / c);
		double xx = x[i] + c * dt;
		//cout<<i<<" "<<now_x<<" "<<now_t<<" "<<now_v<<" "<<xx<<" "<<c<<" "<<dt<<endl;	
		//printf("%f %f %f\n", xx, x[i], c*dt);
		//printf("%d %.10f %.10f %.10f %.10f %.10f %.10f\n", i, now_x, now_t, now_v, xx, c, dt);
		now_x += now_v*dt + a/2*dt*dt;
		now_v += a*dt;
		now_t += dt;
		//printf("%.10f %.10f %.10f\n", now_x, now_t, now_v);
		if (xx >= D) {//另一辆车已经过了终点了，可以不用考虑它了
			break;
		}
		if (fabs(now_x - xx) < EPS) { //撞
			//assert(fabs(now_v - c) < EPS);
			//匀速
			double rx = min(D, x[i+1]) - now_x;
			now_x += rx;
			now_t += rx / c;
			now_v = c;//减速到c
		} else { //没撞，xx到了x[i+1]

		}
	}
	//D - now_x = now_v*dt + a/2*dt*dt 
	//全速加到D
	//printf("end  %.10f %.10f %.10f\n", now_x, now_t, now_v);
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
			printf("%.8f\n", gao(D, n, a));
		}
	}
	return 0;
}


