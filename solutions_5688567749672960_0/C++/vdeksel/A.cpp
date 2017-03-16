#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream ein;
FILE * aus;
int TestCase;

#define MAXN  1000000

int r[MAXN+1];

void start()
{
	printf("%d\n", TestCase);
  int result;
	// read test case
  int N;
  ein >> N;
	result = r[N];

	// output result
    fprintf(aus, "Case #%d: %d\n", TestCase, result);     // %llu , %ll
}

void main()
{
	int NumTestCases;	
	ein.open("A-small-attempt0.in");
	aus = fopen("ausgabe.txt","w");
	
	r[1] = 1;
	for (int n=2;n<=MAXN;n++)
	{
		if (n % 10 != 0)
		{
			int u = n;
			int v = 0;
			while (u>0)
			{
				v = (10*v) + (u % 10);
				u = u/10;
			}
			if (v < n)
			{
				r[n] = min(r[n-1], r[v]) + 1;
			}
			else
			{
				r[n]= r[n-1] +1;
			}
		}
		else
		{
			r[n] = r[n-1] + 1;
		}
	}

	ein >> NumTestCases;
	for (TestCase = 1; TestCase <= NumTestCases; TestCase++)
		start();

	fclose(aus);
	ein.close();
}
