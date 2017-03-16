#include <iostream>
#include <cmath>
using namespace std;

struct point
{
	double t,s;
};

point p[2000];

int main()
{
	int T;
	cin >> T;
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d:\n", t);
		double D;
		int N,A;
		cin >> D >> N >> A;
		for(int i=0;i<N;i++)
		{
			cin >> p[i].t >> p[i].s;
		}
		if(p[0].s>=D)
			N = 0;
		for(int i=N-1;i>0;i--)
		{
			if(p[i-1].s>=D) continue;
			p[i].t = p[i-1].t + (D-p[i-1].s)*(p[i].t-p[i-1].t)/(p[i].s - p[i-1].s);
			p[i].s = D;
			N = i+1;
			break;
		}
		for(int i=0;i<A;i++)
		{
			double a;
			cin >> a;
			double T = 0;
			for(int j=0;j<N;j++)
			{
				double temp = p[j].t - sqrt(2*p[j].s/a);
				if(temp>T)
					T = temp;
			}
			T += sqrt(2*D/a);
			printf("%.7lf\n",T);
		}
	}
}
