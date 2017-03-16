#include <vector>
#include <algorithm>
#include <fstream>

#define ULL unsigned long long int

using namespace std;

ifstream ein;
FILE * aus;
int TestCase;

ULL gcd(ULL a, ULL b)
{
	ULL t;
	if (a==0)
		return b;
	if (b==0)
		return a;
	if (a>=b)
	{
		t = a / b;
		return gcd(a-t*b, b);
	}
	return gcd(b,a);
}

void start()
{
	printf("%d\n", TestCase);
	int result = 1;
	// read test case

	ULL P, Q;
	char c;
	ein >> P;
	ein >> c;
	ein >> Q;

	ULL g;
	g = gcd(P,Q);
	P = P/g;
	Q = Q/g;

	while (Q>1)
	{
		if ((Q & 1) != 0)
		{
			result = -1;
			break;
		}
		Q = Q / 2;
		if (P>=1)
		{
			P = P / 2;
		}
		else
			result++;
	}
	// output result
    if (result >= 0)
		fprintf(aus, "Case #%d: %d\n", TestCase, result);     // %llu , %ll
	else
		fprintf(aus, "Case #%d: impossible\n", TestCase);
}

void main()
{
	int NumTestCases;	
	ein.open("A-small-attempt0.in");
	aus = fopen("ausgabe.txt","w");
	
	ein >> NumTestCases;
	for (TestCase = 1; TestCase <= NumTestCases; TestCase++)
		start();

	fclose(aus);
	ein.close();
}
