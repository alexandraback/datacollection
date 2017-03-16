#include <cstdio>

int a[1024];
double b[1024];

int main()
{
	FILE *in = fopen("A-large.in", "r");
	FILE *out = fopen("output.txt", "w");

	//in = stdin;
	//out = stdout;
	int tn, ti = 0;
	fscanf(in, "%d", &tn);
	while(tn--)
	{
		int n;
		int total = 0;
		fscanf(in, "%d", &n);
		for(int i = 0 ; i < n; ++i)
		{
			fscanf(in, "%d", &a[i]);
			total += a[i];
		}
		double avg = (double)total*2 / n;
		double dt = 0;
		for(int i = 0; i < n; ++i)
			if(avg - a[i] > 0) dt += (avg-a[i]) / total;
		avg /= dt;
		dt = 0;
		for(int i = 0; i < n; ++i)
		{
			if(avg - a[i] <= 0) b[i] = 0;
			else b[i] = (avg-a[i]) / total;
			dt += b[i];
		}
		fprintf(out, "Case #%d:", ++ti);
		for(int i = 0; i < n; ++i)
			fprintf(out, " %.7lf", b[i]/dt*100.);
		fprintf(out, "\n");
	}
}
