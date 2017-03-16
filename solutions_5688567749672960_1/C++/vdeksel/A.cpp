#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

ifstream ein;
ofstream aus;
int TestCase;

long long int turnlist[14] = {           
	      21,  
		 201,  
	    1101, 
 	   11001,
 	  101001,
     1010001,
    10010001,
   100100001,
     1000100001,
    10001000001,
   100001000001,
  1000010000001,
 10000010000001,
100000100000001};


long long int r(long long n)
{
	if (n<21)
		return n;
	
	int d;
	int e = 1;
	int m = 1;
	for (d=0;d<17;d++)
	{
		if (e>n)
			break;
		e *= 10;
		if (d % 2 == 0)
			m *= 10;
	}
	if (n % m == 0)
	{
		return (r(n-1) + 1);
	}
	if (n % m != 1)
	{
		return ((n % m)- 1) + r(n - (n% m) + 1);
	}
		// turn around
			long long int u = n;
			long long int v = 0;
			while (u > 0 )
			{
				v = 10*v + (u % 10);
				u = u/10;
			}
	if (v >= n)
	{
		return (1 + r(n-1));
	}
	return (1+r(v));
}

void start()
{
	printf("%d\n", TestCase);
  long long int result;
	// read test case
  long long int N;
  ein >> N;
	
  result = r(N);
  // output result
  aus << "Case #" << TestCase << ": " << result << endl;
}

void main()
{
	int NumTestCases;	
	ein.open("A-large.in");
	aus.open("ausgabe.txt");
	
	
	ein >> NumTestCases;
	for (TestCase = 1; TestCase <= NumTestCases; TestCase++)
		start();

	aus.close();
	ein.close();
}
