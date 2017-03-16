#include <tchar.h>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
typedef unsigned uint;
typedef unsigned __int64 uint64;

vector<uint64> binomials;
int max_c;
uint64 Binomial(uint n, uint k)
{
	if(n>=max_c || !(0<=k && k<=n)) __asm int 3;
	return binomials[n*max_c+k];
}
void SetBinomial(uint n, uint k, uint64 val)
{
	if(n>=max_c || !(0<=k && k<=n)) __asm int 3;
	binomials[n*max_c+k] = val;
}
void precalc(uint mx)
{
	max_c = mx;
	binomials.resize(max_c*max_c);
	for(uint k=0; k<max_c; k++) 
	{
		SetBinomial(k, 0, 1);
	}
	for(uint k=1; k<max_c; k++) 
	{
		SetBinomial(k, k, 1);
		for(uint n=k+1; n<max_c; n++)
		{
			SetBinomial(n, k, Binomial(n-1, k-1) + Binomial(n-1, k));
		}
	}
}

uint N, X, Y, K, R;

uint64 dcount(uint c)
{
	return 2*c*c-c;
}

double solve()
{
	K = (X+Y)/2;
	if(N >= dcount(K+1)) return 1.0;
	if(N <= dcount(K)) return 0.0;
	R = N - dcount(K);

	if(X==0)
	{
		return 0.0;
	}

	if(R<=Y) return 0.0;
	if(R>2*K+Y) return 1.0;

	uint64 sum = 0;

	for(uint f = Y+1; f <= min(R, 2*K); f++)
	{
		sum += Binomial(R, f);
	}

	return (double)sum / pow(2, (double)R);
}

int _tmain(int argc, _TCHAR* argv[])
{
	precalc(21);

	uint cTask, iTask;
	double ret;

	FILE* fin  = fopen("task.in", "rt");
	FILE* fout = fopen("task.out", "wt");

	fscanf(fin, "%u", &cTask);
	for(iTask=1; iTask<=cTask; iTask++)
	{
		fscanf(fin, "%u %u %u", &N, &X, &Y);
tryagain:
		ret = solve();
		fprintf(fout, "Case #%u: %0.06f\n", iTask, ret);
	}
	fclose(fin);
	fclose(fout);
	printf("done\n");
	getch();
}
