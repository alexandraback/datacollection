#include "stdio.h"
#include "stdlib.h"
#include "memory.h"
#include "string.h"
#include "math.h"

FILE *fin, *fout;

#define INPUT_FILE_NAME "C-small-attempt0"
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
	int N,i,j,k;
	int points[200];
	int sum1, sum2;
	fscanf_s(fin, "%d", &N);
	for (i=0;i<N;++i)
	{
		fscanf_s(fin, "%d", &points[i]);
	}

	int subs1=0,subs2;
	for (subs1=1;subs1<(1<<20);++subs1)
	{
		sum1 = 0;
		k = subs1;
		j=0;
		while (k>0)
		{
			if (k&1)
				sum1 += points[j];
			++j;
			k>>=1;
		}
		for (subs2=1;subs2<(1<<20);++subs2)
		{
			if ((subs1 & subs2)==0)
			{
				sum2 = 0;
				k = subs2;
				j=0;
				while (k>0)
				{
					if (k&1)
						sum2 += points[j];
					++j;
					k>>=1;
				}
				if (sum1==sum2)
				{
					print("\n");
					j=0;
					while (subs1>0)
					{
						if (subs1&1)
						{
							print("%d ", points[j]);
						}
						++j;
						subs1>>=1;
					}
					print("\n");
					j=0;
					while (subs2>0)
					{
						if (subs2&1)
						{
							print("%d ", points[j]);
						}
						++j;
						subs2>>=1;
					}
					return;
				}
			}
		}
	}
	print("Impossible");
}