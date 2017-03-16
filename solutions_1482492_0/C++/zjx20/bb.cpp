#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

bool equal(double a,double b)
{
	return fabs(a-b) < 1e-8;
}

const int N = 2010;
const int A = 300;

double tt[N];
double xx[N];
double aa[A];

double solve_xxx(double acc, double car_v, double car_pos, double &ttt)
{
	double a = 0.5 * acc;
	double b = -car_v;
	double c = -car_pos;

	ttt = (-b+sqrt(b*b-4.0*a*c))/(2*a);

	return car_pos + ttt * car_v;
}

double solve_t(double acc, double v, double s)
{
	double a = 0.5*acc;
	double b = v;
	double c = -s;

	return (-b+sqrt(b*b-4.0*a*c))/(2*a);
}

double calc(double acc,int n, double d)
{
	//double sum = 0;
	//double v = 0;
	//double pos = 0;

	//double pos_car = xx[0];
	//double curr = 0;
	//double car_v = 0;

	//int i = 0;
	//while(!equal(d, pos))
	//{
	//	if(equal(pos, pos_car))
	//	{
	//		car_v = (xx[i+1] - xx[i]) / (tt[i+1] - tt[i]);
	//		double next = xx[++i];
	//	}
	//}

	if(n == 1 || xx[0] >= d) return sqrt(d*2.0/acc);

	double ans = 0;

	//double fir_pos = std::min(xx[0], d);
	//double fir_t = sqrt(fir_pos*2.0/acc);
	//double fir_v = acc * fir_t;

	double fir_pos = 0;
	double fir_t = 0;
	double fir_v = 0;

	double car_v = (xx[1]-xx[0])/(tt[1]-tt[0]);
	double car_pos = xx[0];


	double match_tt = 0;
	double match_pos = solve_xxx(acc, car_v, car_pos, match_tt);
	if(equal(match_pos, d) || match_pos > d)
	{
		ans += solve_t(acc, 0, d);
	}
	else
	{
		ans += match_tt + (d - match_pos) / car_v;
	}
	return ans;
}

int main()
{
	freopen("B-small-attempt3.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t,ca=0;

	int i,j;

	scanf("%d: ",&t);
	while(t--)
	{
		printf("Case #%d:\n",++ca);

		double d;
		int n,a;

		scanf("%lf%d%d",&d,&n,&a);
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf",&tt[i],&xx[i]);
		}
		for(i=0;i<a;i++)
			scanf("%lf",&aa[i]);

		for(i=0;i<a;i++)
			printf("%.7lf\n", calc(aa[i], n, d));
	}
	return 0;
}