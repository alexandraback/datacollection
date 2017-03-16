#include <cstdio>
#include <cmath>

double a[2][2];

int main()
{
	FILE *in = fopen("B-small-attempt1.in", "r");
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
			if(n == 2)
			{
				double v = (a[1][1] - a[0][1]) / (a[1][0] - a[0][0]);
				double t = (v + sqrt(v*v + 2.*acc*a[0][1])) / acc;
				ans = sqrt(2.*acc*D) / acc;
				if(ans > t) ans = a[0][0] + (D - a[0][1]) / v;
			}
			else ans = sqrt(2.*acc*D) / acc;
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