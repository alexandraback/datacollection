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
	int A,B;
	int m,n,i,e,s=0;
	fscanf_s(fin, "%d %d\n", &A, &B);
	m=A;
	e=1;
	while(m>9)
	{
		e*=10;
		m/=10;
	}
	for (m=A;m<B;++m)
	{
		n=(m%10)*e+(m/10);
		while (n!=m)
		{
			if (m<n && n<=B)
				++s;
			n=(n%10)*e+(n/10);
		}
	}
	print("%d", s);
}