#include <cstdio>
#include <cmath>

double a[2048][2];

int main()
{
	FILE *in = fopen("B-large.in", "r");
	FILE *out = fopen("output.txt", "w");

	//in = stdin;
	//out = stdout;

	int tn, ti = 0;
	fscanf(in, "%d", &tn);
	while(tn--)
	{
		double D;
		int n, tnn;
		fscanf(in, "%lf %d %d\n", &D, &n, &tnn);
		for(int i = 0; i < n; ++i)
			fscanf(in, "%lf %lf\n", &a[i][0], &a[i][1]);
		fprintf(out, "Case #%d:\n", ++ti);
		while(tnn--)
		{
			double ans;
			double acc;
			fscanf(in, "%lf", &acc);
			if(n < 2) ans = sqrt(2.*acc*D) / acc;
			else
			{
				ans = 0;
				double v0 = 0;
				double x0 = 0;
				for(int i = 1; i < n; ++i)
				{
					double x = a[i][1];
					if(x >= D) x = D;
					double v = (a[i][1] - a[i-1][1]) / (a[i][0] - a[i-1][0]);
					double t = ((v-v0) + sqrt((v-v0)*(v-v0) + 2.*acc*a[i-1][1])) / acc;
					double t2 = (-v0 + sqrt(v0*v0+2.*acc*(x-x0))) / acc;
					if(t2 > t) ans += (x-a[i-1][1]) / v;
					else ans += t2;
					v0 = v0 + acc*t2;
					x0 = x;
				}
			}
			fprintf(out, "%.7lf\n", ans);
		}
	}
}

/*
2
1000.000000 2 3
0.000000 20.500000
25.000000 1000.000000
1.00 5.00 9.81
50.000000 2 2
0.000000 0.000000
100000.000000 100.000000
1.00 1.01
*/