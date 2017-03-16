#include<cstdio>

using namespace std;

long int v[100]  = {0};
long int Emax=0, N=0,  R = 0, Gmax = 0;

int some(int actno, long int energy, long int gain)
{
	if(actno >= N)
		return 0;

	long int enr = energy, ga = gain;

	for(long int i=0; i<=enr; i++)
	{
		energy = enr;
		gain = ga;

		energy = energy - i + R;
		
		if(energy > Emax)
			energy = Emax;

		gain = gain + (v[actno] * i);

		if(gain > Gmax)
			Gmax = gain;
		
		//printf("%d %ld %ld %ld\n", actno, energy, gain, i);
		some(actno + 1, energy, gain); 
	}
}

int main(int argc, char** argv)
{
	int t = 0;
	FILE *fp = fopen(argv[1], "r");
	FILE *fm = fopen(argv[2], "w");
	fscanf(fp, "%d", &t);

	for(int i=0; i<t; i++)
	{
		fscanf(fp, "%ld %ld %ld", &Emax, &R, &N);

		for(int j=0; j<N; j++)
			fscanf(fp, "%ld", &v[j]);
		
		some(0, Emax, 0);
		
		fprintf(fm, "Case #%d: %ld\n", i+1, Gmax);
		Gmax = 0;
	}
	
	fclose(fp);
	fclose(fm);
	return 0;
}
