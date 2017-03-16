#include "stdio.h"
#include "stdlib.h"
#include "memory.h"
#include "string.h"
#include "math.h"

FILE *fin, *fout;

#define INPUT_FILE_NAME "A-large"
#define INPUT_FILE INPUT_FILE_NAME##".in"
#define OUTPUT_FILE INPUT_FILE_NAME##".out"

#define print(format,...) {fprintf(fout, format, __VA_ARGS__); printf(format, __VA_ARGS__);}

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define pow2(a) ((a)*(a))

template<class T>
inline void swap(T &a, T &b)
{
	T c;
	c=a;
	a=b;
	b=c;
}

void problem(int nCase);
void init();

void main(int argc, char **argv)
{
	int N,k;
	printf("%s\n", INPUT_FILE);
	fopen_s(&fin, INPUT_FILE, "rt");
	fopen_s(&fout, OUTPUT_FILE, "wt");
	fscanf_s(fin, "%d\n", &N);
	k=0;
	init();
	while(N--)
	{
		++k;
		print("Case #%d: ", k);
		problem(k);
		print("\n");
	}
	fclose(fin);
	fclose(fout);
}

void init()
{
}

void problem(int nCase)
{
	int N;
	int points[200];
	int i,j=0;
	int sum=0,sum2;
	fscanf_s(fin, "%d", &N);
	for (i=0;i<N;++i)
	{
		fscanf_s(fin, "%d", &points[i]);
		sum += points[i];
	}
	sum2 = 0;
	long double needed = sum*2.0/N;
	for (i=0;i<N;++i)
	{
		if (points[i]<needed)
		{
			sum2 += points[i];
			++j;
		}
	}
	needed = (long double)(sum+sum2)/j;
	for (i=0;i<N;++i)
	{
		long double enough = (needed-points[i])*100.0/(sum);
		print("%.6f ", max(enough,0));
	}
}