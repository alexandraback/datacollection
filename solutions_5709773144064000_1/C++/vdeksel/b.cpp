#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream ein;
FILE * aus;
int TestCase;

void start()
{
	
	// read test case
	double c,f,x;
	ein >> c >> f >> x;

	double s;

	int k;
	k = (int)(x/c - 2/f);
	if (k<0)
		k=0;

	s = x/(2+k*f);
	for (int m=0;m<k;m++)
		s += c/(2+(double) m*f);

	// minimize c/2 + c/(2+f) + c/(2+2f) + ... + c/(2+(k-1)f) + x/(2+kf)


	// [c - xf / (2+(k+1)f)] / (2+kf)

	// kleinstes k mit (k+1) > x/c -2 /f 
	
	// output result
    fprintf(aus, "Case #%d: %.7f\n", TestCase, s);
}

void main()
{
	int NumTestCases;	
	ein.open("b-large.in");
	aus = fopen("ausgabe.txt","w");
	
	ein >> NumTestCases;
	for (TestCase = 1; TestCase <= NumTestCases; TestCase++)
		start();

	fclose(aus);
	ein.close();
}
